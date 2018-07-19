#include <iostream>
#include <stdio.h>

const int MAX = 102;
char G[MAX][MAX];
// char G[MAX][MAX] = {"............",   ".W........WW..", "..WWW.....WWW.",
//                     ".....WW...WW..", "..........WW..", "..........W...",
//                     "...W......W...", "..W.W.....WW..", ".W.W.W.....W..",
//                     "..W.W......W..", "...W.......W..", "............"};
const char W = 'W';
const char F = '.';
int n, m;

bool WFS(int x, int y) {
    if (G[x][y] == W) {
        G[x][y] = F;
        for (int i = -1; i < 2; i++) {
            WFS(x - 1, y + i);
            WFS(x + 1, y + i);
        }
        WFS(x, y - 1);
        WFS(x, y + 1);
        return true;
    } else {
        return false;
    }
}

int main() {
    // 数据分布  G[1->n][1->m]
    while (std::cin >> n >> m) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                std::cin >> G[i][j];
            }
        }
        // 增加边界
        for (int i = 0; i < n; i++)
            G[i][0] = G[i][m + 1] = F;
        for (int i = 0; i < m; i++)
            G[0][i] = G[n + 1][i] = F;
        // 处理图表
        int count = 0;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (WFS(i, j))
                    count++;
            }
        }

        printf("%d\n", count);
    }
}