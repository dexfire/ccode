#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX_N = 100;
int G[MAX_N][MAX_N] = {{0}};
bool visited[MAX_N] = {0};
int path[MAX_N] = {0};
int start_v; //????
int end_v;   //????
int n;       //???
void loadG() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
}
void BFS() {
    queue<int> next;
    next.push(start_v);
    visited[start_v] = true;
    while (!next.empty()) {
        int v = next.front();
        next.pop();
        if (v == end_v)
            return;
        for (int i = 0; i < n; i++) {
            if (G[v][i] == 1) {
                if (!visited[i]) {
                    path[i] = v;
                    next.push(i);
                    visited[i] =
                        true; //????i?????????????
                }
            }
        }
    }
}
int main() {

    cin >> start_v >> end_v;
    start_v = start_v - 1; //??????0??
    end_v = end_v - 1;
    std::fill(path, path + MAX_N, -1); // or memset
    loadG();
    BFS();
    if (path[end_v] == -1)
        cout << "NO" << endl;
    else {
        stack<int> s;
        int v = end_v;
        while (path[v] != -1) {
            s.push(v);
            v = path[v];
        }
        s.push(v);
        while (!s.empty()) {
            cout << (s.top() + 1) << endl;
            s.pop();
        }
    }
    return 0;
}