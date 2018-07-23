#include <stdio.h>
#include <string.h>

const int MAXN(100005);
bool visited[MAXN];
int n, k;
struct node {
    int x;    // Î»ÖÃ
    int step; //²½Êý
};
struct node q[MAXN];

int bfs() {
    node now, next;
    int head, tail;

    q[0].x = n;
    q[0].step = 0;
    head = 0;
    tail = 1;
    visited[n] = true;

    while (head < tail) {
        now = q[head];
        head++;
        for (int i = 0; i < 3; i++) {
            switch (i) {
            case 0:
                next.x = now.x - 1;
                break;
            case 1:
                next.x = now.x + 1;
                break;
            case 2:
                next.x = now.x * 2;
                break;
            }
            if (next.x < 0 || next.x >= MAXN)
                continue;
            if (!visited[next.x]) {
                visited[next.x] = true;
                next.step = now.step + 1;
                q[tail].x = next.x;
                q[tail].step = next.step;
                tail++;
                if (next.x == k)
                    return next.step;
            }
        }
    }
    return 0;
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        memset(visited, false, sizeof(visited));
        if (n >= k)
            printf("%d\n", n - k);
        else
            printf("%d\n", bfs());
    }
}
