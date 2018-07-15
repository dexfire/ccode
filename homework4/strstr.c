#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s = "clang++ array_sort.c -o array_sort.exe -g -Wall -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw32 -std=c17++ -Wnoinvalid-source-encoding";
    int found = 0;
    // 输出原有字符串
    printf("\n\t\t字符串 s[%d] = \"%s\";\n", strlen(s),s);
    for (int i = 0; i < strlen(s);i++){
        for (int j = 0; j <strlen(s);j++){
            // 判断是否存在重复
            if( j!=i && *(s+j) == *(s+i)){
                //调试信息
                //printf(" *(s+%d):%c,\t*(s+%d):%c\n",j, *(s+j), i,*(s+i));
                // 找到重复 -> 跳过
                break;
            }
            // 没有重复？
            else if(j==strlen(s)-1){
                //调试信息
                //printf(" *(s+%d):%c,\t*(s+%d):%c\n",j, *(s+j), i,*(s+i));
                //判断标识
                found = 1;
                printf("\n\t\t首个不重复字符：%c\n\t\t所在位置为：%d\n\t\t",*(s+i),i);
            }
        }
        // 找到就跳出
        if(found){
            break;
        }else if(i==strlen(s)-1){
            // 没有不重复字符，输出 -1
            printf("\n\n\n\n\t\t-1\n\t\t");
        }
    }
    system("pause");
    return 0;
}