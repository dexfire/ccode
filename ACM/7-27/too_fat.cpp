#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double n;
    while (cin >> n) {
        n -= 100;
        n *= 1.8;
        cout << setiosflags(ios::fixed) << setprecision(1) << n;
    }
    return 0;
}