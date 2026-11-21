#include <stdio.h>

/*
 * 统计字符串里的字母、数字、空格个数
 *
 * 给定一个字符串 s，统计其中：
 *   - 英文字母（'A'~'Z'、'a'~'z'）的个数，存入 *letters
 *   - 数字字符（'0'~'9'）的个数，存入 *digits
 *   - 空格字符（' '）的个数，存入 *spaces
 * 其他字符（如标点符号）不计入这三类。
 *
 * 例如 s = "Hello World 123"：
 *   - letters = 10, digits = 3, spaces = 2
 *
 * 基础知识：
 *   - C 语言字符串是以空字符 '\0' 结尾的字符数组。
 *   - 可以通过指针参数（如 *letters = ...）把多个结果传回调用方。
 *
 * 写完函数后，直接运行 main 验证。
 */
void countChars(const char *s, int *letters, int *digits, int *spaces) {
    // 在这里写代码
}

int main(void) {
    const struct {
        const char *input;
        int expectedLetters;
        int expectedDigits;
        int expectedSpaces;
    } cases[] = {
        {"Hello World 123", 10, 3, 2},
        {"", 0, 0, 0},
        {"abcXYZ", 6, 0, 0},
        {"0123456789", 0, 10, 0},
        {"   ", 0, 0, 3},
        {"C99 is fun!", 6, 2, 2},
        {"a1 b2 c3!", 3, 3, 2},
        {"!@#$%^&*()", 0, 0, 0},
        {" 2026 Year of C ", 7, 4, 5},
        {"Aa0 Bb1 Cc2 Zz9", 8, 4, 3},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int letters = -1, digits = -1, spaces = -1;
        countChars(cases[i].input, &letters, &digits, &spaces);

        int passed = letters == cases[i].expectedLetters &&
                     digits == cases[i].expectedDigits &&
                     spaces == cases[i].expectedSpaces;
        printf("[%s] \"%s\" | expected = (%d, %d, %d), actual = (%d, %d, %d)\n",
               passed ? "PASS" : "FAIL",
               cases[i].input,
               cases[i].expectedLetters, cases[i].expectedDigits, cases[i].expectedSpaces,
               letters, digits, spaces);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
