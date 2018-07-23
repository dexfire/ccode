#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
int const MAX = 1e4 + 5;

struct Stop {
    int dis, fuel;
} s[MAX];

bool cmp(Stop a, Stop b) { return a.dis < b.dis; }

int main() {
    int n, l, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i].dis, &s[i].fuel);
    scanf("%d %d", &l, &p);
    for (int i = 0; i < n; i++)
        s[i].dis = l - s[i].dis;
    s[n].fuel = 0; //将终点加进去
    s[n++].dis = l;
    sort(s, s + n, cmp);
    priority_queue<int> q;
    int ans = 0, pos = 0, num = p;
    for (int i = 0; i < n; i++) {
        int d = s[i].dis - pos;
        while (num < d) {
            if (q.empty()) {
                printf("-1\n");
                return 0;
            }
            ans++; //加油
            num += q.top();
            q.pop();
        }
        num -= d;
        q.push(s[i].fuel);
        pos = s[i].dis;
    }
    printf("%d\n", ans);
}