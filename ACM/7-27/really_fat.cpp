#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int t;
    int h, w;
    double stdx;
    double cmp;
    while (t--) {
        cin >> h >> w;
        stdx = h - 100;
        stdx *= 1.8;
        cmp = w - stdx;
        if (abs(cmp) <= 0.1 * stdx) {
            cout << "You are wan mei!" << endl;
        } else if (cmp > 0) {
            cout << "You are tai pang le !" << endl;
        } else if (cmp < 0) {
            cout << "You are tai shou le !" << endl;
        }
    }
    return 0;
}