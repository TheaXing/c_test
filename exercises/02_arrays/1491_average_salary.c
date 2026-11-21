#include <stdio.h>

/*
 * 力扣 1491：去掉最低工资和最高工资后的工资平均值
 * https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
 *
 * salary 是一个整数数组，salarySize 是它的长度。
 * 数组中有 3 到 100 个互不相同的工资，每个工资在 1000 到 1000000 之间。
 * 去掉最高和最低各一个，返回剩余工资的平均值。结果可以有小数。
 *
 * 例如 {1000, 2000, 3001, 5000} 去掉 1000 和 5000 后，
 * 剩下 2000 和 3001，平均值为 2500.5。
 *
 * 写完函数并返回结果后，直接运行 main 验证。
 */
double average(int salary[], int salarySize) {
    // 在这里写代码
}

int main(void) {
    struct {
        int salary[10];
        int size;
        double expected;
    } cases[] = {
        {{4000, 3000, 1000, 2000}, 4, 2500.0},
        {{1000, 2000, 3000}, 3, 2000.0},
        {{6000, 5000, 4000, 3000, 2000, 1000}, 6, 3500.0},
        {{1000, 2000, 3001, 5000}, 4, 2500.5},
        {{8000, 9000, 2000, 3000, 6000, 1000}, 6, 4750.0},
        {{1000, 1000000, 500000}, 3, 500000.0},
        {{1000000, 999999, 999998, 999997, 999996}, 5, 999998.0},
        {{1000, 2000, 3000, 4001, 5000}, 5, 9001.0 / 3},
        {{7000, 1200, 9500, 3400, 5600, 8100, 2300}, 7, 5280.0},
        {{2500, 7500, 4000, 6000, 1500, 9000, 3200, 8800, 5100, 4400}, 10, 5187.5},
    };

    const double tolerance = 0.00001;
    int failures = 0;
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < count; i++) {
        double actual = average(cases[i].salary, cases[i].size);
        double expected = cases[i].expected;
        int passed = actual >= expected - tolerance && actual <= expected + tolerance;
        printf("[%s] case %d, expected = %.5f, actual = %.5f\n",
               passed ? "PASS" : "FAIL", i + 1, expected, actual);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", count - failures, count);
    return failures == 0 ? 0 : 1;
}
