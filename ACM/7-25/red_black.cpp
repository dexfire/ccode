#include <cstdio>
#include <iostream>
using namespace std;
const char blk = '.', red = '#', man = '@';
int w, h;
int x, y;
char arr[25][25];

int wfs(int xx, int yy, int &cnt) {
    if (arr[xx][yy] == red)
        return 0;
    else {
        arr[xx][yy] = red;
        cnt++;
        wfs(xx - 1, yy, cnt);
        wfs(xx + 1, yy, cnt);
        wfs(xx, yy - 1, cnt);
        wfs(xx, yy + 1, cnt);
    }
    return cnt;
}

int main() {
    // freopen("red_black.txt", "r", stdin);
    while (cin >> w >> h) {
        if (w == 0 && h == 0)
            return 0;
        char ch;
        for (int i = 1; i <= h; i++) {
            getchar();
            for (int j = 1; j <= w; j++) {
                scanf("%c", &arr[i][j]);
                if (arr[i][j] == man) {
                    x = i;
                    y = j;
                    arr[i][j] = blk;
                }
            }
        }
        //增加边界
        for (int i = 1; i <= w; i++) {
            arr[0][i] = red;
            arr[h + 1][i] = red;
        }
        for (int i = 1; i <= h; i++) {
            arr[i][0] = red;
            arr[i][w + 1] = red;
        }
        //开始搜索相连黑色方块
        int t = 0;
        cout << wfs(x, y, t) << endl;
    }
    return 0;
}