#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPEAT_FLAG -1
int main()
{
    int array[20];
    int i, j;
    //第一个数字一定是独有的，且不会被后面的方法统计到，故设置初值为1
    size_t repeats = 0;
    srand((int)time(NULL));
    printf("原数组元素 array[20] = {");
    for (i = 0; i < 20; i++)
    {
        //生成随机排序数组
        if(i>0)
        array[i] = array[i-1] + rand() % 2;
        else
        array[i] = rand() % 2;
        printf("%d, ", array[i]);

        //第0个一定是独立的，所以从j=1开始
        for (int j = 1; j < i; j++)
        {
            if (array[j] == array[i])
            {
                repeats++;
                array[i] = REPEAT_FLAG;
                break;
            }
        }
    }
    printf("}\n新数组元素 array[%d] = {", repeats);
    for (i = 0; i < 20; i++)
    {
        if (array[i] != REPEAT_FLAG)
        {
            printf("%d, ", array[i]);
        }
    }
    printf("}\n");
    system("pause");
    return 0;
}