#include <stdio.h>
#include <math.h>

//  精确度
unsigned int EFS;
// 积分函数
double rectint(double (*f)(double x),double from,double to){
    double result;
    // 微分x
    double dx = (to - from) / EFS;
    for ( unsigned int i = 0; i < EFS+1;i++){
        // 积分
        result += (*f)(from + i * dx) * dx;
    }
    return result;
}

int main(){
    // 输入精度
    printf("请输入分割份数(精度):");
    scanf("%ld", &EFS);
    // 依次求三个函数的积分
    printf("∫sinxdx @ [0,1] = %lf\n", rectint(sin,0.0f,1.0f));
    printf("∫cosxdx @ [-1,1] = %lf\n", rectint(cos,-1.0f,1.0f));
    printf("∫√xdx @ [0,2] = %lf\n", rectint(cos,0.0f,2.0f));
    system("pause");
}