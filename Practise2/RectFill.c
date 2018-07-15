#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 0, n = 0, a = 0;
    printf("\n\n\n\n\t\t\t*\t请输入容器矩形的长度和宽度，英文逗号分隔：");
    fflush(stdin);
    scanf("%d,%d", &m,&n);
    printf("\n\t\t\t*\t请输入填充正方形边长：");
    fflush(stdin);
    scanf("%d", &a);
    printf("\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n\t\t\t*                          \t\t\t\t\t\t\t*");
    printf("\n\t\t\t*   长为 【 %d 】宽为【 %d 】的矩形可以容纳【%d 】个边长为【%d】的正方形\t*", m, n, (m / a) * (n / a), a);
    printf("\n\t\t\t*                          \t\t\t\t\t\t\t*");
    printf("\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    getch();
}