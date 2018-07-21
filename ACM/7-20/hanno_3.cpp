#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;

void move(int x, string a, string b, string c) {
    if (x == 1) {
        cout << "move " << a << " --> " << c << endl;
        return;
    }
    move(x - 1, a, c, b);
    cout << "move " << a << " --> " << c << endl;
    move(x - 1, b, a, c);
}

int main() {
    while (~scanf("%d", &n)) {
        move(n, "A", "B", "C");
    }
    return 0;
}