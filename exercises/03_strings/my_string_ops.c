#include <stdio.h>

/*
 * 手写 my_strlen 和 my_strcpy
 *
 * 不借助 <string.h> 中的库函数，自己实现以下两个经典字符串函数：
 *   1. my_strlen(const char *s)：
 *      返回字符串 s 的长度（不包含末尾的 '\0'）。
 *   2. my_strcpy(char *dest, const char *src)：
 *      把 src 的内容（包含末尾的 '\0'）复制到 dest，并返回 dest。
 *      题目保证 dest 空间足够，且 dest 与 src 内存区域不重叠。
 *
 * 例如 src = "hello"：
 *   - my_strlen(src) 返回 5
 *   - my_strcpy(dest, src) 后，dest 中的字符串变为 "hello"，且返回 dest
 *
 * 基础知识：
 *   - C 语言字符串是以空字符 '\0' 标记结束的字符数组。
 *   - 字符串长度不计算末尾的 '\0'，但复制字符串时必须把 '\0' 也复制过去。
 *
 * 写完两个函数后，直接运行 main 验证。
 */
int my_strlen(const char *s) {
    // 在这里写代码
}

char *my_strcpy(char *dest, const char *src) {
    // 在这里写代码
}

static int stringsEqual(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return a[i] == b[i];
}

int main(void) {
    const struct {
        const char *input;
        int expectedLen;
    } cases[] = {
        {"", 0},
        {"a", 1},
        {"hello", 5},
        {"Hello, World!", 13},
        {"   ", 3},
        {"1234567890", 10},
        {"C99 standard", 12},
        {"a\tb", 3},
        {"!@#$%^&*()", 10},
        {"Practice makes perfect.", 23},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actualLen = my_strlen(cases[i].input);

        char dest[64];
        for (int j = 0; j < 63; j++) {
            dest[j] = '#';
        }
        dest[63] = '\0';

        char *ret = my_strcpy(dest, cases[i].input);
        int lenOk = actualLen == cases[i].expectedLen;
        int copyOk = ret == dest && stringsEqual(dest, cases[i].input);
        int passed = lenOk && copyOk;

        printf("[%s] \"%s\" | len: expected = %d, actual = %d | copy: %s\n",
               passed ? "PASS" : "FAIL",
               cases[i].input,
               cases[i].expectedLen, actualLen,
               copyOk ? "OK" : "FAIL");
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
