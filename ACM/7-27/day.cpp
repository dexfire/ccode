#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        n += 2;
        if (n > 7)
            n -= 7;
        cout << n << endl;
    }
    return 0;
}