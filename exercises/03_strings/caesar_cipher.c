#include <stdio.h>
#include <string.h>

/*
 * 凯撒加密
 *
 * 给定一个字符串 s 和一个非负整数位移量 shift（0 <= shift <= 1000）。
 * 请原地对 s 进行凯撒加密：
 *   - 每个英文字母在字母表中向后移动 shift 位（超过 'z' 或 'Z' 时循环回到 'a' 或 'A'）；
 *   - 大写字母加密后仍为大写，小写字母加密后仍为小写；
 *   - 非英文字母（数字、空格、标点等）保持不变。
 *
 * 例如：
 *   - s = "abc", shift = 3           -> "def"
 *   - s = "xyz", shift = 3           -> "abc"
 *   - s = "Hello, World!", shift = 3 -> "Khoor, Zruog!"
 *
 * 基础知识：
 *   - C 语言字符串是以空字符 '\0' 结尾的字符数组。
 *   - 在 ASCII 编码中，26 个大写字母 'A'~'Z' 和 26 个小写字母 'a'~'z' 各自连续排列。
 *
 * 写完函数后，直接运行 main 验证。
 */
void caesarCipher(char *s, int shift) {
    // 在这里写代码
}

int main(void) {
    const struct {
        const char *input;
        int shift;
        const char *expected;
    } cases[] = {
        {"abc", 3, "def"},
        {"xyz", 3, "abc"},
        {"XYZ", 3, "ABC"},
        {"Hello, World!", 3, "Khoor, Zruog!"},
        {"Attack at 12:00!", 5, "Fyyfhp fy 12:00!"},
        {"NoChange", 0, "NoChange"},
        {"FullCycle", 26, "FullCycle"},
        {"AzBy", 27, "BaCz"},
        {"", 10, ""},
        {"C99_Test_Zz", 13, "P99_Grfg_Mm"},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        char buf[64];
        strcpy(buf, cases[i].input);

        caesarCipher(buf, cases[i].shift);
        int passed = strcmp(buf, cases[i].expected) == 0;
        printf("[%s] \"%s\" (shift=%d) -> expected = \"%s\", actual = \"%s\"\n",
               passed ? "PASS" : "FAIL",
               cases[i].input, cases[i].shift, cases[i].expected, buf);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
