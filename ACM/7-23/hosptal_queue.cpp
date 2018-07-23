#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct man {
    int proprity;
    long order;
    // bool friend inline operator<(man &a, man &b) {
    //     return a.proprity < b.proprity;
    // }
};
struct cmp {
    bool inline operator()(man &a, man &b) { return a.proprity < b.proprity; }
};

// bool inline operator<(man &a, man &b) { return a.proprity < b.proprity; }
const string in = "IN", out = "OUT";
const char *ept = "EMPTY\n";
int n;
long order;
// ÁÙÊ±±äÁ¿
string tp;
int a, b;

int main() {
    // freopen("hosptal_queue.txt", "r", stdin);
    while (~scanf("%d", &n)) {
        priority_queue<man, vector<man>, cmp> queue_a, queue_b, queue_c;
        order = 1;
        for (int i = 0; i < n; i++) {
            cin >> tp;
            if (tp == in) {
                scanf("%d%d", &a, &b);
                man m = {b, order++};
                switch (a) {
                case 1:
                    queue_a.push(m);
                    break;
                case 2:
                    queue_b.push(m);
                    break;
                case 3:
                    queue_c.push(m);
                    break;
                }
            } else if (tp == out) {
                scanf("%d", &b);
                switch (b) {
                case 1:
                    if (!queue_a.empty()) {
                        printf("%ld\n", queue_a.top().order);
                        queue_a.pop();
                    } else
                        printf(ept);
                    break;
                case 2:
                    if (!queue_b.empty()) {
                        printf("%ld\n", queue_b.top().order);
                        queue_b.pop();
                    } else
                        printf(ept);
                    break;
                case 3:
                    if (!queue_c.empty()) {
                        printf("%ld\n", queue_c.top().order);
                        queue_c.pop();
                    } else
                        printf(ept);
                    break;
                }
            }
        }
    }
    return 0;
}