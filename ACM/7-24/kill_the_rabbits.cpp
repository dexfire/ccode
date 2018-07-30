<<<<<<< HEAD
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;
int N, M;
int rabbits[MAX];

struct arrow {
    int attack;
    int price;
    int idx;
    // 伤害高，价格低->伤害低,价格高
    friend bool operator<(arrow a, arrow b) {
        if (a.attack == b.attack)
            return a.price < b.price;
        return a.attack < b.attack;
    }
} arrs[MAX];

/***
 * 题目要求 ：
 * 			杀死所有兔子
 * 			花的钱最少
 *
 * 		箭的伤害和价格不成正比【有的箭伤害高，而且廉价】
 * 1、箭：最小序列  兔子最小序列
 * 2、方案一：【思路错误】
 * 假设可以杀死，则
 * 用最少的钱，杀血最少的兔子，不能杀死就丢弃这支箭【不算钱】
 **/
int main() {
    freopen("rabbits.txt", "r", stdin);
    while (cin >> N >> M) {
        priority_queue<int> rabits; //兔子  最大优先队列，血量大到小

        int t;
        while (N--) {
            cin >> t;
            rabits.push(t);
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].attack;
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].price;
            arrs[i].idx = i;
        }
        int gold = 0;
        int hp;
        bool okay = true;
        if (M < N) { //肯定不能全杀死
            okay = false;
        } else { //开始杀兔子
            while (!rabits.empty()) {
                hp = rabits.top(); //从血量最多的兔子开始，否则算出来不是最小值
                rabits.pop();
                priority_queue<arrow> qarrs;       // 动态箭队列
                for (int i = M - 1; i >= 0; i--) { //能杀死兔子的箭加入队列
                    if (arrs[i].attack >= hp) {
                        qarrs.push(arrs[i]);
                    }
                }
                if (qarrs.empty()) {
                    okay = false;
                    break;
                } else {
                    gold +=
                        qarrs.top().price; //能杀死当前血量最高的兔子的最小花费
                    arrs[qarrs.top().idx].attack = 0; //避免重复
                    cout << gold;
                }
            }
        }
        if (okay)
            cout << gold << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
=======
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;
int N, M;
int rabbits[MAX];

struct arrow {
    int attack;
    int price;
    int idx;
    // 伤害高，价格低->伤害低,价格高
    friend bool operator<(arrow a, arrow b) {
        if (a.attack == b.attack)
            return a.price < b.price;
        return a.attack < b.attack;
    }
} arrs[MAX];

/***
 * 题目要求 ：
 * 			杀死所有兔子
 * 			花的钱最少
 *
 * 		箭的伤害和价格不成正比【有的箭伤害高，而且廉价】
 * 1、箭：最小序列  兔子最小序列
 * 2、方案一：【思路错误】
 * 假设可以杀死，则
 * 用最少的钱，杀血最少的兔子，不能杀死就丢弃这支箭【不算钱】
 **/
int main() {
    freopen("rabbits.txt", "r", stdin);
    while (cin >> N >> M) {
        priority_queue<int> rabits; //兔子  最大优先队列，血量大到小

        int t;
        while (N--) {
            cin >> t;
            rabits.push(t);
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].attack;
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].price;
            arrs[i].idx = i;
        }
        int gold = 0;
        int hp;
        bool okay = true;
        if (M < N) { //肯定不能全杀死
            okay = false;
        } else { //开始杀兔子
            while (!rabits.empty()) {
                hp = rabits.top(); //从血量最多的兔子开始，否则算出来不是最小值
                rabits.pop();
                priority_queue<arrow> qarrs;       // 动态箭队列
                for (int i = M - 1; i >= 0; i--) { //能杀死兔子的箭加入队列
                    if (arrs[i].attack >= hp) {
                        qarrs.push(arrs[i]);
                    }
                }
                if (qarrs.empty()) {
                    okay = false;
                    break;
                } else {
                    gold +=
                        qarrs.top().price; //能杀死当前血量最高的兔子的最小花费
                    arrs[qarrs.top().idx].attack = 0; //避免重复
                    cout << gold;
                }
            }
        }
        if (okay)
            cout << gold << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
>>>>>>> 36d7ee913d0bbaf3688fa4b5f3ecb33e5f923eb6
}