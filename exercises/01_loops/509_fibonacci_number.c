#include <stdio.h>

/*
 * 力扣 509：斐波那契数
 * https://leetcode.cn/problems/fibonacci-number/
 *
 * F(0) = 0，F(1) = 1。之后每一项都等于前两项的和。
 * 给定 n（0 <= n <= 30），返回 F(n)。
 * 例如数列从 0、1、1、2、3、5 开始，输入 5 返回 5。
 *
 * 可以用 for 循环逐项计算。写完函数后，直接运行 main 验证。
 */
int fib(int n) {
    // 在这里写代码
}

int main(void) {
    const struct {
        int input;
        int expected;
    } cases[] = {
        {0, 0},
        {1, 1},
        {2, 1},
        {5, 5},
        {10, 55},
        {30, 832040},
    };

    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        int actual = fib(cases[i].input);
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
