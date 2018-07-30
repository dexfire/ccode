#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, t, x;
    string s;
    while (scanf("%d%d", &n, &t)) {
        priority_queue<int> a;
        for (int i = 0; i < n; i++) {
            cin>>s;
            if (s == "I") {
                scanf("%d", &x);
                a.push(x);
            } else if (s == "Q") {
                int c[t];
                for (int i = 0; i < t - 1; i++) {
                    c[i] = a.top();
                    a.pop();
                }
                printf("%d", a.top());
                for (int i = 0; i < t - 1; i++) {
                    a.push(c[i]);
                }
            }
        }
    }
    return 0;
}
