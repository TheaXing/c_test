#include <stdio.h>

/*
 * 水仙花数
 *
 * 给定一个三位正整数 n（100 <= n <= 999）。
 * 若它等于百位、十位和个位数字的立方和，返回 1，否则返回 0。
 *
 * 例如 153 = 1 * 1 * 1 + 5 * 5 * 5 + 3 * 3 * 3，所以输入 153 返回 1。
 *
 * 写完函数后，main 会检查 100 到 999，并打印找出的水仙花数。
 */
int isArmstrongNumber(int n) {
    // 在这里写代码
    int a = n % 10;
    int b = (n / 10) % 10;
    int c = n / 100;
    printf("%d,%d %d\n", a ,b ,c);
    if ((a * a * a + b * b * b + c * c * c )== n) {
        return 1;
    }else {
        return 0;
    }
    return 0;
}

int main(void) {
    int failures = 0;
    printf("Found:");
    for (int n = 100; n <= 999; n++) {
        int expected = n == 153 || n == 370 || n == 371 || n == 407;
        int actual = isArmstrongNumber(n);
        if (actual == 1) {
            printf(" %d", n);
        }
        if (actual != expected) {
            failures++;
        }
    }
    printf("\n");
    puts("Expected: 153 370 371 407");
    printf("%d/900 passed.\n", 900 - failures);
    return failures == 0 ? 0 : 1;
}
