#include <stdio.h>
#include <stdlib.h>
#define ACC 1e-3     //��ȷ��10^-3

double a, b, c, d;
int main(){
    printf("\n\n\t\t�����뷽��Ax^3+Bx^2+Cx+D=0���ĸ�ϵ�� A B C D ���ո�ָ�����");
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double root(double s);
    printf("\n\n\t\tf(x)=0��ӽ�1�ĸ�Ϊ��x=%lf\n\n\t\t", root(1));
    system("pause");
}

double root(double s){
    double f(double x);
    double fx(double x);
    double abs1(double x);
    double x, x0 = s;
    x = x0 - f(x0) / fx(x0);  // ��һ�γ�ֵ
    while(abs(x-x0)>=ACC){     //��ȷ��Ҫ��
        x0 = x;
        x = x0 - f(x0) / fx(x0);    // ��������
    }
    return x;
}

double f(double x){    // ԭ����
    return a * x * x * x + b * x * x + c * x + d;
}

double fx(double x){  // ������
    return 3 * a * x * x + 2 * b * x + c;
}

double abs1(double _x){     // �����ֵ
    return _x >= 0 ? _x : -_x;
}