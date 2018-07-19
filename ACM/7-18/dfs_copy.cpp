#include <iostream>
using namespace std;
const int MAX_N = 100;
int G[MAX_N][MAX_N] = {{0}};
bool visited[MAX_N] = {0};
int start_v;
int end_v;
int n;
void loadG() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
}
bool DFS(int v) {
    if (v == end_v)
        return true;
    // 无向图
    // 重复访问会
    
    if (visited[v])
        return false;
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (G[v][i] == 1) {
            if (DFS(i))
                return true;
        }
    }
    return false;
}
int main() {
    cin >> start_v >> end_v;
    // 可读位置 到 数据存储位置变换
    start_v = start_v - 1;
    end_v = end_v - 1;
    // 输入矩阵
    loadG();
    cout << (DFS(start_v) ? "YES" : "NO") << endl;
    return 0;
}
