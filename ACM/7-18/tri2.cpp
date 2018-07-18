#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[101];
    // memset(A, 0, sizeof(A));
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + sizeof(A));
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++) {
                int len = A[i] + A[j] + A[k];
                int ma = max(A[i], max(A[j], A[k]));
                int rest = len - ma;
                if (rest > ma)
                    ans = max(len, ans);
            }
    }
    if (ans == 0)
        cout << "no" << endl;
    else
        cout << ans << endl;
    return 0;
}
