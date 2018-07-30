/***
 * 木棒还原问题:
 *  木棒原来是一样长的，后来发生了一场爆炸，o(╯□╰)o 然后被炸成无数小段
 *  求原来每节木棒总长
 * 备注要求:
 *  原来最少两根。
 *  原长度最少0（忽略这个条件..），最多50。
 *  分割后最多64根。
 *  找出 *最小* 可能长度。
 *
 * 解题思路：
 *  枚举法 + 剪枝
 *      1、读入数据
 *      2、长度排序，确定搜索范围
 *      3、开始搜索，逐个数据检验是否合适
 *      4、找到合适的输出
 *
 * 检验方法
 *      找一根木棒作为基础，然后在上面加
 *          长了 -> 换下一根(更短的！)，这一根丢进（本次检验的）黑名单
 *          短了 -> 寻找下一根（依然先长后短）
 *              长了 -> 换下一根(更短的！)，这一根丢进（本次检验的）黑名单
 *              短了 -> 寻找下一根（依然先长后短）
 *                  ...
 *                  ... 【递归过程】
 *          合适-> 去掉用过的木棒，继续拼下一根
 *          木棒用完了 -> 检验ok，输出结果
 *
 * 剪枝法的应用：
 *  搜索范围
 *      首先，大致范围 单根最大长度 -> min(总长度/2,50)
 *      其次，总长度 *一定* 是原长度的整数倍
 *  验证原长是否合适
 *      从最长的棍子开始拼，
 *
 * 一些细节问题：
 *  单根长度使用vector储存，方便查长度
 *  检验过程不能破坏原数据
 *
 **/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define min(a, b) (a < b ? a : b)
int n;
vector<int> sticks(64);
int alllen;
int t; //临时变量

bool chk(int len) { sticks. }

int solve() {
    int min = sticks.back();
    int max = min(alllen / n, 50);
    if (min <= max)
        return -2;
    for (int i = min; i <= max; i++) {
        if (chk(i))
            return i;
    }
    return -1;
}

int main() {

    while (cin >> n) {
        alllen = 0;
        for (int i = 0; i < n; i++) {
            cin >> t;
            sticks.push_back(t);
            alllen += t;
        }
        sort(sticks.begin(), sticks.end(), greater<int>());
    }
}