#include <stdio.h>

/*
 * 数组逆序存放
 *
 * 给定一个整数数组 nums（通过指针传入）及其长度 numsSize（1 <= numsSize <= 100）。
 * 请将数组中的元素「原地」前后颠倒存放，不需要返回新数组。
 *
 * 例如：
 *   - {1, 2, 3, 4, 5} 逆序后变为 {5, 4, 3, 2, 1}
 *   - {1, 2, 3, 4}    逆序后变为 {4, 3, 2, 1}
 *
 * 提示：
 *   1. 在 C 语言中，数组参数写成 int *nums 后，依然可以像数组一样用 nums[i] 访问元素。
 *
 * 写完函数后，直接运行 main 验证。
 */
void reverseArray(int *nums, int numsSize) {
    // 在这里写代码
}

static void printArray(const int *nums, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%s%d", i == 0 ? "" : ", ", nums[i]);
    }
    printf("}");
}

int main(void) {
    struct {
        int input[10];
        int expected[10];
        int size;
    } cases[] = {
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, 5},
        {{1, 2, 3, 4}, {4, 3, 2, 1}, 4},
        {{42}, {42}, 1},
        {{10, 20}, {20, 10}, 2},
        {{5, 5, 5, 5}, {5, 5, 5, 5}, 4},
        {{-3, -1, 0, 2, 8}, {8, 2, 0, -1, -3}, 5},
        {{1, 2, 3, 2, 1}, {1, 2, 3, 2, 1}, 5},
        {{9, 7, 5, 3, 1, 0}, {0, 1, 3, 5, 7, 9}, 6},
        {{100, -100, 200, -200, 300, -300, 400}, {400, -300, 300, -200, 200, -100, 100}, 7},
        {{3, 1, 4, 1, 5, 9, 2, 6, 5, 3}, {3, 5, 6, 2, 9, 5, 1, 4, 1, 3}, 10},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actual[10];
        for (int j = 0; j < cases[i].size; j++) {
            actual[j] = cases[i].input[j];
        }

        reverseArray(actual, cases[i].size);

        int passed = 1;
        for (int j = 0; j < cases[i].size; j++) {
            if (actual[j] != cases[i].expected[j]) {
                passed = 0;
                break;
            }
        }

        printf("[%s] case %d, expected = ", passed ? "PASS" : "FAIL", i + 1);
        printArray(cases[i].expected, cases[i].size);
        printf(", actual = ");
        printArray(actual, cases[i].size);
        printf("\n");

        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
