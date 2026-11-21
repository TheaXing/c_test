#include <stdio.h>

/*
 * 通用数组回调（applyToArray 与 countIf）
 *
 * 下方使用 typedef 定义了两种函数指针类型：
 *   typedef int (*TransformFn)(int);   // 接收一个 int，返回变换后的 int
 *   typedef int (*PredicateFn)(int);   // 接收一个 int，返回非 0 表示满足条件，0 表示不满足
 *
 * 请实现以下两个通用数组处理函数：
 *
 * 1. void applyToArray(int *nums, int numsSize, TransformFn fn)
 *    对数组 nums 中的每个元素调用 fn，并将返回值原地写回对应位置。
 *    若 fn 为 NULL 或 numsSize <= 0，不做任何修改。
 *
 * 2. int countIf(const int *nums, int numsSize, PredicateFn pred)
 *    统计数组 nums 中满足 pred(nums[i]) != 0 的元素个数并返回。
 *    若 pred 为 NULL 或 numsSize <= 0，返回 0。
 *
 * 例如：
 *   - 若 doubleVal(x) 返回 x * 2，对 {1, 2, 3} 调用 applyToArray 后数组变为 {2, 4, 6}
 *   - 若 isEven(x) 在 x 为偶数时返回 1，对 {1, 2, 3, 4} 调用 countIf 返回 2
 *
 * 基础知识：
 *   - 通过把函数指针作为参数传入，同一个遍历函数可以配合不同的回调函数完成多种操作。
 *   - 调用函数指针前应检查它是否为 NULL。
 *
 * 写完两个函数后，直接运行 main 验证。
 */
typedef int (*TransformFn)(int);
typedef int (*PredicateFn)(int);

void applyToArray(int *nums, int numsSize, TransformFn fn) {
    // 在这里写代码
}

int countIf(const int *nums, int numsSize, PredicateFn pred) {
    // 在这里写代码
}


/*
 * ========== 以下代码无需关注 ==========
 */
static int doubleVal(int x) {
    return x * 2;
}

static int squareVal(int x) {
    return x * x;
}

static int absVal(int x) {
    return x < 0 ? -x : x;
}

static int clampNonNegative(int x) {
    return x < 0 ? 0 : x;
}

static int isEven(int x) {
    return x % 2 == 0;
}

static int isPositive(int x) {
    return x > 0;
}

static int isGreaterThanTen(int x) {
    return x > 10;
}

static int arraysEqual(const int *a, const int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

static int runApplyCase(int caseNo, const char *name,
                        const int *input, const int *expected, int size,
                        TransformFn fn) {
    int actual[8];
    for (int i = 0; i < size; i++) {
        actual[i] = input[i];
    }
    applyToArray(actual, size, fn);
    int passed = arraysEqual(actual, expected, size);
    printf("[%s] case %d (applyToArray: %s)\n", passed ? "PASS" : "FAIL", caseNo, name);
    return passed;
}

int main(void) {
    int failures = 0;
    const int total = 10;

    /* Case 1: 翻倍 */
    {
        const int in[] = {1, 2, 3, 4, 5};
        const int exp[] = {2, 4, 6, 8, 10};
        if (!runApplyCase(1, "doubleVal", in, exp, 5, doubleVal)) {
            failures++;
        }
    }

    /* Case 2: 平方 */
    {
        const int in[] = {-3, -1, 0, 2, 4};
        const int exp[] = {9, 1, 0, 4, 16};
        if (!runApplyCase(2, "squareVal", in, exp, 5, squareVal)) {
            failures++;
        }
    }

    /* Case 3: 取绝对值 */
    {
        const int in[] = {-5, 3, -12, 0, 8};
        const int exp[] = {5, 3, 12, 0, 8};
        if (!runApplyCase(3, "absVal", in, exp, 5, absVal)) {
            failures++;
        }
    }

    /* Case 4: 负数归零 */
    {
        const int in[] = {-4, 7, -1, 0, 5};
        const int exp[] = {0, 7, 0, 0, 5};
        if (!runApplyCase(4, "clampNonNegative", in, exp, 5, clampNonNegative)) {
            failures++;
        }
    }

    /* Case 5: applyToArray 传入 NULL 回调与空长度 */
    {
        int nums[] = {1, 2, 3};
        const int expected[] = {1, 2, 3};
        applyToArray(nums, 3, NULL);
        applyToArray(nums, 0, doubleVal);
        int passed = arraysEqual(nums, expected, 3);
        printf("[%s] case 5 (applyToArray: NULL & size 0)\n", passed ? "PASS" : "FAIL");
        if (!passed) {
            failures++;
        }
    }

    /* Case 6: 统计偶数个数 */
    {
        const int nums[] = {1, 2, 3, 4, 5, 6};
        int actual = countIf(nums, 6, isEven);
        int passed = actual == 3;
        printf("[%s] case 6 (countIf isEven): expected = 3, actual = %d\n",
               passed ? "PASS" : "FAIL", actual);
        if (!passed) {
            failures++;
        }
    }

    /* Case 7: 统计正数个数 */
    {
        const int nums[] = {-3, 0, 5, -1, 8, 2};
        int actual = countIf(nums, 6, isPositive);
        int passed = actual == 3;
        printf("[%s] case 7 (countIf isPositive): expected = 3, actual = %d\n",
               passed ? "PASS" : "FAIL", actual);
        if (!passed) {
            failures++;
        }
    }

    /* Case 8: 统计大于 10 的元素个数 */
    {
        const int nums[] = {10, 11, 5, 25, 100, 9};
        int actual = countIf(nums, 6, isGreaterThanTen);
        int passed = actual == 3;
        printf("[%s] case 8 (countIf > 10): expected = 3, actual = %d\n",
               passed ? "PASS" : "FAIL", actual);
        if (!passed) {
            failures++;
        }
    }

    /* Case 9: 全部不满足与全部满足 */
    {
        const int odds[] = {1, 3, 5, 7};
        const int pos[] = {1, 2, 3};
        int c1 = countIf(odds, 4, isEven);
        int c2 = countIf(pos, 3, isPositive);
        int passed = c1 == 0 && c2 == 3;
        printf("[%s] case 9 (countIf none & all): expected = (0, 3), actual = (%d, %d)\n",
               passed ? "PASS" : "FAIL", c1, c2);
        if (!passed) {
            failures++;
        }
    }

    /* Case 10: countIf 传入 NULL 回调与空长度 */
    {
        const int nums[] = {2, 4, 6};
        int c1 = countIf(nums, 3, NULL);
        int c2 = countIf(nums, 0, isEven);
        int passed = c1 == 0 && c2 == 0;
        printf("[%s] case 10 (countIf NULL & size 0): expected = (0, 0), actual = (%d, %d)\n",
               passed ? "PASS" : "FAIL", c1, c2);
        if (!passed) {
            failures++;
        }
    }

    printf("%d/%d passed.\n", total - failures, total);
    return failures == 0 ? 0 : 1;
}
