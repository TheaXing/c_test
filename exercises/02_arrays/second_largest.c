#include <stdio.h>

/*
 * 找数组第二大元素
 *
 * 给定一个整数数组 nums（通过指针传入）及其长度 numsSize（2 <= numsSize <= 100）。
 * 数组中的所有整数「互不相同」（可能包含负数和 0），请返回其中第二大的整数。
 *
 * 例如：
 *   - {1, 5, 3, 9, 2}      -> 最大是 9，第二大是 5，返回 5
 *   - {-5, -2, -9, -1, -7} -> 最大是 -1，第二大是 -2，返回 -2
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
int findSecondLargest(int *nums, int numsSize) {
    // 在这里写代码
}

int main(void) {
    struct {
        int nums[10];
        int size;
        int expected;
    } cases[] = {
        {{1, 5, 3, 9, 2}, 5, 5},
        {{10, 20}, 2, 10},
        {{20, 10}, 2, 10},
        {{9, 3, 5, 1, 7}, 5, 7},
        {{1, 2, 3, 4, 5}, 5, 4},
        {{5, 4, 3, 2, 1}, 5, 4},
        {{-5, -2, -9, -1, -7}, 5, -2},
        {{-10, 0, -3, -20}, 4, -3},
        {{100, -50, 200, 199, 0, 50}, 6, 199},
        {{42, 17, 99, 88, 63, 105, 74, 104, 12, 55}, 10, 104},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actual = findSecondLargest(cases[i].nums, cases[i].size);
        int passed = actual == cases[i].expected;
        printf("[%s] case %d, expected = %d, actual = %d\n",
               passed ? "PASS" : "FAIL", i + 1, cases[i].expected, actual);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
