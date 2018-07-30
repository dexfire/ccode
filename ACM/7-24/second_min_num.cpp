<<<<<<< HEAD
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct cmp {
    inline bool operator()(int a, int b) { return a > b; }
};
int c, n;
int t;
int main() {
    // freopen("second_min_num.txt", "r", stdin);
    cin >> c;
    while (c--) {
        priority_queue<int, vector<int>, cmp> queue;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            queue.push(t);
        }
        queue.pop();
        cout << queue.top() << endl;
    }
    return 0;
=======
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct cmp {
    inline bool operator()(int a, int b) { return a > b; }
};
int c, n;
int t;
int main() {
    // freopen("second_min_num.txt", "r", stdin);
    cin >> c;
    while (c--) {
        priority_queue<int, vector<int>, cmp> queue;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            queue.push(t);
        }
        queue.pop();
        cout << queue.top() << endl;
    }
    return 0;
>>>>>>> 36d7ee913d0bbaf3688fa4b5f3ecb33e5f923eb6
}