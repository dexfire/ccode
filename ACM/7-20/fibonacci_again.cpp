#include <stdio.h>
int n;
int f(int x) {
    if (x == 0)
        return 7;
    else if (x == 1)
        return 11;
    int a = 7, b = 11, r;
    for (int i = 2; i <= n; i++) {
        r = a + b;
        a = b;
        b = r;
        b %= 3;
    }
    return b;
}

int main() {
    int fn;
    while (scanf("%d", &n) != EOF) {
        fn = f(n);
        // printf("f(%d)=%d\n", n, fn);
        while (fn > 3)
            fn %= 3;
        if (fn == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
}