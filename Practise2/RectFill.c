#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 0, n = 0, a = 0;
    printf("\n\n\n\n\t\t\t*\t�������������εĳ��ȺͿ�ȣ�Ӣ�Ķ��ŷָ���");
    fflush(stdin);
    scanf("%d,%d", &m,&n);
    printf("\n\t\t\t*\t��������������α߳���");
    fflush(stdin);
    scanf("%d", &a);
    printf("\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n\t\t\t*                          \t\t\t\t\t\t\t*");
    printf("\n\t\t\t*   ��Ϊ �� %d ����Ϊ�� %d ���ľ��ο������ɡ�%d �����߳�Ϊ��%d����������\t*", m, n, (m / a) * (n / a), a);
    printf("\n\t\t\t*                          \t\t\t\t\t\t\t*");
    printf("\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    getch();
}