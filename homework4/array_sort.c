#include <stdio.h>
#include <stdlib.h>
#define REPEAT_FLAG -1
int main()
{
    int array[20] = {0, 0, 1, 3, 3, 3, 4, 4, 5, 6, 8, 8, 8, 8, 8, 11, 12, 12, 13, 14};
    int i;
    //第一个数字一定是独有的，且不会被后面的方法统计到，故设置初值为1
    int newlength = 1;
    printf("\n\n\t\t原数组元素\t array[20] = {");
    for (i = 0; i < 20; i++)
    {
        //输出原数组内容
        printf("%d, ", array[i]);
        for (int j = 0; j < i; j++)
        {
            if (array[j] == array[i])
            {
                //标志改位重复
                array[i] = REPEAT_FLAG;
                break;
            }
            else if (j == i - 1)
            {
                //统计新长度
                newlength++;
            }
        }
    }
    printf("}\n\n\t\t处理后数组元素\t array[%d] = {", newlength);
    for (i = 0; i < 20; i++)
    {
        if (array[i] != REPEAT_FLAG)
        {
            printf("%d, ", array[i]);
        }
    }
    printf("... }\n\n\n\n\t\t");
    system("pause");
    return 0;
}