#include <stdio.h>

/*
 * 指针交换与三数排序
 *
 * 请实现以下两个函数：
 *
 * 1. void swap(int *a, int *b)
 *    交换指针 a 和 b 所指向的两个整数的值。
 *    （注意：a 和 b 可能指向同一个变量。）
 *
 * 2. void sortThree(int *a, int *b, int *c)
 *    将指针 a、b、c 所指向的三个整数按从小到大的顺序重新排列，
 *    使调用结束后满足 *a <= *b <= *c。
 *
 * 例如：
 *   - x = 3, y = 5，调用 swap(&x, &y) 后变为 x = 5, y = 3
 *   - x = 3, y = 1, z = 2，调用 sortThree(&x, &y, &z) 后变为 x = 1, y = 2, z = 3
 *
 * 基础知识：
 *   - C 语言函数参数按值传递；想在函数内部修改外部变量，需要传入变量的地址（指针）。
 *   - 运算符 & 用于取变量地址，运算符 * 用于解引用指针以读取或修改其指向的值。
 *
 * 写完两个函数后，直接运行 main 验证。
 */
void swap(int *a, int *b) {
    // 在这里写代码
}

void sortThree(int *a, int *b, int *c) {
    // 在这里写代码
}


/*
 * ========== 以下代码无需关注 ==========
 */
int main(void) {
    int failures = 0;
    const int total = 10;

    /* Case 1: swap 常规交换 */
    {
        int x1 = 3, y1 = 5;
        int x2 = -10, y2 = 0;
        swap(&x1, &y1);
        swap(&x2, &y2);
        int passed = x1 == 5 && y1 == 3 && x2 == 0 && y2 == -10;
        printf("[%s] case 1 (swap basic): (%d, %d), (%d, %d)\n",
               passed ? "PASS" : "FAIL", x1, y1, x2, y2);
        if (!passed) {
            failures++;
        }
    }

    /* Case 2: swap 两个指针指向同一个变量 */
    {
        int x = 42;
        swap(&x, &x);
        int passed = x == 42;
        printf("[%s] case 2 (swap self): expected = 42, actual = %d\n",
               passed ? "PASS" : "FAIL", x);
        if (!passed) {
            failures++;
        }
    }

    /* Cases 3~10: sortThree 覆盖 3 个数的全部 6 种排列 + 重复值 + 全负数 */
    const struct {
        int a, b, c;
        int ea, eb, ec;
    } sortCases[] = {
        {1, 2, 3, 1, 2, 3},
        {1, 3, 2, 1, 2, 3},
        {2, 1, 3, 1, 2, 3},
        {2, 3, 1, 1, 2, 3},
        {3, 1, 2, 1, 2, 3},
        {3, 2, 1, 1, 2, 3},
        {5, -2, 5, -2, 5, 5},
        {-10, -30, -20, -30, -20, -10},
    };

    int sortCount = sizeof(sortCases) / sizeof(sortCases[0]);
    for (int i = 0; i < sortCount; i++) {
        int a = sortCases[i].a;
        int b = sortCases[i].b;
        int c = sortCases[i].c;
        sortThree(&a, &b, &c);
        int passed = a == sortCases[i].ea && b == sortCases[i].eb && c == sortCases[i].ec;
        printf("[%s] case %d (sortThree %d,%d,%d): expected = (%d, %d, %d), actual = (%d, %d, %d)\n",
               passed ? "PASS" : "FAIL", i + 3,
               sortCases[i].a, sortCases[i].b, sortCases[i].c,
               sortCases[i].ea, sortCases[i].eb, sortCases[i].ec,
               a, b, c);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", total - failures, total);
    return failures == 0 ? 0 : 1;
}
