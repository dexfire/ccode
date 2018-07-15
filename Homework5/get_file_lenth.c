#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *text = fopen("sy5.txt", "r");
    int lines = 0;
    // 缓冲区
    char *str = (char *)malloc(1024);
    while(!feof(text)){
        fgets(str, 1024, text);
        // 统计行数
        lines++;
    }
    // 输出行数和文件大小
    printf("lines = %d\nsize = %d\n",lines,ftell(text));
    system("pause");
}