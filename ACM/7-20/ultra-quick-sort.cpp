#include <iostream>
using namespace std;

int n;
int X[500005];
int swap_count;
template <class T> void swapx(T &a, T &b) {
    if (a == b)
        return;
    T t = a;
    a = b;
    b = t;
    swap_count++;
}

template <class T> void print(T arr, int offset, int count) {
    for (int i = offset; i < offset + count; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

template <class T> void quick_sort(T arr[], int st, int ed) {
    //移动流程 j 移动 -> i移动 -> j移动 -> ...
    // 用这种移动方式保证了起初的那个元素始终在“对方手中【比如while(i--)的时候，arr[j]=key】”
    if (ed <= st) //等于时候交换无意义，小于交换会出错
        return;
    int i = st, j = ed;
    T key = arr[st];
    while (i != j) {
        while (j > i && arr[j] >= key)
            j--;
        // print(arr, st, ed - st + 1);
        // cout << i << " --> " << j << endl;
        swapx(arr[j], arr[i]); //交换数值，坐标不变
        // print(arr, st, ed - st + 1);
        while (i < j && arr[i] <= key)
            i++;
        // print(arr, st, ed - st + 1);
        // cout << i << " <-- " << j << endl;
        swapx(arr[i], arr[j]);
        // print(arr, st, ed - st + 1);
    }
    quick_sort(arr, st, i - 1);
    quick_sort(arr, i + 1, ed);
}

int main() {
    while (cin >> n) {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        swap_count = 0;
        quick_sort<int>(X, 0, n - 1);
        cout << swap_count << endl;
    }
    return 0;
}
