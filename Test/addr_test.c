#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    int x[20];
    printf("\n\n\tx = { \t");
    for (int i = 0; i < 20;i++){
        *(x+i) = i;
        printf(" %d ,", i);
    }
    printf(" }\n");

    printf("\n\n\tx = %d\t*x = %d\t**x = error\t&x = %d\t*&x=%d\t**&x = %d\n\n\t",x,*x, /*   **x  */ &x, *&x, **&x);
    SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);
    printf("x��һ��ָ�룬ָ��x[0] ��Ҳ����˵x�� &x[0] �ȼۡ�\n\t��&x��Ȼ��ַ��xһ�£���Ϊ����ָ�룬��Ҫȡ���ζ���(*����) ���ܵõ�x[0] ��ֵ��\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    printf("x[0] = %d\t &x[0] = %d\t *x[0] = error \t *&x[0] = %d\n\n\t",x[0], &x[0], /*  *x[0]  */ *&x[0]);
    SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);
    printf("x[0]��һ����ͨ������*&x[0] = x[0]��˵�� * �� & ��Ϊ�����㡣\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    printf("x[5] = %d\t*(x+5) = %d\tx+5 = %d\t &x[5] = %d\t *x[5] = error \t*&x[5] = % d\n\n\t",x[5], *(x+5) ,x + 5, &x[5], /* *x[5] */ *&x[5]);
    SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);
    printf("*(x+5)=x[5]��ָ��ļӼ�������Ӧ�������±���ƶ���\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    int y[4][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}};
    printf("\n\n\ty[4][5]={\n");
    for (int i = 0; i < 4;i++){
        printf("       \t{");
        for (int j = 0; j < 5;j++){
            printf(" %d ,",j);
        }
        printf("},\n");
    }
    printf("\t}\n\n\t");
    printf("y = %d\t*y = %d\t**y = %d\n\n\t",y,*y,**y);
    SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);
    printf("yΪ����ָ�룬�����ƶ�nά�������϶���һ��n��ָ��(n>0)��ָ��ĵ�ַΪ��Ԫ�ص�ַ��\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    printf("y[0] = %d\t")
    system("pause");
}