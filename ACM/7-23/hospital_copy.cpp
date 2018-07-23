#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
class que {
  public:
    int id, level;
    friend bool operator<(que ca,
                          que cb) //重载<号是从大到小排序，>号是从小到大排序
    {
        if (ca.level != cb.level)
            return ca.level < cb.level;
        else
            return ca.id > cb.id;
    }
};
int N;
int main() {
    // freopen("hosptal_queue.txt", "r", stdin);
    // int i, j;
    while (~scanf("%d", &N)) {
        string ch;
        int doctor, level;
        priority_queue<que> p[4];
        int ans = 0;
        que temp;

        while (N--) {
            cin >> ch;
            if (ch == "IN") {
                cin >> doctor >> level;
                temp.id = ++ans;
                temp.level = level;
                p[doctor].push(temp);
            } else {
                cin >> doctor;
                if (p[doctor].empty()) {
                    printf("EMPTY\n");
                } else {
                    printf("%d\n", p[doctor].top().id);
                    p[doctor].pop();
                }
            }
        }
    }
    return 0;
}
