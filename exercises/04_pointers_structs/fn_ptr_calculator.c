#include <stdio.h>

/*
 * 函数指针计算器
 *
 * 下方使用 typedef 定义了一个函数指针类型 BinaryOp：
 *   typedef int (*BinaryOp)(int, int);
 * 它表示“指向接收两个 int 参数、返回 int 的函数的指针”。
 *
 * 请实现以下 6 个函数：
 *
 * 1. int opAdd(int a, int b)   返回 a + b
 * 2. int opSub(int a, int b)   返回 a - b
 * 3. int opMul(int a, int b)   返回 a * b
 * 4. int opDiv(int a, int b)   返回 a / b（整数除法，调用方保证 b != 0）
 *
 * 5. BinaryOp selectOp(char symbol)
 *    根据运算符字符返回对应的运算函数指针：
 *      - '+' -> opAdd
 *      - '-' -> opSub
 *      - '*' -> opMul
 *      - '/' -> opDiv
 *      - 其他字符 -> NULL
 *
 * 6. int calculate(int a, int b, BinaryOp op)
 *    调用函数指针 op 对 a 和 b 执行运算并返回结果；
 *    若 op 为 NULL，返回 0。
 *
 * 基础知识：
 *   - 在 C 语言中，函数名可以隐式转换为指向该函数的指针。
 *   - 拿到函数指针 op 后，可以直接像普通函数一样通过 op(a, b)（或 (*op)(a, b)）调用它。
 *
 * 写完 6 个函数后，直接运行 main 验证。
 */
typedef int (*BinaryOp)(int, int);

int opAdd(int a, int b) {
    // 在这里写代码
}

int opSub(int a, int b) {
    // 在这里写代码
}

int opMul(int a, int b) {
    // 在这里写代码
}

int opDiv(int a, int b) {
    // 在这里写代码
}

BinaryOp selectOp(char symbol) {
    // 在这里写代码
}

int calculate(int a, int b, BinaryOp op) {
    // 在这里写代码
}


/*
 * ========== 以下代码无需关注 ==========
 */
static int customMax(int a, int b) {
    return a > b ? a : b;
}

static int customMod(int a, int b) {
    return a % b;
}

int main(void) {
    int failures = 0;
    const int total = 10;

    /* Cases 1~5: 四则运算路由与计算 */
    const struct {
        char symbol;
        int a;
        int b;
        int expected;
        BinaryOp expectedFn;
    } opCases[] = {
        {'+', 12, 8, 20, opAdd},
        {'-', 12, 8, 4, opSub},
        {'*', 6, -7, -42, opMul},
        {'/', 20, 4, 5, opDiv},
        {'/', -7, 2, -3, opDiv},
    };

    for (int i = 0; i < 5; i++) {
        BinaryOp fn = selectOp(opCases[i].symbol);
        int actual = calculate(opCases[i].a, opCases[i].b, fn);
        int passed = fn == opCases[i].expectedFn && actual == opCases[i].expected;
        printf("[%s] case %d (%d %c %d): expected = %d, actual = %d\n",
               passed ? "PASS" : "FAIL",
               i + 1, opCases[i].a, opCases[i].symbol, opCases[i].b,
               opCases[i].expected, actual);
        if (!passed) {
            failures++;
        }
    }

    /* Case 6~7: 不支持的运算符返回 NULL */
    {
        BinaryOp fn = selectOp('%');
        int passed = fn == NULL;
        printf("[%s] case 6 (selectOp '%%' -> NULL)\n", passed ? "PASS" : "FAIL");
        if (!passed) {
            failures++;
        }
    }
    {
        BinaryOp fn = selectOp('?');
        int passed = fn == NULL;
        printf("[%s] case 7 (selectOp '?' -> NULL)\n", passed ? "PASS" : "FAIL");
        if (!passed) {
            failures++;
        }
    }

    /* Case 8: 传入 NULL 函数指针时返回 0 */
    {
        int actual = calculate(10, 20, NULL);
        int passed = actual == 0;
        printf("[%s] case 8 (calculate with NULL): expected = 0, actual = %d\n",
               passed ? "PASS" : "FAIL", actual);
        if (!passed) {
            failures++;
        }
    }

    /* Case 9~10: 传入调用方自定义的任意回调函数 */
    {
        int actual = calculate(15, 27, customMax);
        int passed = actual == 27;
        printf("[%s] case 9 (custom callback max(15, 27)): expected = 27, actual = %d\n",
               passed ? "PASS" : "FAIL", actual);
        if (!passed) {
            failures++;
        }
    }
    {
        int actual = calculate(17, 5, customMod);
        int passed = actual == 2;
        printf("[%s] case 10 (custom callback mod(17, 5)): expected = 2, actual = %d\n",
               passed ? "PASS" : "FAIL", actual);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", total - failures, total);
    return failures == 0 ? 0 : 1;
}
