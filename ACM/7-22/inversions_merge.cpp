#include <cstdio>
#include <windows.h>

#define maxn 100005
int n, k;
int arr[maxn];
int temp[maxn]; //单线程 可以拿来共享
int count;

void EchoWithColor(char *str, int color = FOREGROUND_RED | FOREGROUND_GREEN |
                                          FOREGROUND_BLUE) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_INTENSITY | color);
    printf(str);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_INTENSITY | FOREGROUND_RED |
                                FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void merge(int arr[], int st, int mid, int ed, int stack) {
    for (int i = 0; i < stack; i++)
        EchoWithColor("  ", stack);
    printf("%d merge -> st:%d,mid:%d,ed:%d\n", stack, st + 1, mid + 1, ed + 1);
    int i = st, j = mid + 1, p = 0;
    while (i <= mid && j <= ed) {
        if (arr[i] < arr[j]) { //正序排序
            temp[p++] = arr[i++];
        } else {
            temp[p++] = arr[j++];
            count += (mid - i + 1);
        }
        // count++;
    }
    // 这里的i和j是可以和前面while循环衔接的
    while (i <= mid)
        temp[p++] = arr[i++];
    while (j <= ed)
        temp[p++] = arr[j++];
    // 拷贝数据
    for (int t = 0; t < ed - st + 1; t++)
        arr[t] = temp[t];
}

// 归并排序  时间复杂度
// 分治(递归、分割)思想： 将复杂的问题 无限分割
//                  最终分割成
//               一些*两个数*的排序问题
//			+  一些*一个数*的排序问题
//		5->2+3->2+2+1			4->2+2			3->2+1
//		而两个数和一个数的排序问题是可以直接解决的
//			【前提是使用相同的模式可求解】
//          例如：3个数进行merge_sort() （假定下标 0 、1、2）
//              则 mid = (0+2 )/2 =1 , 排序问题分割为
//      ① 0,1 元素排序
//				两个元素的比较和倒序是所有排序算法的核心，
//				当只剩两个元素时，merge_sort()将会直接return
//			    实际比较工作则在merge中完成
//			【line12 比较两个数的大小，完成两数比较和交换】
//		② 2,2 元素排序 【line39 return】
//				单个成员是不需要比较排序的，直接返回

// 归并排序高效性体现在哪里？

// 	为什么可以用归并排序求逆序数？？
//			逆序数可以用 对换 来考虑，产生一次对换，逆序数+1

// 函数解读
// 看第一个merge_sort() 如果把调用堆栈信息打印出来的话会发现，
// 最初一段时间都用来对st -> ed这段进行切割了
void merge_sort(int arr[], int st, int ed, int stack) {
    for (int i = 0; i < stack; i++)
        EchoWithColor("  ", stack);
    printf("%d merge_sort -> st:%d,ed:%d\n", stack, st + 1, ed + 1);
    if (ed <= st)
        return;
    int mid = (st + ed) / 2;

    merge_sort(arr, st, mid, stack + 1);
    merge_sort(arr, mid + 1, ed, stack + 1);
    merge(arr, st, mid, ed, stack + 1);
}

int main() {

    freopen("test.txt", "r", stdin);
    while (~scanf("%d%d", &n, &k)) {
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        count = 0;
        merge_sort(arr, 0, n - 1, 0);
        printf("%d\n", count - k > 0 ? count - k : 0);
    }
    fclose(stdin);
    return 0;
}