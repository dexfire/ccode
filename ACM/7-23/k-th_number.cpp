#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, t, x;
    char b[100];
    while (cin >> n >> t) {
        priority_queue<int> a;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] == 'I') {
                cin >> x;
                a.push(x);
            }
            if (b[i] == 'Q') {
                int c[t];
                for (int i = 0; i < t - 1; i++) {
                    c[i] = a.top();
                    a.pop();
                }
                cout << a.top() << endl;
                for (int i = 0; i < t - 1; i++) {
                    a.push(c[i]);
                }
            }
        }
    }
    return 0;
}
