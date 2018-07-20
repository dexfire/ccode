#include <iostream>
#include <string.h>
using namespace std;

void exchange(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void  sort(int a[], int low, int high) {
    if (high <= low) {
        return;
    }
    int lt = low;
    int i = low + 1;
    int gt = high;
    int p = a[low];

    while (i <= gt) {
        if (a[i] < p) {
            exchange(a, i++, lt++);
        } else if (a[i] > p) {
            exchange(a, i++, gt--);
        } else {
            i++;
        }
    }
}

// void sort(int a[]) {
//     sort(a, 0, sizeof(a)/sizeof(int));
// }

int main(int argc, char const *argv[])
{
    int array[100];
    int t,idx;
    while(1){
        memset((wchar_t*)array, 0, idx);
        idx = 0;
        while(1){
            cin >> array[idx];
            if(array[idx]==0)
                break;
            idx++;
        }
        sort(array,0,idx+1);
        for (int i = 0; i <= idx;i++)
            cout << array[i]<<"  ";
        cout << endl;
    }
    return 0;
}
