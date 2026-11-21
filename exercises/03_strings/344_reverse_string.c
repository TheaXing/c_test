#include <stdio.h>
#include <string.h>

/*
 * 力扣 344：反转字符串
 * https://leetcode.cn/problems/reverse-string/
 *
 * 编写一个函数，其作用是将输入的字符数组 s 原地反转过来，sSize 为数组长度。
 * 不要给另外的数组分配额外的空间，必须原地修改输入数组。
 *
 * 例如：
 *   - s = {'h', 'e', 'l', 'l', 'o'}, sSize = 5 -> {'o', 'l', 'l', 'e', 'h'}
 *   - s = {'H', 'a', 'n', 'n', 'a', 'h'}, sSize = 6 -> {'h', 'a', 'n', 'n', 'a', 'H'}
 *
 * 基础知识：
 *   - 本题输入是长度为 sSize 的字符数组，不保证末尾带有 '\0'，长度以 sSize 为准。
 *
 * 写完函数后，直接运行 main 验证。
 */
void reverseString(char *s, int sSize) {
    // 在这里写代码
}

int main(void) {
    const struct {
        const char *input;
        int size;
        const char *expected;
    } cases[] = {
        {"hello", 5, "olleh"},
        {"Hannah", 6, "hannaH"},
        {"a", 1, "a"},
        {"ab", 2, "ba"},
        {"abcd", 4, "dcba"},
        {"abcba", 5, "abcba"},
        {"123456", 6, "654321"},
        {"A b C", 5, "C b A"},
        {"!@#$", 4, "$#@!"},
        {"C_Language", 10, "egaugnaL_C"},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        char buf[32];
        memcpy(buf, cases[i].input, (size_t)cases[i].size);

        reverseString(buf, cases[i].size);
        int passed = memcmp(buf, cases[i].expected, (size_t)cases[i].size) == 0;
        printf("[%s] \"%.*s\" -> expected = \"%.*s\", actual = \"%.*s\"\n",
               passed ? "PASS" : "FAIL",
               cases[i].size, cases[i].input,
               cases[i].size, cases[i].expected,
               cases[i].size, buf);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
