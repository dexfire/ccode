#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double a, b, c;
double delta;

int main()
{
    void less();
    void equal();
    void more();
    printf("\n\n\n\n\t\t请输入 Ax°+ Bx + C = 0 的三个系数 A B C 【空格隔开】：");
    scanf("%lf%lf%lf", &a, &b, &c);    //输入系数
    delta = b * b - 4 * a * c;
    printf("\n\n\t\t\t\tΔ= %.2lf ", delta);     // 输出Δ值
    if (delta == 0)
        equal();     // 求相等实根
    else if (delta < 0)
        less();       //求共轭复根
    else
        more();        //求两个实根
    printf("\n\n\n\n\n\t\t");
    system("pause");
    return 0;
}

void less()  //求共轭复根
{
    printf("< 0\n\n\t\t\t\tx1= %.2lf%+.2lfi ，x2= %.2lf%+.2lfi", -b / 2 / a, sqrt(-delta) / 2 / a, -b / 2 / a, -sqrt(-delta) / 2 / a);
}

void equal()    // 求相等实根
{
    printf("= 0\n\n\t\t\t\tx1= x2 = %.2lf", -b / 2 / a);
}

void more()  //求两个实根
{
    printf("< 0\n\n\t\t\t\tx1 = %.2lf ，x2= %.2lf", (-b + sqrt(delta)) / 2 / a, (-b - sqrt(delta)) / 2 / a);
}