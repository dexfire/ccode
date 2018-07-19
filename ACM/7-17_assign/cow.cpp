#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

// 空间位置 x[]
const int MAX = 100005;
int X[MAX + 1]; // 内存占用 400KB
int N, C;

// put cows test
int pc(int x) {
    int idx = 1;
    int dx;
    for (int i = 1; i < C; i++) {
        dx = 0;
        // printf("COW %d\n", i);
        while (idx < N && dx < x) {
            idx++;
            dx += X[idx] - X[idx - 1];
            // printf("dx= %d\t", dx);
        }
        // printf("\n\t @ %d  dx= %d  x=%d\n", X[idx], dx, x);
        if (idx >= N) {              // N用完
            if (i < C - 1 || dx < x) // 牛没放完,dx<x保证最后一只空间足够
                return 0;
            else if (dx >= x) // 牛放完了 只有i=C-1的可能
                return 1;
        }
    }
    // 牛放完了，N没有用完
    // printf("return with idx = %d\n", idx);
    return 1;
}

void solve() {
    int lb = 0, rb = MAX * 3, mid;
    for (int i = 0; i < 64; i++) {
        mid = (double)(rb + lb) / 2.0 + 0.5;
        // printf("min %d mid %d max %d\n", lb, mid, rb);
        if (pc(mid)) {
            lb = mid;
        } else {
            rb = mid;
        }
    }
    // printf("%d\n", (lb + rb) / 2);
}

int main() {
    X[0] = 0;
    while (scanf("%d%d", &N, &C) != EOF) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &X[i]);
        std::sort(X, X + N);
        solve();
    }
    // system("pause");
    return 0;
}