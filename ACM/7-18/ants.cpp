#include <iostream>
#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

using namespace std;

//�������� - ��������ײ
// ���ʱ�䣺 �������϶��������
// �ʱ�䣺 �������϶���Զ����
int main() {
    // N ����ʵ����
    // L �˳��� nһ����������
    // max ,min ��̣��ʱ��
    // x �� xx ��ʱ����������λ��
    int N, n, L, min, max;
    int x, xx, t;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &L, &n);
            min = max = 0;
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                xx = L - x;
                if ((t = MIN(x, xx)) > min)
                    min = t;
                if ((t = MAX(x, xx)) > max)
                    max = t;
            }
            printf("%d %d\n", min, max);
            // cout << min << " " << max << endl;
        }
    }
}
