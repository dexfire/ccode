#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *text = fopen("sy5.txt","r");
    // �ַ���������
    char *str = (char*)malloc(1024);
    // ��һ��ֱ�������������ʼֵΪ1����ı�����Ĭ��Ϊ��һ�г���
    int lines = 1,maxlenth = 0;
    printf("%s", fgets(str,1024,text));
    maxlenth = ftell(text);
    // ѭ����ȡ
    while(!feof(text)){
        // ͳ������
        lines++;
        fgets(str, 1024, text);
        // ���ָ������ַ����������󳤶�
        if(strlen(str)>maxlenth)
            maxlenth = strlen(str);
    }
    // �������lines �Լ� ��г���
    printf("\nlines = %d\nmaxlenth = %d\n", lines,maxlenth);
    system("pause");
}