#include <conio.h>
#include <stdio.h>

int main()
{
    unsigned int num, num2;
    printf("\n\n\t\t\t\t������һ����λ������");
    scanf("%d", &num);
    num2 = num + num * 1000;
    if (num < 100)
    {
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*    ��������ǣ�%6d     \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*    ���ֲ�����λ����Ŷ~    \t\t*");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");

        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    ��������ǣ�%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d �� 7  �� 11 �� 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    ��ʵ��λ��Ҳ���ԵĹ�~('�Ѧء�`)\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }
    else if (num > 999 & num< 10000000)
    {
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    ��������ǣ�%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d �� 7  �� 11 �� 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    ������λ��Ҳ������~( ^��^)\t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }
    else if(num >=10000000){
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    ��������ǣ�%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d �� 7  �� 11 �� 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    ����6λ����ը��~( ^��^)\t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }else
    {
        printf("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*                         \t\t*");
        printf("\n\t\t\t\t*    ��������ǣ�%6d \t\t*", num);
        printf("\n\t\t\t\t*                           \t\t*");
        printf("\n\t\t\t\t*   %3d �� 7  �� 11 �� 13 = %3d \t*", num2, num2 / 7 / 11 / 13);
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*    �����ԭ������һ��Ŷ~( ^��^)\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                         ���ٺ�..\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t*                          \t\t*");
        printf("\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * *");
    }
    printf("\n\n\n\n\t\t\t\t���»س����˳�...");
    getch();
    return 0;
}
