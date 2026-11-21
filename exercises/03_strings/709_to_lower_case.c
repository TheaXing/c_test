#include <stdio.h>
#include <string.h>

/*
 * 力扣 709：转换成小写字母
 * https://leetcode.cn/problems/to-lower-case/
 *
 * 给你一个字符串 s，将该字符串中的大写字母转换成相同的小写字母，
 * 其他字符保持不变，原地修改后返回 s。
 *
 * 例如：
 *   - s = "Hello"  -> "hello"
 *   - s = "here"   -> "here"
 *   - s = "LOVELY" -> "lovely"
 *
 * 基础知识：
 *   - C 语言字符串是以空字符 '\0' 结尾的字符数组。
 *   - 在 ASCII 编码中，'A'~'Z' 与 'a'~'z' 各自按字母顺序连续排列。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
char *toLowerCase(char *s) {
    // 在这里写代码
}

int main(void) {
    const struct {
        const char *input;
        const char *expected;
    } cases[] = {
        {"Hello", "hello"},
        {"here", "here"},
        {"LOVELY", "lovely"},
        {"", ""},
        {"A", "a"},
        {"z", "z"},
        {"Hello, World! 2026", "hello, world! 2026"},
        {"AZaz", "azaz"},
        {"12345!@#", "12345!@#"},
        {"C_Language_TEST_09", "c_language_test_09"},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        char buf[64];
        strcpy(buf, cases[i].input);

        char *actual = toLowerCase(buf);
        int passed = actual != NULL && strcmp(actual, cases[i].expected) == 0;
        printf("[%s] \"%s\" -> expected = \"%s\", actual = \"%s\"\n",
               passed ? "PASS" : "FAIL",
               cases[i].input,
               cases[i].expected,
               actual != NULL ? actual : "NULL");
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
