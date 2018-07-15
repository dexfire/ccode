#include "stdio.h"
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int X, Y, P;
    double R;
    printf("请输入要存入的本金,年利率和存入年数（用逗号隔开）:");
    scanf("%d,%lf,%d", &X, &R, &P);
    R = R * 100;
    Y = X * pow(((100 + R) / 100), P);
    printf("本息和为%d", Y);
    getch();
}