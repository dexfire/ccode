#include <iostream>
#include <conio.h>

int main(int argc, char** argv){
    double weight;
    printf("\n\n\n\t\t\t������Ҫ�ʼĵ���Ʒ���� [��λkg]��");
    scanf("%lf", &weight);
    if(weight<0){
        printf("\n\n\n\t\t\tem... ��������Ϊ����Ŷ��");
    }else if(weight>0&&weight<=10){
        printf("\n\n\n\t\t\t�ܹ�����ȡ%.2lfԪ����ϸ���£�", weight * 0.8 + 0.2);
        printf("\n\n\n\t\t\t\t\t\t�����ѣ���0.2");
        printf("\n\n\n\t\t\t\t\t\t���طѣ���%.2lf",weight*0.8);
        printf("\n\n\n\t\t\t\t\t\t====================");
        printf("\n\n\n\t\t\t\t\t\t�ϼƣ���%.2lf",weight * 0.8 + 0.2);
    }else if(weight>10&&weight<=20){
        printf("\n\n\n\t\t\t�ܹ�����ȡ%.2lfԪ����ϸ���£�", (weight-10)*0.75+10 * 0.8 + 0.2);
        printf("\n\n\n\t\t\t\t\t\t�����ѣ���0.2");
        printf("\n\n\n\t\t\t\t\t\t���طѣ���%.2lf",10*0.8);
        printf("\n\n\n\t\t\t\t\t\t���طѣ���%.2lf",(weight-10)*0.75);
        printf("\n\n\n\t\t\t\t\t\t====================");
        printf("\n\n\n\t\t\t\t\t\t�ϼƣ���%.2lf", (weight-10)*0.75+10 * 0.8 + 0.2);
    }else if(weight<=30){
        printf("\n\n\n\t\t\t�ܹ�����ȡ%.2lfԪ����ϸ���£�", (weight-20)*0.7+10*0.75+10 + 0.2);
        printf("\n\n\n\t\t\t\t\t\t�����ѣ���0.2");
        printf("\n\n\n\t\t\t\t\t\t���طѣ���%.2lf",10*0.8);
        printf("\n\n\n\t\t\t\t\t\t���طѣ���%.2lf", weight-20*0.7+10*0.75);
        printf("\n\n\n\t\t\t\t\t\t====================");
        printf("\n\n\n\t\t\t\t\t\t�ϼƣ���%.2lf", (weight-20)*0.7+10*0.75+10 + 0.2);
    }else{
        printf("Fail");
    }
    getch();
}
