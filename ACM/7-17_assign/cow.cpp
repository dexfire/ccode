#include <iostream>

using namespace std;
// 空间位置 x[]
const int MAX = 100000;
int X[MAX]; // 内存占用 400KB
int N, C;

// put cows test
int pc(int x) {
    int idx = 0;
    int dx;
    for (int i = 0; i < C; i++) {
        dx = 0;
        if (idx < N) {
            while (dx < x)
                dx += X[idx++];
        } else {           // 位置用完
            if (i < C - 1) // 牛没放完
                return 0;
            else // 牛放完了
                return 1;
        }
    }
}

void solve() {
    int lb, rb, mid;
    mid = lb + (rb - lb) / 2;
    while ()
}

int main() {
    while (cin >> N >> C) {
        for (int i = 0; i < N; i++)
            cin >> X[i];
    }
    solve();
    return 0;
}