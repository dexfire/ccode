#include <algorithm>

template <class T> inline void swap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

template <class T> void buble_sort(T arr[], int st, int ed) {
    if (ed <= st)
        return;
    for (int i = st; i < ed + 1; i++) {
        for (int j = i; j < 1 + ed; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

// µİ¹éË¼Ïë ¹é²¢ÅÅĞò
template <class T> void merge(T arr[], int st, int mid, int ed, T tmp[]) {
    int i = st, j = mid + 1, p = 0;
    while (i <= mid && j <= ed) {
        if (arr[i] < arr[j]) {
            tmp[p++] = arr[i];
        } else {
            tmp[p++] = arr[j];
        }
    }
    while (i <= mid)
        tmp[p++] = arr[i];
    while (j <= ed)
        tmp[p++] = arr[j];
    for (int i = 0; i < ed - st + 1; i++)
        arr[st + i] = tmp[i];
}

template <class T> void merge_sort(T arr[], int st, int ed) {
    if (ed <= st)
        return;
    int mid = (st + ed) / 2;
    merge_sort(arr, st, mid);
    merge_sort(arr, mid + 1, ed);
}
