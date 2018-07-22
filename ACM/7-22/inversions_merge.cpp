#include <cstdio>
#define maxn 100005
int n, k;
int arr[maxn];
int temp[maxn]; //���߳� ������������
int count;
void merge(int arr[], int st, int mid, int ed) {
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

void merge_sort(int arr[], int st, int ed) {
    if (ed <= st)
        return;
    int mid = (st + ed) / 2;
    merge_sort(arr, st, mid);
    merge_sort(arr, mid + 1, ed);
    merge(arr, st, mid, ed);
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        count = 0;
        merge_sort(arr, 0, n - 1);
        printf("%d\n", count - k > 0 ? count - k : 0);
    }
    return 0;
}