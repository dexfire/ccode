#include <stdio.h>
#include <string.h>
#include <conio.h>
//比较两个字符串的大小，返回结果：a>b?
int ismore(char *a, char *b)
{
    int minlen;
    if(strlen(a) > strlen(b) ){
        minlen = strlen(b);
    }else{
        minlen = strlen(a);
    }

    for (int i = 0; i < minlen; i++)
    {
        if (*(a + i) > *(b + i))
        {
            return 1;
        }
        else if (*(a + i) < *(b + i))
        {
            return 0;
        }
        //完全相同，且为最后一个字符？
        else if (i == minlen - 1)
        {
            // 如果a和b前面部分完全相同，且a比b短，则a“小”
            if (strlen(a) < strlen(b))
            {
                return 0;
            }
        }
    }
    return 0;
}

// 实现了全文字排序
int main()
{
    // 指向字符串的指针
    char *strs[] = {"China", "Japan", "Italy", "America", "Egypt","Angola","Austria","Canada","Switzerland","Mali","Cambodia","Zaire","Qatar"};
    char *tmp;
    for (int i = 0; i < sizeof(strs) / sizeof(char*); i++)
        printf("%s,",* (strs + i));
    printf("\n");
    for (int i = 0; i < sizeof(strs) / sizeof(char *); i++)
    {
        for (int j = i; j < sizeof(strs) / sizeof(char *); j++)
        {
            //前者比后者大则交换
            if (ismore(*(strs + i), *(strs + j)))
            {
                tmp = *(strs + i);
                *(strs + i) = *(strs + j);
                *(strs + j) = tmp;
            }
        }
        printf("%s\n", *(strs + i));
    }
    getch ();
}
