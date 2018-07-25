#include <algorithm>
#include <iostream>
using namespace std;

bool f36(int x) {
    int a = 0, b = 0, c = 0;
    while (x > 0) {
        if (x % 10 == 6) {
            a++;
            if (x % 100 == 36)
                b++;
        } else if (x % 10 == 3)
            c++;
        x /= 10;
    }
    if (a == c && a == b && b > 0)
        return true;
    else
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
