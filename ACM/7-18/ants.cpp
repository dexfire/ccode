#include <iostream>
#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

using namespace std;

//分析方法 - 不考虑碰撞
// 最短时间： 所有蚂蚁都向近端走
// 最长时间： 所有蚂蚁都向远端走
int main() {
    // N 测试实例数
    // L 杆长， n一根杆蚂蚁数
    // max ,min 最短，最长时间
    // x ， xx 临时变量，蚂蚁位置
    int N, n, L, min, max;
    int x, xx, t;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &L, &n);
            min = max = 0;
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                xx = L - x;
                if ((t = MIN(x, xx)) > min)
                    min = t;
                if ((t = MAX(x, xx)) > max)
                    max = t;
            }
            printf("%d %d\n", min, max);
            // cout << min << " " << max << endl;
        }
    }
}
