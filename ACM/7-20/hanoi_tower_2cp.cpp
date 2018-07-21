#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 99999999;

int f[65];

void Init() {
    f[1] = 1;
    f[2] = 3;
    for (int i = 3; i < 65; i++) {
        int minx = INF;
        for (int x = 1; x < i; x++)
            if (2 * f[x] + pow(2.0, i - x) - 1 < minx)
                minx = 2 * f[x] + pow(2.0, i - x) - 1;

        /*写成下面这样就错了,估计是tmp溢出了
        for(int x=1;x<i;x++){
            int tmp=2*f[x]+pow(2.0,i-x)-1;
            if(tmp<minx)
                minx=tmp;
        }
        */
        f[i] = minx;
    }
}

int main() {

    // freopen("input.txt","r",stdin);

    int n;
    Init();
    while (~scanf("%d", &n)) {
        printf("%d\n", f[n]);
    }
    return 0;
}