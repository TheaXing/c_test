#include <stdio.h>

/*
 * 查找数组元素并返回指针
 *
 * 给定整数数组 nums、长度 numsSize（0 <= numsSize <= 100）和目标值 target。
 * 从前往后查找第一个值等于 target 的元素：
 *   - 若找到，返回指向该元素的指针；
 *   - 若未找到（或数组长度为 0），返回 NULL。
 *
 * 例如 nums = {10, 20, 30, 40}：
 *   - target = 30 -> 返回 &nums[2]（解引用得到 30）
 *   - target = 25 -> 返回 NULL
 *
 * 基础知识：
 *   - 空指针常量 NULL 表示指针不指向任何有效地址。
 *   - 对于数组指针 nums，表达式 nums + i 与 &nums[i] 表示同一个元素的地址。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
int *findElement(int *nums, int numsSize, int target) {
    // 在这里写代码
}


/*
 * ========== 以下代码无需关注 ==========
 */
int main(void) {
    struct {
        int nums[8];
        int size;
        int target;
        int expectedIndex; /* -1 表示期望返回 NULL */
    } cases[] = {
        {{10, 20, 30, 40}, 4, 30, 2},
        {{10, 20, 30, 40}, 4, 10, 0},
        {{10, 20, 30, 40}, 4, 40, 3},
        {{10, 20, 30, 40}, 4, 25, -1},
        {{5, 3, 5, 8, 5}, 5, 5, 0},
        {{1, 4, 2, 4, 9}, 5, 4, 1},
        {{42}, 1, 42, 0},
        {{42}, 1, 0, -1},
        {{-5, 0, 7, -3, 12}, 5, -3, 3},
        {{1, 2, 3}, 0, 1, -1},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int *expectedPtr = cases[i].expectedIndex >= 0
                               ? &cases[i].nums[cases[i].expectedIndex]
                               : NULL;
        int *actualPtr = findElement(cases[i].nums, cases[i].size, cases[i].target);
        int passed = actualPtr == expectedPtr;

        if (expectedPtr == NULL) {
            printf("[%s] case %d, target = %d, expected = NULL, actual = %s\n",
                   passed ? "PASS" : "FAIL",
                   i + 1, cases[i].target,
                   actualPtr == NULL ? "NULL" : "non-NULL");
        } else {
            int actualIndex = actualPtr != NULL ? (int)(actualPtr - cases[i].nums) : -1;
            printf("[%s] case %d, target = %d, expected index = %d, actual index = %d\n",
                   passed ? "PASS" : "FAIL",
                   i + 1, cases[i].target,
                   cases[i].expectedIndex, actualIndex);
        }

        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
