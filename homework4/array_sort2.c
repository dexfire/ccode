#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPEAT_FLAG -1
int main()
{
    int array[20];
    int i, j;
    //��һ������һ���Ƕ��еģ��Ҳ��ᱻ����ķ���ͳ�Ƶ��������ó�ֵΪ1
    size_t repeats = 0;
    srand((int)time(NULL));
    printf("ԭ����Ԫ�� array[20] = {");
    for (i = 0; i < 20; i++)
    {
        //���������������
        if(i>0)
        array[i] = array[i-1] + rand() % 2;
        else
        array[i] = rand() % 2;
        printf("%d, ", array[i]);

        //��0��һ���Ƕ����ģ����Դ�j=1��ʼ
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
    printf("}\n������Ԫ�� array[%d] = {", repeats);
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