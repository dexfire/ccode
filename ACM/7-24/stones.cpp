#include <iostream>
#include <queue>
using namespace std;
#define max(a, b) (a > b ? a : b)
struct stone {
    int p;
    int dis;
};
struct cmp {
    // 排序结果： 位置小优先 -> 距离大优先
    inline bool operator()(stone &a, stone &b) {
        if (a.p == b.p) // 如果位置相同，则优先处理最大的那个【扔的距离最小】
            return a.dis < b.dis;
        return a.p > b.p;
    }
};
int T;
int n;
bool odd;
long long result;
int main() {
    /***
     *	捡石头，遇到的第奇数个就扔，偶数个不管
     *				石头有限，不会一直循环扔
     *				最后一次处理的一个一定是偶数个的（奇数还会再扔一次，变为偶数）
     * 一个int 记录最大距离 :作为最终结果， 每次偶数个都记录此位置
     * 一个最小优先队列
     * 每次输入数据的操作：
     * 			看当前奇数还是偶数，
     * 			然后判断当前应该从 最小优先队列 拿数还是最大优先队列拿数
     * 偶数个的直接放进队列
     * 第奇数个进来的 ， +dis 后放入另一个最小优先队列
     *
     * 偶数个 直接放入队列
     */
    // freopen("stones.txt", "r", stdin);
    cin >> T;
    while (T--) {
        result = 0;
        cin >> n;
        priority_queue<stone, vector<stone>, cmp> q;
        for (int i = 0; i < n; i++) {
            stone t;
            cin >> t.p >> t.dis;
            q.push(t);
        }
        odd = false;
        while (!q.empty()) {
            odd = !odd;
            stone now = q.top();
            q.pop();
            // 抛弃掉同位置的小石头【】
            while (!q.empty() && q.top().p == now.p) {
                q.pop();
                odd = !odd; // ???
            }

            if (odd) {
                // cout << "throw " << now.p << " -> " << now.p + now.dis <<
                // endl;
                now.p += now.dis;
                result = max(result, now.p);
                q.push(now);
            } else {
                // cout << "stay " << now.p << endl;
                result = max(result, now.p);
            }
        }
        cout << result << endl;
    }
    return 0;
}
