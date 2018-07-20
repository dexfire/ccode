#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 1005
// Scores
int sc[MAX];
int fsc[MAX];
double rate[MAX];
double rate_cp[MAX];

int main() {
    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++)
            cin >> sc[i];
        for (int i = 0; i < n; i++) {
            cin >> fsc[i];
            rate[i] = sc[i] / fsc[i];
            rate_cp[i] = rate[i];
        }
        sort(rate, rate + n);
    }
}