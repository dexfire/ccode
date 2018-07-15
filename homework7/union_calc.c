#include <stdio.h>
#include <stdlib.h>

// 联合体定义
union num{
    int n1;
    double n2;
} num1, num2;
// 加
double add(union num a,union num b){
    return num1.n1 + num2.n2;
}
// 减
double minus(union num a,union num b){
    return num1.n1 - num2.n2;
}
// 乘
double muliply(union num a,union num b){
    return num1.n1 * num2.n2;
}
// 除
double divide(union num a,union num b){
    return num1.n1 / num2.n2;
}

int main(){
    // 输入数据
    printf("第一个数（int）：");
    scanf("%d", &num1.n1);
    printf("第二个数（double）：");
    scanf("%lf", &num2.n2);
    // 运算
    printf("\n计算结果：\n和：%lf，\n差：%lf，\n积：%lf，\n商：%lf\n\n", add(num1,num2),minus(num1,num2),muliply(num1,num2),divide(num1,num2));
    system("pause");
    return 0;
}