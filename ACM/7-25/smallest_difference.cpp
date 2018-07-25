#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
int T;
int arr[10];
int n;

int diff() {
    for (int i = 0; i < n; i++) {
    }
}

int main() {
    cin >> T;
    vector<int> v;
    while (T--) {
        v.clear();
        char s[50];
        cin.getline(s, 50);
        istringstream ss(s);
        int t;
        n = 0;
        while (ss >> t)
            arr[n++] = t;
    }
    return 0;
}