#include <stdio.h>
#include <stdlib.h>

int main(){
    long x1=1, x2=2,tmp;
    printf("\n\t所求的数列为：\n\n\t\t%ld,%ld",x1,x2);
    long next(long a,long b);
    for (long i = 0; i < 8;i++){
        tmp = x1;
        x1 = x2;
        x2 = next(tmp,x2);
        printf(",%ld", x2);
    }
    printf("\n\n\n\t");
    system("pause");
    return 0;
}

long next(long a,long b){
    return a * b;
}

long next_x(){
    int j = 8;
    while(j--){
        printf(next(x2,next));
    }
    printf();
}