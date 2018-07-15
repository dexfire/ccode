#include <iostream>
#include <conio.h>

int main(int argc, char** argv){
    double weight;
    printf("\n\n\n\t\t\t请输入要邮寄的物品重量 [单位kg]：");
    scanf("%lf", &weight);
    if(weight<0){
        printf("\n\n\n\t\t\tem... 重量不能为负数哦。");
    }else if(weight>0&&weight<=10){
        printf("\n\n\n\t\t\t总共将收取%.2lf元。明细如下：", weight * 0.8 + 0.2);
        printf("\n\n\n\t\t\t\t\t\t手续费：￥0.2");
        printf("\n\n\n\t\t\t\t\t\t首重费：￥%.2lf",weight*0.8);
        printf("\n\n\n\t\t\t\t\t\t====================");
        printf("\n\n\n\t\t\t\t\t\t合计：￥%.2lf",weight * 0.8 + 0.2);
    }else if(weight>10&&weight<=20){
        printf("\n\n\n\t\t\t总共将收取%.2lf元。明细如下：", (weight-10)*0.75+10 * 0.8 + 0.2);
        printf("\n\n\n\t\t\t\t\t\t手续费：￥0.2");
        printf("\n\n\n\t\t\t\t\t\t首重费：￥%.2lf",10*0.8);
        printf("\n\n\n\t\t\t\t\t\t续重费：￥%.2lf",(weight-10)*0.75);
        printf("\n\n\n\t\t\t\t\t\t====================");
        printf("\n\n\n\t\t\t\t\t\t合计：￥%.2lf", (weight-10)*0.75+10 * 0.8 + 0.2);
    }else if(weight<=30){
        printf("\n\n\n\t\t\t总共将收取%.2lf元。明细如下：", (weight-20)*0.7+10*0.75+10 + 0.2);
        printf("\n\n\n\t\t\t\t\t\t手续费：￥0.2");
        printf("\n\n\n\t\t\t\t\t\t首重费：￥%.2lf",10*0.8);
        printf("\n\n\n\t\t\t\t\t\t续重费：￥%.2lf", weight-20*0.7+10*0.75);
        printf("\n\n\n\t\t\t\t\t\t====================");
        printf("\n\n\n\t\t\t\t\t\t合计：￥%.2lf", (weight-20)*0.7+10*0.75+10 + 0.2);
    }else{
        printf("Fail");
    }
    getch();
}
