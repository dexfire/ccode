#include <cstdio>
#include <iostream>

#include <algorithm>

using namespace std;

#define per(i, a, b) for (int i = a; i <= b; i++)
#define input(a) scanf("%d", &a)
#define ll long long
int l, m, n, s, arr0[4005], arr1[4005], arr2[4005], ss[1005];
ll arr[300000];

int main() {
    int cnt = 1;
    while (~scanf("%d%d%d", &l, &m, &n)) {
        per(i, 0, l - 1) input(arr0[i]);
        per(i, 0, m - 1) input(arr1[i]);
        per(i, 0, n - 1) input(arr2[i]);
        int t = 0;
        per(i, 0, l - 1) {
            per(j, 0, m - 1) { arr[t++] = arr0[i] + arr1[j]; }
        }
        sort(arr, arr + t);
        sort(arr2, arr2 + n);
        input(s);
        printf("Case %d:\n", cnt);
        cnt++;
        per(i, 1, s) {
            int tmp;
            bool flag = false;
            input(tmp);
            per(j, 0, n - 1) {
                int tt = upper_bound(arr, arr + t, tmp - arr2[j]) -
                         lower_bound(arr, arr + t, tmp - arr2[j]);
                if (tt != 0) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}