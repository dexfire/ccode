#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
//#define LOACL
#define space " "
using namespace std;
// typedef long long LL;
// typedef __int64 Int;
typedef pair<int, int> PAI;
const int INF = 0x3f3f3f3f;
const double ESP = 1e-5;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MAXN = 500 + 10;
int num[MAXN];
char c;
struct node {
    int a, b, c;
} datax[MAXN];
int cnt;
bool cmp(node x, node y) {
    if (x.c == y.c)
        return (abs(x.a - cnt / 2) < abs(y.a - cnt / 2));
    return x.c < y.c;
}
int main() {
    int T;
    scanf("%d", &T);
    getchar();
    while (T--) {
        cnt = 0;
        while (c = getchar()) {
            if (c == '\n')
                break;
            if (c >= '0' && c <= '9')
                num[cnt++] = c - '0';
        }
        sort(num, num + cnt);
        int a = 0, b = 0;
        int ans = INF;
        if (cnt == 2) {
            ans = num[1] - num[0];
        } else if (cnt & 1) {
            for (int i = 0; i < (cnt + 1) / 2; i++) {
                if (num[i] == 0) {
                    a = a * 10 + num[++i];
                    a = a * 10;
                } else
                    a = a * 10 + num[i];
            }
            // cout << a << endl;
            for (int i = cnt - 1; i >= (cnt + 1) / 2; i--) {
                b = b * 10 + num[i];
            }
            ans = a - b;
            //  cout << a << space << b << endl;
        } else {
            int cut = 0;
            for (int i = 0; i < cnt; i++) {
                for (int j = i + 1; j < cnt; j++) {
                    if (num[i] == 0)
                        continue;
                    datax[cut].a = j;
                    datax[cut].b = i;
                    datax[cut++].c = num[j] - num[i];
                }
            }
            sort(datax, datax + cut, cmp);
            // for (int i = 0; i < cut; i++) cout << datax[i].a << space <<
            // datax[i].b << space << datax[i].c << endl;
            int k = abs(datax[0].a - cnt / 2) == abs(datax[1].a - cnt / 2);
            k++;
            // cout << "k= " << k << endl;
            while (k--) {
                int ca = cnt / 2 - 1;
                int cb = cnt / 2 - 1;
                int ta = datax[k].a, tb = datax[k].b;
                a = num[ta];
                b = num[tb];
                for (int i = 0; i < cnt; i++) {
                    if (ca == 0) {
                        ca = i;
                        break;
                    }
                    if (i != ta && i != tb) {
                        ca--;
                        a = a * 10 + num[i];
                    }
                }
                for (int i = cnt - 1; i >= ca; i--) {
                    if (i != ta && i != tb) {
                        b = b * 10 + num[i];
                    }
                }
                ans = min(ans, a - b);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
