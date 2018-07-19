#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

// �ռ�λ�� x[]
const int MAX = 100005;
int X[MAX + 1]; // �ڴ�ռ�� 400KB
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
        if (idx >= N) {              // N����
            if (i < C - 1 || dx < x) // ţû����,dx<x��֤���һֻ�ռ��㹻
                return 0;
            else if (dx >= x) // ţ������ ֻ��i=C-1�Ŀ���
                return 1;
        }
    }
    // ţ�����ˣ�Nû������
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