#include <algorithm>
#include <iostream>

using namespace std;
// N people  M total elements K used
int N, M, K;

void req2idx(double ele[], double req, int count, int result[], int offset) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < M; j++) {
            if (req == ele[j]) {
                ele[j] = 0;
                result[offset + i] = j;
                break;
            }
        }
    }
}

int main() {
    // 要求： 找出最大的需求值
    // 思路：  需求值合并（相加）->  需求值排序 -> 取最大需求值
    //              -> 查找需求值对应的原下标（难点是需求值相同时的处理） ->
    //              下标值重排序 -> 逆序输出
    while (cin >> N >> M >> K) {
        double element[M];
        double element_copy[M];

        double req;
        fill(element, element + M, 0.0);  // 初始化为0
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> req;
                element[j] += req;
                element_copy[j] = element[j];  //拷贝一份原序列 用于后续查找下标
            }
        }
        sort<double*>(element, element + M);  //对需求值排序
        int result[K];                        //保存最终的下标值结果
        int c, offset = 0;                    // c : 需求值重复次数
        // offset : 结果数组的当前写入位置
        for (int i = M - 1; i > M - K - 1;
             i--) {  // 取需求值最大的K个（M -> M-K）-1
            c = 1;
            //统计需求值重复次数
            while (i > (M - K - 2) && element[i] == element[i - 1]) {
                i--;
                c++;
            }
            // 需求值转为下标值，结果在result数组中
            req2idx(element_copy, element[i], c, result, offset);
            offset += c;  //移动result数组当前写入位置
        }
        sort(result, result + K);
        //逆序输出
        for (int i = K - 1; i > 0; i--) {
            cout << result[i] + 1 << " ";
        }
        cout << result[0] + 1 << endl;
    }
    return 0;
}