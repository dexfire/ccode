template <typename T> void merge(T a[], int s, int m, int e, T tmp[]) {
    int pb = 0;
    int p1 = s;
    int p2 = m + 1;
    while (p1 <= m && p2 <= e) {
        if (a[p1] < a[p2]) {
            tmp[pb++] = a[p1++];
        } else {
            tmp[pb++] = a[p2++];
        }
    }
    while (p1 <= m) {
        tmp[pb++] = a[p1++];
    }
    while (p2 <= e) {
        tmp[pb++] = a[p2++];
    }
}
// Ê±¼ä¸´ÔÓ¶È  (nlogn)
template <typename T> void merge_sort(T a[], int s, int e, T tmp[]) {
    if (a < e) {
        int m = (s + e) / 2;
        merge_sort(a, s, m, tmp);
        merge_sort(a, m + 1, e, tmp);
        merge(a, s, m, e, tmp);
    }
}