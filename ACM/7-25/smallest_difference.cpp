#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
struct node {
    int a;
    int b;
    int c;
} datax[510];
struct pair {
    int a;
    int b;
};
bool cmp(node x, node y) {
    if (x.c == y.c)
        return abs(x.a - n / 2) < abs(y - a - n / 2);
    return x.c < y.c;
}

int T;
int arr[10];
int n;

// arr数组  0 -> cnt-1   低位 ->  高位
int arr2int(int arr[], int cnt) {
    int res;
    for (int i = 0; i < cnt; i++) {
        res += i * pow(10, i);
    }
    return res;
}

int diff() {
    int b = n / 2, a = n - b;
    bool used[n];
    fill(used, used + n, false);

    if (n % 2 == 0) {
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == 0)
                    continue;
                datax[idx].a = j;
                datax[idx].b = i;
                datax[idx].c = arr[j] - arr[i];
                idx++;
            }
        }
        sort(datax, datax + n, cmp);
    } else {
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
        sort(arr, arr + n);
    }
    return 0;
}