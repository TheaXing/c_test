#include <stdio.h>

/*
 * 判断闰年
 *
 * 给定一个正整数年份 year（1 <= year <= 10000）。
 * 如果是闰年，返回 1；否则返回 0。
 *
 * 闰年规则（满足以下任意一条即为闰年）：
 *   1. 能被 4 整除，但不能被 100 整除；
 *   2. 能被 400 整除。
 *
 * 例如：
 *   - 2024 能被 4 整除且不能被 100 整除，是闰年，返回 1；
 *   - 1900 能被 100 整除但不能被 400 整除，不是闰年，返回 0；
 *   - 2000 能被 400 整除，是闰年，返回 1。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
int isLeapYear(int year) {
    // 在这里写代码
}

int main(void) {
    const struct {
        int year;
        int expected;
    } cases[] = {
        {2000, 1},
        {1900, 0},
        {2024, 1},
        {2023, 0},
        {2020, 1},
        {2100, 0},
        {2400, 1},
        {1996, 1},
        {1999, 0},
        {4, 1},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actual = isLeapYear(cases[i].year);
        int passed = actual == cases[i].expected;
        printf("[%s] year = %d, expected = %d, actual = %d\n",
               passed ? "PASS" : "FAIL", cases[i].year, cases[i].expected, actual);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
