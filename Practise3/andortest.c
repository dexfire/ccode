#include <conio.h>
#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    printf("\n\na = %d ,b= %d , c = %d ", a, b, c);
    printf("\n\na++ || b++ && c++ = %d", a++ || b++ && c++);
    printf("\n\na = %d ,b= %d , c = %d ", a, b, c);
    getch();
}