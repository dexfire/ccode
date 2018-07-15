#include <iostream>
#include <math.h>
#include <conio.h>

double mysqrt(double,unsigned int*);

int main(){
    double a;
    scanf("%lf", &a);
    unsigned int counter = 0;
    printf("input = %lf\nmath.h::sqrt(): %lf\nmysqrt(): %lf£¬µü´úÁË%u´Î¡£\nÎó²î£º%lf", 
    a,sqrt(a) ,mysqrt(a, &counter),counter,sqrt(a)-mysqrt(a,&counter));
    getch();
}

double mysqrt(double a,unsigned int * counter){
    double sqrtx(double, double);
    const float ESP = 1e-5;
    double x0 = sqrtx(a, a/2);
    double tmp;
    *counter = 0;
    while(fabs((tmp=sqrtx(a, x0))-x0)>=ESP){
        x0 = tmp;
        (*counter)++;
    }
    return x0;
}

double sqrtx(double a,double x0){
    return 0.5 * (x0 + a / x0);
}