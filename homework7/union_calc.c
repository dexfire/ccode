#include <stdio.h>
#include <stdlib.h>

// �����嶨��
union num{
    int n1;
    double n2;
} num1, num2;
// ��
double add(union num a,union num b){
    return num1.n1 + num2.n2;
}
// ��
double minus(union num a,union num b){
    return num1.n1 - num2.n2;
}
// ��
double muliply(union num a,union num b){
    return num1.n1 * num2.n2;
}
// ��
double divide(union num a,union num b){
    return num1.n1 / num2.n2;
}

int main(){
    // ��������
    printf("��һ������int����");
    scanf("%d", &num1.n1);
    printf("�ڶ�������double����");
    scanf("%lf", &num2.n2);
    // ����
    printf("\n��������\n�ͣ�%lf��\n�%lf��\n����%lf��\n�̣�%lf\n\n", add(num1,num2),minus(num1,num2),muliply(num1,num2),divide(num1,num2));
    system("pause");
    return 0;
}