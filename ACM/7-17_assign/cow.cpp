#include <iostream>

using namespace std;
// �ռ�λ�� x[]
const int MAX = 100000;
int X[MAX]; // �ڴ�ռ�� 400KB
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
        } else {           // λ������
            if (i < C - 1) // ţû����
                return 0;
            else // ţ������
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