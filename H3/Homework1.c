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
    printf("\n\n\n\n\t\t������ Ax��+ Bx + C = 0 ������ϵ�� A B C ���ո��������");
    scanf("%lf%lf%lf", &a, &b, &c);    //����ϵ��
    delta = b * b - 4 * a * c;
    printf("\n\n\t\t\t\t��= %.2lf ", delta);     // �����ֵ
    if (delta == 0)
        equal();     // �����ʵ��
    else if (delta < 0)
        less();       //�����
    else
        more();        //������ʵ��
    printf("\n\n\n\n\n\t\t");
    system("pause");
    return 0;
}

void less()  //�����
{
    printf("< 0\n\n\t\t\t\tx1= %.2lf%+.2lfi ��x2= %.2lf%+.2lfi", -b / 2 / a, sqrt(-delta) / 2 / a, -b / 2 / a, -sqrt(-delta) / 2 / a);
}

void equal()    // �����ʵ��
{
    printf("= 0\n\n\t\t\t\tx1= x2 = %.2lf", -b / 2 / a);
}

void more()  //������ʵ��
{
    printf("< 0\n\n\t\t\t\tx1 = %.2lf ��x2= %.2lf", (-b + sqrt(delta)) / 2 / a, (-b - sqrt(delta)) / 2 / a);
}