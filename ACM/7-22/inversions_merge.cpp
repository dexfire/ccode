#include <cstdio>
#include <windows.h>

#define maxn 100005
int n, k;
int arr[maxn];
int temp[maxn]; //���߳� ������������
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
        if (arr[i] < arr[j]) { //��������
            temp[p++] = arr[i++];
        } else {
            temp[p++] = arr[j++];
            count += (mid - i + 1);
        }
        // count++;
    }
    // �����i��j�ǿ��Ժ�ǰ��whileѭ���νӵ�
    while (i <= mid)
        temp[p++] = arr[i++];
    while (j <= ed)
        temp[p++] = arr[j++];
    // ��������
    for (int t = 0; t < ed - st + 1; t++)
        arr[t] = temp[t];
}

// �鲢����  ʱ�临�Ӷ�
// ����(�ݹ顢�ָ�)˼�룺 �����ӵ����� ���޷ָ�
//                  ���շָ��
//               һЩ*������*����������
//			+  һЩ*һ����*����������
//		5->2+3->2+2+1			4->2+2			3->2+1
//		����������һ���������������ǿ���ֱ�ӽ����
//			��ǰ����ʹ����ͬ��ģʽ����⡿
//          ���磺3��������merge_sort() ���ٶ��±� 0 ��1��2��
//              �� mid = (0+2 )/2 =1 , ��������ָ�Ϊ
//      �� 0,1 Ԫ������
//				����Ԫ�صıȽϺ͵��������������㷨�ĺ��ģ�
//				��ֻʣ����Ԫ��ʱ��merge_sort()����ֱ��return
//			    ʵ�ʱȽϹ�������merge�����
//			��line12 �Ƚ��������Ĵ�С����������ȽϺͽ�����
//		�� 2,2 Ԫ������ ��line39 return��
//				������Ա�ǲ���Ҫ�Ƚ�����ģ�ֱ�ӷ���

// �鲢�����Ч�����������

// 	Ϊʲô�����ù鲢����������������
//			������������ �Ի� �����ǣ�����һ�ζԻ���������+1

// �������
// ����һ��merge_sort() ����ѵ��ö�ջ��Ϣ��ӡ�����Ļ��ᷢ�֣�
// ���һ��ʱ�䶼������st -> ed��ν����и���
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