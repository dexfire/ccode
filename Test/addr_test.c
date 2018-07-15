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
    printf("x是一级指针，指向x[0] ，也就是说x和 &x[0] 等价。\n\t而&x虽然地址和x一致，但为二级指针，需要取两次对象(*操作) 才能得到x[0] 的值。\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    printf("x[0] = %d\t &x[0] = %d\t *x[0] = error \t *&x[0] = %d\n\n\t",x[0], &x[0], /*  *x[0]  */ *&x[0]);
    SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);
    printf("x[0]是一个普通变量，*&x[0] = x[0]，说明 * 和 & 互为逆运算。\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    printf("x[5] = %d\t*(x+5) = %d\tx+5 = %d\t &x[5] = %d\t *x[5] = error \t*&x[5] = % d\n\n\t",x[5], *(x+5) ,x + 5, &x[5], /* *x[5] */ *&x[5]);
    SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);
    printf("*(x+5)=x[5]，指针的加减运算相应于数组下标的移动。\n\n\t");
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
    printf("y为二级指针，可以推断n维数组名肯定是一个n级指针(n>0)，指向的地址为首元素地址。\n\n\t");
    SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);

    printf("y[0] = %d\t")
    system("pause");
}