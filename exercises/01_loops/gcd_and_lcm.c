#include <stdio.h>

/*
 * 最大公约数与最小公倍数
 *
 * 给定两个正整数 a 和 b（1 <= a, b <= 10000）：
 *   1. gcd(a, b)：返回 a 和 b 的最大公约数（能同时整除 a 和 b 的最大正整数）。
 *   2. lcm(a, b)：返回 a 和 b 的最小公倍数（能同时被 a 和 b 整除的最小正整数）。
 *
 * 例如 a = 12, b = 18：
 *   - 最大公约数为 6
 *   - 最小公倍数为 36
 *
 * 提示：
 *   1. 求最大公约数推荐用「辗转相除法」：不断用 b 和 a % b 替换 (a, b)，
 *      直到 b == 0，此时 a 就是最大公约数。
 *
 * 写完两个函数后，直接运行 main 验证。
 */
int gcd(int a, int b) {
    // 在这里写代码
}

int lcm(int a, int b) {
    // 在这里写代码
}

int main(void) {
    const struct {
        int a;
        int b;
        int expectedGcd;
        int expectedLcm;
    } cases[] = {
        {12, 18, 6, 36},
        {18, 12, 6, 36},
        {7, 13, 1, 91},
        {5, 5, 5, 5},
        {1, 99, 1, 99},
        {6, 24, 6, 24},
        {48, 18, 6, 144},
        {100, 75, 25, 300},
        {21, 14, 7, 42},
        {1071, 462, 21, 23562},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actualGcd = gcd(cases[i].a, cases[i].b);
        int actualLcm = lcm(cases[i].a, cases[i].b);
        int passed = actualGcd == cases[i].expectedGcd && actualLcm == cases[i].expectedLcm;
        printf("[%s] a = %d, b = %d | gcd: expected = %d, actual = %d | lcm: expected = %d, actual = %d\n",
               passed ? "PASS" : "FAIL",
               cases[i].a, cases[i].b,
               cases[i].expectedGcd, actualGcd,
               cases[i].expectedLcm, actualLcm);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
