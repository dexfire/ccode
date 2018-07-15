#include <stdio.h>
#include <math.h>

//  ��ȷ��
unsigned int EFS;
// ���ֺ���
double rectint(double (*f)(double x),double from,double to){
    double result;
    // ΢��x
    double dx = (to - from) / EFS;
    for ( unsigned int i = 0; i < EFS+1;i++){
        // ����
        result += (*f)(from + i * dx) * dx;
    }
    return result;
}

int main(){
    // ���뾫��
    printf("������ָ����(����):");
    scanf("%ld", &EFS);
    // ���������������Ļ���
    printf("��sinxdx @ [0,1] = %lf\n", rectint(sin,0.0f,1.0f));
    printf("��cosxdx @ [-1,1] = %lf\n", rectint(cos,-1.0f,1.0f));
    printf("�ҡ�xdx @ [0,2] = %lf\n", rectint(cos,0.0f,2.0f));
    system("pause");
}