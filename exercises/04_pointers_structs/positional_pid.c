#include <stdio.h>

/*
 * 位置式 PID 控制器（结构体版）
 *
 * 请基于下方给定的 PID 结构体，实现初始化函数和单步计算函数：
 *
 * 1. void pidInit(PID *pid, double kp, double ki, double kd)
 *    设置比例系数 kp、积分系数 ki、微分系数 kd，
 *    并将内部历史状态 integral 和 prev_error 初始化为 0.0。
 *
 * 2. double pidUpdate(PID *pid, double target, double current, double dt)
 *    给定目标值 target、当前测量值 current 和采样时间间隔 dt（dt > 0），
 *    按离散位置式 PID 公式计算本次控制输出 u 并更新内部状态：
 *      - 本次误差：     e_k = target - current
 *      - 误差积分累计： I_k = I_{k-1} + e_k * dt      （初始 I_0 = 0）
 *      - 误差变化率：   D_k = (e_k - e_{k-1}) / dt    （初始 e_0 = 0）
 *      - 控制输出：     u_k = kp * e_k + ki * I_k + kd * D_k
 *    更新结构体中保存的 integral 与 prev_error 后，返回 u_k。
 *
 * 基础知识：
 *   - 结构体指针访问成员使用箭头运算符，例如 pid->kp 等价于 (*pid).kp。
 *   - 将历史状态保存在结构体内部，可以让多个 PID 控制器实例各自独立运行、互不干扰。
 *
 * 写完两个函数后，直接运行 main 验证（包含 9 组精确数值测试 + 1 组温控闭环仿真）。
 */
typedef struct {
    double kp;
    double ki;
    double kd;
    double integral;
    double prev_error;
} PID;

void pidInit(PID *pid, double kp, double ki, double kd) {
    // 在这里写代码
}

double pidUpdate(PID *pid, double target, double current, double dt) {
    // 在这里写代码
}


/*
 * ========== 以下代码无需关注 ==========
 */
static int nearlyEqual(double a, double b) {
    double diff = a - b;
    return diff >= -1e-6 && diff <= 1e-6;
}

static int runSequenceCase(int caseNo, const char *name,
                           double kp, double ki, double kd,
                           double target, double dt,
                           const double *currents, const double *expected, int steps) {
    PID pid = {0, 0, 0, 999.0, -888.0};
    pidInit(&pid, kp, ki, kd);

    int passed = 1;
    double lastActual = 0.0;
    double lastExpected = 0.0;
    int failStep = -1;

    for (int i = 0; i < steps; i++) {
        double actual = pidUpdate(&pid, target, currents[i], dt);
        if (!nearlyEqual(actual, expected[i])) {
            passed = 0;
            failStep = i + 1;
            lastActual = actual;
            lastExpected = expected[i];
            break;
        }
        lastActual = actual;
        lastExpected = expected[i];
    }

    if (passed) {
        printf("[PASS] case %d (%s), steps = %d, last = %.4f\n",
               caseNo, name, steps, lastActual);
    } else {
        printf("[FAIL] case %d (%s) at step %d, expected = %.6f, actual = %.6f\n",
               caseNo, name, failStep, lastExpected, lastActual);
    }
    return passed;
}

int main(void) {
    int failures = 0;
    const int total = 10;

    /* Case 1: pidInit 正确设置系数并清零历史状态 */
    {
        PID pid = {-1.0, -2.0, -3.0, 999.0, -888.0};
        pidInit(&pid, 1.5, 0.5, 0.2);
        int passed = nearlyEqual(pid.kp, 1.5) &&
                     nearlyEqual(pid.ki, 0.5) &&
                     nearlyEqual(pid.kd, 0.2) &&
                     nearlyEqual(pid.integral, 0.0) &&
                     nearlyEqual(pid.prev_error, 0.0);
        printf("[%s] case 1 (pidInit reset), kp=%.2f ki=%.2f kd=%.2f I=%.2f prev_e=%.2f\n",
               passed ? "PASS" : "FAIL",
               pid.kp, pid.ki, pid.kd, pid.integral, pid.prev_error);
        if (!passed) {
            failures++;
        }
    }

    /* Case 2: 纯 P 控制 */
    {
        const double currents[] = {4.0};
        const double expected[] = {12.0};
        if (!runSequenceCase(2, "P only", 2.0, 0.0, 0.0, 10.0, 0.1, currents, expected, 1)) {
            failures++;
        }
    }

    /* Case 3: 纯 I 控制（多步积分累计） */
    {
        const double currents[] = {6.0, 8.0, 9.0};
        const double expected[] = {1.0, 1.5, 1.75};
        if (!runSequenceCase(3, "I only", 0.0, 0.5, 0.0, 10.0, 0.5, currents, expected, 3)) {
            failures++;
        }
    }

    /* Case 4: 纯 D 控制（误差上升、下降、不变） */
    {
        const double currents[] = {4.0, 7.0, 7.0};
        const double expected[] = {2.4, -1.2, 0.0};
        if (!runSequenceCase(4, "D only", 0.0, 0.0, 0.2, 10.0, 0.5, currents, expected, 3)) {
            failures++;
        }
    }

    /* Case 5: 完整 PID 单步 */
    {
        const double currents[] = {6.0};
        const double expected[] = {6.4};
        if (!runSequenceCase(5, "PID single step", 1.0, 0.5, 0.1, 10.0, 0.2, currents, expected, 1)) {
            failures++;
        }
    }

    /* Case 6: 完整 PID 连续 3 步 */
    {
        const double currents[] = {2.0, 6.0, 9.0};
        const double expected[] = {19.6, 10.2, 4.65};
        if (!runSequenceCase(6, "PID 3 steps", 2.0, 0.5, 0.1, 10.0, 0.5, currents, expected, 3)) {
            failures++;
        }
    }

    /* Case 7: 超调与负误差 */
    {
        const double currents[] = {8.0, 12.0, 11.0};
        const double expected[] = {4.8, -4.6, -1.6};
        if (!runSequenceCase(7, "overshoot & negative error", 1.5, 1.0, 0.2, 10.0, 0.5, currents, expected, 3)) {
            failures++;
        }
    }

    /* Case 8: 误差归零后依靠历史积分维持输出 */
    {
        const double currents[] = {3.0, 5.0, 5.0};
        const double expected[] = {7.0, -1.0, 1.0};
        if (!runSequenceCase(8, "zero error steady hold", 2.0, 1.0, 0.5, 5.0, 0.5, currents, expected, 3)) {
            failures++;
        }
    }

    /* Case 9: 两个独立 PID 实例交替调用互不干扰 */
    {
        PID pidA, pidB;
        pidInit(&pidA, 1.0, 1.0, 0.0);
        pidInit(&pidB, 2.0, 0.0, 0.5);

        double a1 = pidUpdate(&pidA, 10.0, 6.0, 1.0);
        double b1 = pidUpdate(&pidB, 5.0, 2.0, 1.0);
        double a2 = pidUpdate(&pidA, 10.0, 8.0, 1.0);
        double b2 = pidUpdate(&pidB, 5.0, 4.0, 1.0);

        int passed = nearlyEqual(a1, 8.0) &&
                     nearlyEqual(b1, 7.5) &&
                     nearlyEqual(a2, 8.0) &&
                     nearlyEqual(b2, 1.0);
        printf("[%s] case 9 (two independent PIDs), A=(%.2f, %.2f) B=(%.2f, %.2f)\n",
               passed ? "PASS" : "FAIL", a1, a2, b1, b2);
        if (!passed) {
            failures++;
        }
    }

    /* Case 10: 恒温水箱闭环仿真（20°C 加热并稳定在 80°C） */
    {
        PID pid;
        pidInit(&pid, 1.5, 0.8, 0.05);

        const double ambient = 20.0;
        const double target = 80.0;
        const double dt = 0.1;
        double temp = ambient;

        for (int step = 0; step < 200; step++) {
            double power = pidUpdate(&pid, target, temp, dt);
            temp += (0.5 * power - 0.1 * (temp - ambient)) * dt;
        }

        double diff = temp - target;
        int passed = diff >= -0.1 && diff <= 0.1;
        printf("[%s] case 10 (temperature closed-loop), target = %.2f, final = %.4f\n",
               passed ? "PASS" : "FAIL", target, temp);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", total - failures, total);
    return failures == 0 ? 0 : 1;
}
