#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *text = fopen("����.txt", "w+");
    char ch,flag=0;
    // ѭ����ȡ��׼����
    while(1){
        ch = getchar();
        //��\nֱ�����
        if(ch!='\n'){           
            fputc(ch, text);
            //������һ���ǻ��з������ʶflag
            if(flag)
                flag = 0;
        // �ϴβ���\n����������ñ�ʶflag
        }else if(!flag){
            flag = 1;
            fputc(ch, text);
        // ����������У�����
        }else{
            break;
        }
    }
    system("pause");
}

