#include <conio.h>
#include <ctype.h>
#include <iostream>

int main(int argc, char **argv)
{
    printf("\n\n\n\t\t\t请输入要统计的字符：");
    char ch;
    unsigned int nchar = 0;
    unsigned int nalpha = 0;
    unsigned int ndigit = 0;
    unsigned int nspace = 0;
    unsigned int nother = 0;

    while ((ch = getchar()) != '\n')
    {
        nchar++;
        if (isalpha(ch)){
            nalpha++;
        }
        else if (isdigit(ch)){
            ndigit++;
        }
        else if (ch ==' ') {
            nspace++;
        }
        else{
            nother++;
        }
    }
    printf("\n\n\n\t\t\t总字符数：%u", nchar);
    printf("\n\n\n\t\t\t字母数：%u", nalpha);
    printf("\n\n\n\t\t\t数字数：%u", ndigit);
    printf("\n\n\n\t\t\t空格数：%u", nspace);
    printf("\n\n\n\t\t\t其他  ：%u", nother);
    getch();
}