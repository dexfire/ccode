#include <stdio.h>
#include <stdlib.h>
#define ACC 1e-3     //精确度10^-3

double a, b, c, d;
int main(){
    printf("\n\n\t\t请输入方程Ax^3+Bx^2+Cx+D=0的四个系数 A B C D 【空格分隔】：");
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double root(double s);
    printf("\n\n\t\tf(x)=0最接近1的根为：x=%lf\n\n\t\t", root(1));
    system("pause");
}

double root(double s){
    double f(double x);
    double fx(double x);
    double abs1(double x);
    double x, x0 = s;
    x = x0 - f(x0) / fx(x0);  // 求一次初值
    while(abs(x-x0)>=ACC){     //精确度要求
        x0 = x;
        x = x0 - f(x0) / fx(x0);    // 反复迭代
    }
    return x;
}

double f(double x){    // 原函数
    return a * x * x * x + b * x * x + c * x + d;
}

double fx(double x){  // 导函数
    return 3 * a * x * x + 2 * b * x + c;
}

double abs1(double _x){     // 求绝对值
    return _x >= 0 ? _x : -_x;
}