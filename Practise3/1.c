#include "stdio.h"
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int X, Y, P;
    double R;
    printf("������Ҫ����ı���,�����ʺʹ����������ö��Ÿ�����:");
    scanf("%d,%lf,%d", &X, &R, &P);
    R = R * 100;
    Y = X * pow(((100 + R) / 100), P);
    printf("��Ϣ��Ϊ%d", Y);
    getch();
}