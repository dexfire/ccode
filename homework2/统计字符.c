#include <conio.h>
#include <ctype.h>
#include <iostream>

int main(int argc, char **argv)
{
    printf("\n\n\n\t\t\t������Ҫͳ�Ƶ��ַ���");
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
    printf("\n\n\n\t\t\t���ַ�����%u", nchar);
    printf("\n\n\n\t\t\t��ĸ����%u", nalpha);
    printf("\n\n\n\t\t\t��������%u", ndigit);
    printf("\n\n\n\t\t\t�ո�����%u", nspace);
    printf("\n\n\n\t\t\t����  ��%u", nother);
    getch();
}