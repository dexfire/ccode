#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define log2n(n) ((int)log2f(n))

int N, K;

int minmal_normal_steps(int sum) {
    int steped = 0;
    int steps = 0;
    while (steped < sum) {
        steps++;
        steped += log2n(sum - steped);
    }
    return steps;
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