#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int n, k, t = 0;
int a[105], b[105];
void merge(int a[], int s, int m, int e, int tmp[]) {
    int pb = 0;
    int p1 = s, p2 = m + 1;
    while (p1 <= m && p2 <= e) {
        if (a[p1] <= a[p2])
            tmp[pb++] = a[p1++];
        else
            tmp[pb++] = a[p2++], t = t + m + 1 - p1;
    }
    while (p1 <= m)
        tmp[pb++] = a[p1++];
    while (p2 <= e)
        tmp[pb++] = a[p2++];
    for (int i = 0; i < e - s + 1; ++i)
        a[s + i] = tmp[i];
}
void mergesort(int a[], int s, int e, int tmp[]) {
    if (s < e) {
        int m = s + (e - s) / 2;
        mergesort(a, s, m, tmp);
        mergesort(a, m + 1, e, tmp);
        merge(a, s, m, e, tmp);
    }
}

int main() {
    while (cin >> n >> k) {
        t = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        mergesort(a, 0, n - 1, b);
        cout << max(t - k, 0) << endl;
    }
    return 0;
}
