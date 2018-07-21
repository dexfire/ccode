#include <iostream>
template <class T> void print(T arr, int offset, int count) {
    for (int i = offset; i < offset + count; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}