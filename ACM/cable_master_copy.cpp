#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 10005;
const int MAX_N = 10005;
int N, K;
double Len[MAX_N];
bool C(double x) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        num += (int)(Len[i] / x);
    }
    return num >= K;
}

void solve() {
    double lb = 0.0, ub = (double)INF * 10.0, mid;
    for (int i = 0; i < 100; i++) {
        mid = (lb + ub) / 2;
        if (C(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%.2f\n", floor(ub * 100) / 100);
}

int main() {
    int i;
    while (scanf("%d %d", &N, &K) != EOF) {
        for (i = 0; i < N; i++)
            scanf("%lf", &Len[i]);
        solve();
    }
    return 0;
}