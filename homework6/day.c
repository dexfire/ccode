#include <stdio.h>
#include <math.h>

// ����ָ��
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satusday"};

int main(){
    int day = 1;
    while(1){
        printf("\n\t���������ڶ�Ӧ���֣�");
        scanf("%d",&day);
        // ���� ��Ӧ ��Ӧ�ַ������±�
        printf("\n\t\t%s\n\n\t", *(days + day));
    }
}