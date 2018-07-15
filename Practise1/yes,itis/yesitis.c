#include <conio.h>
#include <stdio.h>

int main()
{
    unsigned int num, num2;
    printf("\n\n\t\t\t\t请输入一个三位正数：");
    scanf("%d", &num);
    num2 = num + num * 1000;
    if (num < 100)
    {
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*    您输入的是：%6d     \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*    数字不是三位正数哦~    \t\t*");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");

        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    您输入的是：%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d ÷ 7  ÷ 11 ÷ 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    其实两位数也可以的哈~('⊙ω⊙`)\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }
    else if (num > 999 & num< 10000000)
    {
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    您输入的是：%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d ÷ 7  ÷ 11 ÷ 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    超过三位数也可以诶~( ^ω^)\t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }
    else if(num >=10000000){
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    您输入的是：%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d ÷ 7  ÷ 11 ÷ 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    超过6位数就炸了~( ^ω^)\t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }else
    {
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    您输入的是：%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d ÷ 7  ÷ 11 ÷ 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    结果和原来的数一样哦~( ^ω^)\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                         诶嘿嘿..\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }
    printf("\n\n\n\n\t\t\t\t按下回车键退出...");
    getch();
    return 0;
}
