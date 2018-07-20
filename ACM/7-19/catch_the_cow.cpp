#include <cmath>
#include <stdio.h>
#include <stdlib.h>

#define log2n(n) ((int)log2f(n))

int N, K;

int minmal_normal_steps(int sum) {
    // 总共要走sum步
    //
    int ex = sum;
    while (ex > 0) {
    }
    log2n(sum);
    int steped +=

        int a = log2n(sum);
    while (a < sum) {
        int b = a - 1;
        while (pow(2, b) > sum - 1)
            b--;
        a += b;
    }
    int lenth = 1;
    int steps = 1;
    int steps_count = 1;
    while (lenth < sum) {
        lenth += (steps *= 2);
        steps_count++;
    }
    return steps_count;
}

int main() {
    int steps;
    while (scanf("%d%d", &N, &K) != EOF) {
        steps = log2n(K / N);
        steps += minmal_normal_steps(K - N * pow(2, steps));
    }

    printf("%d  %d\n", minal_normal_steps(64), log2n(100));
    system("pause");
}