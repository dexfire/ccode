#include <stdio.h>
#include <string.h>
#include <conio.h>
//�Ƚ������ַ����Ĵ�С�����ؽ����a>b?
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
        //��ȫ��ͬ����Ϊ���һ���ַ���
        else if (i == minlen - 1)
        {
            // ���a��bǰ�沿����ȫ��ͬ����a��b�̣���a��С��
            if (strlen(a) < strlen(b))
            {
                return 0;
            }
        }
    }
    return 0;
}

// ʵ����ȫ��������
int main()
{
    // ָ���ַ�����ָ��
    char *strs[] = {"China", "Japan", "Italy", "America", "Egypt","Angola","Austria","Canada","Switzerland","Mali","Cambodia","Zaire","Qatar"};
    char *tmp;
    for (int i = 0; i < sizeof(strs) / sizeof(char*); i++)
        printf("%s,",* (strs + i));
    printf("\n");
    for (int i = 0; i < sizeof(strs) / sizeof(char *); i++)
    {
        for (int j = i; j < sizeof(strs) / sizeof(char *); j++)
        {
            //ǰ�߱Ⱥ��ߴ��򽻻�
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
