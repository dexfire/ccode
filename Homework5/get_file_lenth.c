#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *text = fopen("sy5.txt", "r");
    int lines = 0;
    // ������
    char *str = (char *)malloc(1024);
    while(!feof(text)){
        fgets(str, 1024, text);
        // ͳ������
        lines++;
    }
    // ����������ļ���С
    printf("lines = %d\nsize = %d\n",lines,ftell(text));
    system("pause");
}