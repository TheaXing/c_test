#include <stdio.h>
#include <stdlib.h>

/*
 * 手写单链表（基础增删查）
 *
 * 请基于下方给定的链表节点结构体 Node，实现单链表的 5 个基础操作：
 *
 * 1. Node *listPushFront(Node *head, int val)
 *    用 malloc 创建值为 val 的新节点并插入链表头部，返回新的头节点指针。
 *
 * 2. Node *listPushBack(Node *head, int val)
 *    用 malloc 创建值为 val 的新节点并插入链表尾部，返回新的头节点指针。
 *
 * 3. int listLength(const Node *head)
 *    返回链表中的节点总数（空链表返回 0）。
 *
 * 4. Node *listFind(Node *head, int target)
 *    从头到尾查找第一个 val == target 的节点并返回其指针；若未找到返回 NULL。
 *
 * 5. Node *listRemoveFirst(Node *head, int target)
 *    删除链表中第一个 val == target 的节点并用 free 释放该节点，返回新的头节点指针；
 *    若链表为空或未找到目标值，保持链表不变并返回原 head。
 *
 * 基础知识：
 *   - 结构体内部可以包含指向自身类型的指针（如 struct Node *next），用来把节点串成链表。
 *   - 链表末尾节点的 next 为 NULL；空链表用 head == NULL 表示。
 *   - 使用 malloc 分配节点内存（需引入 <stdlib.h>），不再使用时用 free 释放。
 *
 * 写完 5 个函数后，直接运行 main 验证。
 */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *listPushFront(Node *head, int val) {
    // 在这里写代码
}

Node *listPushBack(Node *head, int val) {
    // 在这里写代码
}

int listLength(const Node *head) {
    // 在这里写代码
}

Node *listFind(Node *head, int target) {
    // 在这里写代码
}

Node *listRemoveFirst(Node *head, int target) {
    // 在这里写代码
}


/*
 * ========== 以下代码无需关注 ==========
 */
static void freeList(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

static int listMatches(const Node *head, const int *expected, int expectedLen) {
    if (listLength(head) != expectedLen) {
        return 0;
    }
    const Node *curr = head;
    for (int i = 0; i < expectedLen; i++) {
        if (curr == NULL || curr->val != expected[i]) {
            return 0;
        }
        curr = curr->next;
    }
    return curr == NULL;
}

static void printList(const Node *head) {
    printf("[");
    const Node *curr = head;
    int first = 1;
    int limit = 32;
    while (curr != NULL && limit-- > 0) {
        printf("%s%d", first ? "" : " -> ", curr->val);
        first = 0;
        curr = curr->next;
    }
    if (curr != NULL) {
        printf(" -> ...");
    }
    printf("]");
}

int main(void) {
    int failures = 0;
    const int total = 10;

    /* Case 1: 空链表上的全部安全操作 */
    {
        Node *head = NULL;
        int len = listLength(head);
        Node *found = listFind(head, 10);
        Node *afterRemove = listRemoveFirst(head, 10);
        int passed = len == 0 && found == NULL && afterRemove == NULL;
        printf("[%s] case 1 (empty list ops)\n", passed ? "PASS" : "FAIL");
        if (!passed) {
            failures++;
        }
    }

    /* Case 2: 连续头插 */
    {
        Node *head = NULL;
        head = listPushFront(head, 1);
        head = listPushFront(head, 2);
        head = listPushFront(head, 3);
        const int expected[] = {3, 2, 1};
        int passed = listMatches(head, expected, 3);
        printf("[%s] case 2 (pushFront 1,2,3): actual = ", passed ? "PASS" : "FAIL");
        printList(head);
        printf("\n");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 3: 连续尾插（从空链表开始） */
    {
        Node *head = NULL;
        head = listPushBack(head, 10);
        head = listPushBack(head, 20);
        head = listPushBack(head, 30);
        const int expected[] = {10, 20, 30};
        int passed = listMatches(head, expected, 3);
        printf("[%s] case 3 (pushBack 10,20,30): actual = ", passed ? "PASS" : "FAIL");
        printList(head);
        printf("\n");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 4: 头插与尾插混合 */
    {
        Node *head = NULL;
        head = listPushBack(head, 2);
        head = listPushFront(head, 1);
        head = listPushBack(head, 3);
        head = listPushFront(head, 0);
        const int expected[] = {0, 1, 2, 3};
        int passed = listMatches(head, expected, 4);
        printf("[%s] case 4 (mixed push): actual = ", passed ? "PASS" : "FAIL");
        printList(head);
        printf("\n");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 5: 查找头、中、尾元素 */
    {
        Node *head = NULL;
        head = listPushBack(head, 10);
        head = listPushBack(head, 20);
        head = listPushBack(head, 30);
        Node *p1 = listFind(head, 10);
        Node *p2 = listFind(head, 20);
        Node *p3 = listFind(head, 30);
        int passed = head != NULL && head->next != NULL && head->next->next != NULL &&
                     p1 == head &&
                     p2 == head->next && p2->val == 20 &&
                     p3 == head->next->next && p3->val == 30;
        printf("[%s] case 5 (find head/mid/tail)\n", passed ? "PASS" : "FAIL");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 6: 查找不存在的元素与重复元素（返回第一个） */
    {
        Node *head = NULL;
        head = listPushBack(head, 5);
        head = listPushBack(head, 2);
        head = listPushBack(head, 5);
        Node *missing = listFind(head, 99);
        Node *firstFive = listFind(head, 5);
        int passed = missing == NULL && firstFive == head;
        printf("[%s] case 6 (find missing & duplicate)\n", passed ? "PASS" : "FAIL");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 7: 删除头节点 */
    {
        Node *head = NULL;
        head = listPushBack(head, 1);
        head = listPushBack(head, 2);
        head = listPushBack(head, 3);
        head = listRemoveFirst(head, 1);
        const int expected[] = {2, 3};
        int passed = listMatches(head, expected, 2);
        printf("[%s] case 7 (remove head): actual = ", passed ? "PASS" : "FAIL");
        printList(head);
        printf("\n");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 8: 删除中间节点 */
    {
        Node *head = NULL;
        head = listPushBack(head, 1);
        head = listPushBack(head, 2);
        head = listPushBack(head, 3);
        head = listPushBack(head, 4);
        head = listRemoveFirst(head, 3);
        const int expected[] = {1, 2, 4};
        int passed = listMatches(head, expected, 3);
        printf("[%s] case 8 (remove middle): actual = ", passed ? "PASS" : "FAIL");
        printList(head);
        printf("\n");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    /* Case 9: 删除尾节点与唯一节点 */
    {
        Node *head = NULL;
        head = listPushBack(head, 1);
        head = listPushBack(head, 2);
        head = listPushBack(head, 3);
        head = listRemoveFirst(head, 3);
        const int expected1[] = {1, 2};
        int ok1 = listMatches(head, expected1, 2);
        freeList(head);

        Node *single = listPushBack(NULL, 9);
        single = listRemoveFirst(single, 9);
        int ok2 = single == NULL && listLength(single) == 0;
        freeList(single);

        int passed = ok1 && ok2;
        printf("[%s] case 9 (remove tail & single node)\n", passed ? "PASS" : "FAIL");
        if (!passed) {
            failures++;
        }
    }

    /* Case 10: 删除重复元素（只删第一个）与不存在的值 */
    {
        Node *head = NULL;
        head = listPushBack(head, 4);
        head = listPushBack(head, 7);
        head = listPushBack(head, 4);
        head = listPushBack(head, 9);
        head = listRemoveFirst(head, 4);
        head = listRemoveFirst(head, 99);
        const int expected[] = {7, 4, 9};
        int passed = listMatches(head, expected, 3);
        printf("[%s] case 10 (remove duplicate & missing): actual = ", passed ? "PASS" : "FAIL");
        printList(head);
        printf("\n");
        freeList(head);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", total - failures, total);
    return failures == 0 ? 0 : 1;
}
