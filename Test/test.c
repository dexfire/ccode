#include <stdio.h>
#include <stdlib.h>

int main(){
    int incre();
    printf("x=%d\n",incre());
    printf("x=%d\n", incre());
    system("pause");
    return 0;
}

int incre(){
    static int x = 20;
    x += 5;
    return x;
}
