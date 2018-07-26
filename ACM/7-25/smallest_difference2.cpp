#include <algorithm>
#include <iostream>
using namespace std;
int n;

int main() {
    // 数字自由组合，但是一般来说 2n 或者 2n+1 个 分为 N/2 和 N-N/2 个
    while (cin >> n) {
        int nums[n];
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums, nums + n);
        for (i = 0; i < n; i++) {
        }
    }
    return 0;
}