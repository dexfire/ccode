#include <stdio.h>
#include <stdlib.h>
#define REPEAT_FLAG -1
int main()
{
    int array[20] = {0, 0, 1, 3, 3, 3, 4, 4, 5, 6, 8, 8, 8, 8, 8, 11, 12, 12, 13, 14};
    int i;
    //��һ������һ���Ƕ��еģ��Ҳ��ᱻ����ķ���ͳ�Ƶ��������ó�ֵΪ1
    int newlength = 1;
    printf("\n\n\t\tԭ����Ԫ��\t array[20] = {");
    for (i = 0; i < 20; i++)
    {
        //���ԭ��������
        printf("%d, ", array[i]);
        for (int j = 0; j < i; j++)
        {
            if (array[j] == array[i])
            {
                //��־��λ�ظ�
                array[i] = REPEAT_FLAG;
                break;
            }
            else if (j == i - 1)
            {
                //ͳ���³���
                newlength++;
            }
        }
    }
    printf("}\n\n\t\t���������Ԫ��\t array[%d] = {", newlength);
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