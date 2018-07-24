
// 二分查找 要求有序数组 从小到大排序 O(log n)
template <class T> int binary_search(T arr[], int st, int ed, T key) {
    int lb = st, rb = ed;
    int mid;
    while (rb > lb) {
        mid = (st + ed) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > arr[key])
            rb = mid;
        else
            lb = mid;
    }
    if (arr[mid] == key)
        return mid;
    return -1;
}