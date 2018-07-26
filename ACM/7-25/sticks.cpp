#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> sticks(64);
int t; //临时变量
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> t;
            sticks.push_back(t);
        }
        sort(sticks.begin(), sticks.end(), greater<int>);
    }
}