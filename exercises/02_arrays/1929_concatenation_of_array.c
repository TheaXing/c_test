#include <stdio.h>
#include <stdlib.h>

/*
 * 力扣 1929：数组串联
 * https://leetcode.cn/problems/concatenation-of-array/
 *
 * 给你一个长度为 numsSize 的整数数组 nums（1 <= numsSize <= 1000）。
 * 请你构建一个长度为 2 * numsSize 的新数组 ans，满足：
 *   - ans[i] == nums[i]
 *   - ans[i + numsSize] == nums[i]
 * 也就是把 nums 拼接两遍。
 *
 * 例如：
 *   - nums = {1, 2, 1}    -> 返回 {1, 2, 1, 1, 2, 1}，*returnSize = 6
 *   - nums = {1, 3, 2, 1} -> 返回 {1, 3, 2, 1, 1, 3, 2, 1}，*returnSize = 8
 *
 * malloc 学习提示：
 *   1. 不能在函数里写 int ans[2000]; return ans;（局部数组在函数结束时就会被销毁）。
 *   2. 要用 malloc 在堆上申请内存：
 *        int *ans = (int *)malloc(sizeof(int) * numsSize * 2);
 *   3. 别忘了把返回数组的长度写进 *returnSize：
 *        *returnSize = numsSize * 2;
 *   4. 本题由调用方（main）负责 free(ans) 释放你申请的内存，与力扣评测规则一致。
 *
 * 写完函数并返回新数组后，直接运行 main 验证。
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize) {
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
        int nums[6];
        int size;
        int expected[12];
    } cases[] = {
        {{1, 2, 1}, 3, {1, 2, 1, 1, 2, 1}},
        {{1, 3, 2, 1}, 4, {1, 3, 2, 1, 1, 3, 2, 1}},
        {{5}, 1, {5, 5}},
        {{10, 20}, 2, {10, 20, 10, 20}},
        {{7, 7, 7}, 3, {7, 7, 7, 7, 7, 7}},
        {{1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}},
        {{5, 4, 3, 2, 1}, 5, {5, 4, 3, 2, 1, 5, 4, 3, 2, 1}},
        {{1000, 1, 1000}, 3, {1000, 1, 1000, 1000, 1, 1000}},
        {{9, 8, 7, 6, 5, 4}, 6, {9, 8, 7, 6, 5, 4, 9, 8, 7, 6, 5, 4}},
        {{42, 99, 1, 500, 250, 750}, 6, {42, 99, 1, 500, 250, 750, 42, 99, 1, 500, 250, 750}},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int expectedSize = cases[i].size * 2;
        int actualSize = -1;
        int *actual = getConcatenation(cases[i].nums, cases[i].size, &actualSize);

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
