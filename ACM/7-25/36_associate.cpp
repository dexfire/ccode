#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int MAX = 100000;
int n;

bool okay(int x) {
    // 是否整除36
    if (x % 36 != 0)
        return false;
    stringstream ss;
    ss << x;
    string sxx = ss.str();
    if (sxx.find("36") == -1)
        return false;
    int pos = -1;
    //查找3后面不是6的情况
    while (pos < sxx.size() && (pos = sxx.find("3") != -1)) {
        if (pos + 1 < sxx.size() && sxx.at(pos + 1) == '6') {
            if (pos + 2 < sxx.size()) {
                sxx = sxx.substr(pos + 2);
            } else
                break; //结束查找跳出
        } else {       // 找到了3，但是字符串结束|后面不是6
            return false;
        }
    }
    //查找6前面不是3的情况
    while (pos < sxx.size() && (pos = sxx.find("6") != -1)) {
        // 6 前面是不是3？
        if (pos - 1 >= 0 && sxx.at(pos - 1) == '3') {
            if (pos + 1 < sxx.size())
                sxx = sxx.substr(pos + 1);
            else
                break;
        } else { // 找到了6，但是6是第一个字符|前面不是3
            return false;
        }
    }
    return true;
}

int main() {
    freopen("36.txt", "r", stdin);
    bool flag;
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> n;
        flag = false;
        for (int i = n; i < MAX + 1; i++) {
            if (okay(i)) {
                flag = true;
                cout << i << " @ " << n << endl;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
    }

    return 0;
}