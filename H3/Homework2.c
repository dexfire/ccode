#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fan(int m);
    printf("\n\n\n\t\t������һ��������");
    int m;
    scanf("%d", &m);                                                                                                                    // ��������
    printf("\n\n\t\t��λ����֮��Ϊ��%d\n\n\n\n\n\t\t", fan(m));
    system("pause");
}

/**
 *         ����ǩ���� int fan( int m ) 
 *         �Բ���m�ĸ�λ��ͣ����������ֵ��
 **/
int fan(int m)
{
    int sum = 0;
    while ( m >= 10)
    {
        sum += m % 10;                                                                                                                // ͳ��ֵ ���� ���ڵĸ�λ��ֵ
        m /= 10;                                                                                                                            // ��ֵ����ʮ���൱����λ��������λ��
    }
    return sum+m;                                                                                                                      // �������յĸ�λ��ֵ
}