#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *text = fopen("sy5.txt","r");
    // 字符串缓冲区
    char *str = (char*)malloc(1024);
    // 第一行直接输出，行数初始值为1，最长文本长度默认为第一行长度
    int lines = 1,maxlenth = 0;
    printf("%s", fgets(str,1024,text));
    maxlenth = ftell(text);
    // 循环读取
    while(!feof(text)){
        // 统计行数
        lines++;
        fgets(str, 1024, text);
        // 出现更长的字符串则更新最大长度
        if(strlen(str)>maxlenth)
            maxlenth = strlen(str);
    }
    // 输出行数lines 以及 最长行长度
    printf("\nlines = %d\nmaxlenth = %d\n", lines,maxlenth);
    system("pause");
}