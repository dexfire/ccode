#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s = "clang++ array_sort.c -o array_sort.exe -g -Wall -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw32 -std=c17++ -Wnoinvalid-source-encoding";
    int found = 0;
    // ���ԭ���ַ���
    printf("\n\t\t�ַ��� s[%d] = \"%s\";\n", strlen(s),s);
    for (int i = 0; i < strlen(s);i++){
        for (int j = 0; j <strlen(s);j++){
            // �ж��Ƿ�����ظ�
            if( j!=i && *(s+j) == *(s+i)){
                //������Ϣ
                //printf(" *(s+%d):%c,\t*(s+%d):%c\n",j, *(s+j), i,*(s+i));
                // �ҵ��ظ� -> ����
                break;
            }
            // û���ظ���
            else if(j==strlen(s)-1){
                //������Ϣ
                //printf(" *(s+%d):%c,\t*(s+%d):%c\n",j, *(s+j), i,*(s+i));
                //�жϱ�ʶ
                found = 1;
                printf("\n\t\t�׸����ظ��ַ���%c\n\t\t����λ��Ϊ��%d\n\t\t",*(s+i),i);
            }
        }
        // �ҵ�������
        if(found){
            break;
        }else if(i==strlen(s)-1){
            // û�в��ظ��ַ������ -1
            printf("\n\n\n\n\t\t-1\n\t\t");
        }
    }
    system("pause");
    return 0;
}