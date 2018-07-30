#include <algorithm>
#include <iostream>
//#include <queue>

using namespace std;
#define MAX 10000
int n;
int arr[MAX];
int main() {
    // freopen("whats_middle.txt", "r", stdin);
    while (cin >> n) {
        // priority_queue<int> que;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << arr[n / 2] << endl;
    }
    return 0;
}