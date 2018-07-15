#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int balance, duration;
    double intrate;

    printf("\n\n\n\t\t\t请依次输入 【本金,利率,储蓄时长】");
    printf("\n\n\t\t\t以英文逗号分隔，单位分别为【元,1.0,年】");
    printf("\n\n\t\t\t例如：1000,0.03,10 表示 1000元，利率3.0%%，储蓄一年。");
    printf("\n\n\t\t\t请输入：");
    scanf("%d,%lf,%d",&balance,&intrate,&duration);
    printf("\n\n\n\t\t\t您的查询结果：");
    printf("\n\n\t\t\t%d 元本金在 %1.3lf%% 的利率下储蓄 %d 年后的本息之和为 %lf 元。",balance,intrate,duration,balance*(pow(1+intrate,duration)));
    getch();
}
