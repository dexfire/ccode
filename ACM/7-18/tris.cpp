#include <algorithm>
#include <iostream>

using namespace std;
int n;
int arr[100];

bool okay(int i, int j, int k) {
    i = arr[i];
    j = arr[j];
    k = arr[k];
    if (i + j <= k || i + k <= j || j + k <= i)
        return false;
    return true;
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // sort(arr, arr + 100);
        int sum, max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    if (okay(i, j, k)) {
                        sum = arr[i] + arr[j] + arr[k];
                        if (sum > max)
                            max = sum;
                    }
                }
            }
        }
        cout << max << endl;
    }
}