#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

char mp[1010][1010];
int book[1010][1010];
int nx[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int x1, x2, y1, y2, n, m;

struct node {
    int x, y, step;
    bool friend operator<(node a, node b) {
        return a.step > b.step; //注意符号
    }
};

int bfs() {
    priority_queue<node> q; //定义优先队列
    node now, tmp;
    now.x = x1;
    now.y = y1;
    now.step = 0;
    book[x1][y1] = 1;
    q.push(now);
    while (!q.empty()) {
        now = q.top();
        q.pop();
        if (now.x == x2 && now.y == y2)
            return now.step;
        for (int i = 0; i < 4; i++) {
            int tx = now.x + nx[i][0];
            int ty = now.y + nx[i][1];
            int tp = now.step;
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && book[tx][ty] == 0) {
                tmp.x = tx;
                tmp.y = ty;
                if (mp[tx][ty] == '.')
                    tp++;
                tmp.step = tp;
                book[tx][ty] = 1;
                q.push(tmp);
            }
        }
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        memset(book, 0, sizeof(book));
        for (int i = 0; i < n; i++)
            scanf("%s", mp[i]);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1--;
        y1--;
        x2--;
        y2--; //题中给的坐标是从1开始的
        printf("%d\n", bfs());
    }
    return 0;
}