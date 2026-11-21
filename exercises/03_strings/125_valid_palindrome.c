#include <stdbool.h>
#include <stdio.h>

/*
 * 力扣 125：验证回文串
 * https://leetcode.cn/problems/valid-palindrome/
 *
 * 如果在将所有大写字符转换为小写字符、并移除所有非字母和非数字字符之后，
 * 短语正着读和反着读都一样，则可以认为该短语是一个回文串。
 * 字母和数字都属于字母数字字符；移除后为空串也视为回文串。
 *
 * 给你一个字符串 s，如果它是回文串，返回 true；否则，返回 false。
 *
 * 例如：
 *   - s = "A man, a plan, a canal: Panama" -> true（处理后为 "amanaplanacanalpanama"）
 *   - s = "race a car"                     -> false（处理后为 "raceacar"）
 *   - s = " "                              -> true（处理后为空串 ""）
 *
 * 基础知识：
 *   - C 语言字符串是以空字符 '\0' 结尾的字符数组。
 *   - 引入 <stdbool.h> 后可使用 bool、true、false。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
bool isPalindrome(char *s) {
    // 在这里写代码
}

int main(void) {
    const struct {
        const char *input;
        bool expected;
    } cases[] = {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {" ", true},
        {"", true},
        {"a", true},
        {"0P", false},
        {"12321", true},
        {"No 'x' in Nixon", true},
        {"ab_a", true},
        {"Hello, olleH!", true},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        char buf[64];
        int len = 0;
        while (cases[i].input[len] != '\0') {
            buf[len] = cases[i].input[len];
            len++;
        }
        buf[len] = '\0';

        bool actual = isPalindrome(buf);
        int passed = actual == cases[i].expected;
        printf("[%s] \"%s\" -> expected = %s, actual = %s\n",
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
