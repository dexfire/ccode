#include <algorithm>
#include <iostream>
using namespace std;
int N, M, K;

void merge(double a[], int s, int m, int e, double tmp[]) {
    int pb = 0;
    int i = s, j = m + 1;
    while (i <= m && j <= e) {
        if (a[i] < a[j])
            tmp[pb++] = a[i++];
        if (a[i] > a[j])
            tmp[pb++] = a[j++];
    }
    while (i <= m)
        tmp[pb++] = a[i++];
    while (j <= e)
        tmp[pb++] = a[j++];
    for (int i = 0; i < e - s + 1; ++i)
        a[s + i] = tmp[i];
}
void mergesort(double a[], int s, int e, double tmp[]) {
    if (s < e) {
        int m = s + (e - s) / 2;
        mergesort(a, s, m, tmp);
        mergesort(a, m + 1, e, tmp);
        merge(a, s, m, e, tmp);
    }
}
int main() {
    freopen("t_shirt.txt", "r", stdin);
    while (cin >> N >> M >> K) {
        double a[M];
        double a1[M];
        double ac[M];
        int b[K];
        fill(a, a + M, 0.0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a1[j];
                a[j] = a[j] + a1[j];
            }
        }
        for (int i = 0; i < M; i++)
            ac[i] = a[i];
        mergesort(a, 0, M - 1, a1);
        int idx = 0;
        for (int i = M - 1; i > M - K - 1; i--) {
            for (int j = 0; j < M; j++) {
                if (a[i] == ac[j]) {
                    ac[j] = 0; //清空数值，防止重复查找
                    b[idx++] = j;
                }
            }
        }
        sort(b, b + K);
        // for (int t = 0; t < K; t++)
        //     for (int i = M - 1; i >= 0; i--)
        //         for (int j = 0; j < M; j++) {
        //             printf("t %d i %d j %d a[i] %lf ac[j]%lf\n", t, i, j,
        //             a[i],
        //                    ac[j]);
        //             if (a[i] == ac[j]) {
        //                 j = j + 1;
        //                 b[t] = j;
        //             }
        //         }
        for (int i = K - 1; i > 0; i--)
            cout << b[i] + 1 << " ";
        cout << b[0] + 1 << endl;
    }
    return 0;
}
