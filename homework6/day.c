#include <stdio.h>
#include <math.h>

// 数组指针
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satusday"};

int main(){
    int day = 1;
    while(1){
        printf("\n\t请输入星期对应数字：");
        scanf("%d",&day);
        // 数字 对应 对应字符串的下标
        printf("\n\t\t%s\n\n\t", *(days + day));
    }
}