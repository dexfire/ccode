#include <cstdio>
#include <iostream>

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;
const int MAXN = 100005;
int num[MAXN], n, T, tmp[MAXN];
inline bool check(int l) {
    // 复制原始数组
    for (int i = 1; i <= n; i++)
        tmp[i] = num[i];
    tmp[1] = num[1] - 1; //?
    for (int i = 2; i <= n; i++)
        if (num[i] + l <= tmp[i - 1])
            return false;
        else
            tmp[i] = max(num[i] - l, tmp[i - 1] + 1);
    return true;
}

int main() {

    while (~scanf("%d", &T)) {

        for (int Rt = 1; Rt <= T; Rt++) {
            scanf("%d", &n);
            cout << "Case #" << Rt << ":" << endl;
            for (int i = 1; i <= n; i++)
                scanf("%d", &num[i]);

            int l = 0, r = 1000000, ans = 0;
            while (l <= r) {
                int mid = (l + r) >> 1; //除以2
                if (check(mid)) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}