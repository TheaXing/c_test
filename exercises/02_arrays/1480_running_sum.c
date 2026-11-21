#include <stdio.h>
#include <stdlib.h>

/*
 * 力扣 1480：一维数组的动态和
 * https://leetcode.cn/problems/running-sum-of-1d-array/
 *
 * 给你一个长度为 numsSize 的整数数组 nums（1 <= numsSize <= 1000）。
 * 「动态和」的计算公式为：
 *   runningSum[i] = nums[0] + nums[1] + ... + nums[i]
 * 请用 malloc 构建并返回一个长度为 numsSize 的新数组，保存每个位置的动态和。
 *
 * 例如：
 *   - nums = {1, 2, 3, 4}     -> 返回 {1, 3, 6, 10}
 *   - nums = {3, 1, 2, 10, 1} -> 返回 {3, 4, 6, 16, 17}
 *
 * malloc 学习提示：
 *   1. 用 malloc 申请与 nums 等长的新数组：
 *        int *ans = (int *)malloc(sizeof(int) * numsSize);
 *   2. 设置返回长度：
 *        *returnSize = numsSize;
 *
 * 写完函数并返回新数组后，直接运行 main 验证。
 */
int *runningSum(int *nums, int numsSize, int *returnSize) {
    // 在这里写代码
}

static void printArray(const int *nums, int size) {
    if (nums == NULL) {
        printf("NULL");
        return;
    }
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%s%d", i == 0 ? "" : ", ", nums[i]);
    }
    printf("}");
}

int main(void) {
    struct {
        int nums[8];
        int size;
        int expected[8];
    } cases[] = {
        {{1, 2, 3, 4}, 4, {1, 3, 6, 10}},
        {{1, 1, 1, 1, 1}, 5, {1, 2, 3, 4, 5}},
        {{3, 1, 2, 10, 1}, 5, {3, 4, 6, 16, 17}},
        {{7}, 1, {7}},
        {{0, 0, 0, 0}, 4, {0, 0, 0, 0}},
        {{-1, -2, -3, -4}, 4, {-1, -3, -6, -10}},
        {{5, -5, 5, -5, 5}, 5, {5, 0, 5, 0, 5}},
        {{10, -3, 2, -8, 4, 1}, 6, {10, 7, 9, 1, 5, 6}},
        {{100000, 200000, 300000}, 3, {100000, 300000, 600000}},
        {{2, 4, 6, 8, 10, 12, 14, 16}, 8, {2, 6, 12, 20, 30, 42, 56, 72}},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int expectedSize = cases[i].size;
        int actualSize = -1;
        int *actual = runningSum(cases[i].nums, cases[i].size, &actualSize);

        int passed = actual != NULL && actualSize == expectedSize;
        if (passed) {
            for (int j = 0; j < expectedSize; j++) {
                if (actual[j] != cases[i].expected[j]) {
                    passed = 0;
                    break;
                }
            }
        }

        printf("[%s] case %d, size: expected = %d, actual = %d | expected = ",
               passed ? "PASS" : "FAIL", i + 1, expectedSize, actualSize);
        printArray(cases[i].expected, expectedSize);
        printf(", actual = ");
        printArray(actual, actualSize > 0 ? actualSize : 0);
        printf("\n");

        free(actual);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
