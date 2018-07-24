
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
struct node {
    int p, d, num; //λ�ú��ӵľ����Լ�����Ĵ���
    bool friend operator<(node a, node b) {
        if (a.p == b.p)
            return a.d > b.d;
        return a.p > b.p;
    }
} a;
int main() {
    // freopen("stones.txt", "r", stdin);
    int u;
    scanf("%d", &u);
    int n;
    int max; //���
    while (u--) {
        priority_queue<node> q;
        max = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &a.p, &a.d);
            q.push(a);
        }
        int time = 0; //��¼����
        while (!q.empty()) {
            a = q.top();
            q.pop();
            time++;
            if (time & 1) //����
            {
                a.p += a.d;
                if (a.p > max)
                    max = a.p;
                q.push(a);
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
