#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int balance, duration;
    double intrate;

    printf("\n\n\n\t\t\t���������� ������,����,����ʱ����");
    printf("\n\n\t\t\t��Ӣ�Ķ��ŷָ�����λ�ֱ�Ϊ��Ԫ,1.0,�꡿");
    printf("\n\n\t\t\t���磺1000,0.03,10 ��ʾ 1000Ԫ������3.0%%������һ�ꡣ");
    printf("\n\n\t\t\t�����룺");
    scanf("%d,%lf,%d",&balance,&intrate,&duration);
    printf("\n\n\n\t\t\t���Ĳ�ѯ�����");
    printf("\n\n\t\t\t%d Ԫ������ %1.3lf%% �������´��� %d ���ı�Ϣ֮��Ϊ %lf Ԫ��",balance,intrate,duration,balance*(pow(1+intrate,duration)));
    getch();
}
