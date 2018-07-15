#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *text = fopen("郭威.txt", "w+");
    char ch,flag=0;
    // 循环读取标准输入
    while(1){
        ch = getchar();
        //非\n直接输出
        if(ch!='\n'){           
            fputc(ch, text);
            //输入了一个非换行符，清标识flag
            if(flag)
                flag = 0;
        // 上次不是\n继续输出，置标识flag
        }else if(!flag){
            flag = 1;
            fputc(ch, text);
        // 连续输出换行，结束
        }else{
            break;
        }
    }
    system("pause");
}

