#include <stdio.h>

/*
 * 力扣 1281：整数的各位积和之差
 * https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 *
 * 给定正整数 n（1 <= n <= 100000），分别求它各位数字的乘积和总和，
 * 然后返回「乘积 - 总和」。结果可以为负数。
 *
 * 例如 n = 234，乘积为 2 * 3 * 4 = 24，总和为 2 + 3 + 4 = 9，
 * 所以返回 15。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
int subtractProductAndSum(int n) {
    // 在这里写代码
}

int main(void) {
    const struct {
        int input;
        int expected;
    } cases[] = {
        {234, 15},
        {4421, 21},
        {105, -6},
        {7, 0},
        {100000, -1},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actual = subtractProductAndSum(cases[i].input);
        int passed = actual == cases[i].expected;
        printf("[%s] n = %d, expected = %d, actual = %d\n",
               passed ? "PASS" : "FAIL", cases[i].input, cases[i].expected, actual);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
