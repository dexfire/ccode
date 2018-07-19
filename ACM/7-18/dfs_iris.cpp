#include <iostream>
#include <stdio.h>

using namespace std;

// char G[105][105];
int ans, n, m;
char G[105][105] = {"............",   ".W........WW..", "..WWW.....WWW.",
                    ".....WW...WW..", "..........WW..", "..........W...",
                    "...W......W...", "..W.W.....WW..", ".W.W.W.....W..",
                    "..W.W......W..", "...W.......W..", "............"};

////int LeftRight[9] = { 0,0,1,1,1,0,-1,-1,-1 }, UpDown[9] = {
/// 0,1,1,0,-1,-1,-1,0,1 };
// char W = 'W';
// char F = '.';

void DFS(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return;
    if (G[i][j] == 'W')
        G[i][j] = '.';
    for (int k = -1; k < 2; k++) {
        DFS(i + 1, j + k);
        DFS(i - 1, j + k);
    }
    DFS(i, j - 1);
    DFS(i, j + 1);
    return;
}

int main() {
    cin >> n >> m;
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cin >> G[i][j];

    for (int i = 0; i < n; i++)
        G[i][0] = G[i][m + 1] = '.';
    for (int i = 0; i < m; i++)
        G[0][i] = G[n + 1][i] = '.';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (G[i][j] == 'W') {
                DFS(i, j);
                ans++;
            }

    cout << ans << endl;

    system("pause");

    return 0;
}
