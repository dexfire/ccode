#include <algorithm>
#include <iostream>
using namespace std;

bool f36(int x) {
    while (x > 0) {
        if (x % 10 == 6) {
            if (x % 100 == 36)
                return true;
        }
        x /= 10;
    }
    return false;
}
int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        int flag = 0;
        for (int j = x; j <= 100000; j++) {
            if (j % 36 == 0 && f36(j)) {
                cout << j << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "-1" << endl;
    }
    return 0;
}
