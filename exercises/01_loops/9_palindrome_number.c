#include <stdbool.h>
#include <stdio.h>

/*
 * 力扣 9：回文数
 * https://leetcode.cn/problems/palindrome-number/
 *
 * 给你一个整数 x，如果 x 是一个回文整数，返回 true；否则，返回 false。
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 例如：
 *   - x = 121  -> true
 *   - x = -121 -> false（从右向左读为 121-，不是回文数）
 *   - x = 10   -> false（从右向左读为 01，不是回文数）
 *
 * 提示：
 *   1. 在 C 语言中引入 <stdbool.h> 后，可直接返回 true / false（也可以返回 1 / 0）。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
bool isPalindrome(int x) {
    // 在这里写代码
}

int main(void) {
    const struct {
        int input;
        bool expected;
    } cases[] = {
        {121, true},
        {-121, false},
        {10, false},
        {0, true},
        {7, true},
        {1221, true},
        {12321, true},
        {123, false},
        {1001, true},
        {2147447412, true},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        bool actual = isPalindrome(cases[i].input);
        int passed = actual == cases[i].expected;
        printf("[%s] x = %d, expected = %s, actual = %s\n",
               passed ? "PASS" : "FAIL",
               cases[i].input,
               cases[i].expected ? "true" : "false",
               actual ? "true" : "false");
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
