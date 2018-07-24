#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int siz = 100000 + 10;
int n, m;
int a[siz];
struct haha {
    int cost;
    int hurt;
    friend bool operator<(haha a, haha b) { return a.hurt > b.hurt; }
} q[siz];
int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
priority_queue<int, vector<int>, greater<int>> que;
int main() {

    int i;
    while (scanf("%d %d", &n, &m) != EOF) {
        while (!que.empty())
            que.pop();
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        qsort(a, n, sizeof(a[0]), cmp);
        for (i = 0; i < m; i++)
            scanf("%d", &q[i].hurt);
        for (i = 0; i < m; i++)
            scanf("%d", &q[i].cost);
        if (n > m) {
            printf("No\n");
            continue;
        }
        sort(q, q + m); // q 箭数组，伤害递增
        int k = 0, flag = 1;
        __int64 sum = 0;
        for (i = 0; i < n; i++) {                // 动态加入，排序
            while (q[k].hurt >= a[i] && k < m) { //伤害大于hp，箭没用完
                que.push(q[k].cost);
                k++;
            }
            if (que.empty()) {
                flag = 0;
                break;
            }
            sum += que.top();
            que.pop();
        }
        if (flag == 1)
            printf("%I64d\n", sum);
        else
            printf("No\n");
    }
    return 0;
}
