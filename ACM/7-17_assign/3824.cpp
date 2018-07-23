#include <stdio.h>
char op[5] = {'#', '+', '-', '*', '/'};
float cal(float x, float y, char op) {
    switch (op) {
    case 1:
        return x + y;
    case 2:
        return x - y;
    case 3:
        return x * y;
    case 4:
        return x / y;
    default:
        return 0.0;
    }
}
float cal1(int i, int j, int k, int t, int op1, int op2, int op3) {
    float r1, r2, r3;
    r1 = cal(i, j, op1);
    r2 = cal(r1, k, op2);
    r3 = cal(r2, t, op3);
    return r3;
}
float cal2(int i, int j, int k, int t, int op1, int op2, int op3) {
    float r1, r2, r3;
    r1 = cal(j, k, op1);
    r2 = cal(i, r1, op2);
    r3 = cal(r2, t, op3);
    return r3;
}
float cal3(int i, int j, int k, int t, int op1, int op2, int op3) {
    float r1, r2, r3;
    r1 = cal(k, t, op1);
    r2 = cal(j, r1, op2);
    r3 = cal(i, r2, op3);
    return r3;
}
float cal4(int i, int j, int k, int t, int op1, int op2, int op3) {
    float r1, r2, r3;
    r1 = cal(j, k, op1);
    r2 = cal(r1, t, op2);
    r3 = cal(i, r2, op3);
    return r3;
}
float cal5(int i, int j, int k, int t, int op1, int op2, int op3) {
    float r1, r2, r3;
    r1 = cal(i, j, op1);
    r2 = cal(k, t, op2);
    r3 = cal(r1, r2, op3);
    return r3;
}
int get24(int i, int j, int k, int t) {
    int op1, op2, op3;
    int flag = 0;
    for (op1 = 1; op1 <= 4; op1++)
        for (op2 = 1; op2 <= 4; op2++)
            for (op3 = 1; op3 <= 4; op3++) {
                if (cal1(i, j, k, t, op1, op2, op3) == 24) {
                    flag = 1;
                    printf("((%d%c%d)%c%d)%c%d=24\n", i, op[op1], j, op[op2], k,
                           op[op3], t);
                }
                if (cal2(i, j, k, t, op1, op2, op3) == 24) {
                    flag = 1;
                    printf("(%d%c(%d%c%d))%c%d=24\n", i, op[op1], j, op[op2], k,
                           op[op3], t);
                }
                if (cal3(i, j, k, t, op1, op2, op3) == 24) {
                    flag = 1;
                    printf("%d%c(%d%c(%d%c%d))=24\n", i, op[op1], j, op[op2], k,
                           op[op3], t);
                }
                if (cal4(i, j, k, t, op1, op2, op3) == 24) {
                    flag = 1;
                    printf("%d%c((%d%c%d)%c%d)=24\n", i, op[op1], j, op[op2], k,
                           op[op3], t);
                }
                if (cal5(i, j, k, t, op1, op2, op3) == 24) {
                    flag = 1;
                    printf("(%d%c%d)%c(%d%c%d)=24\n", i, op[op1], j, op[op2], k,
                           op[op3], t);
                }
            }

    return flag;
}
int main() {
    int i, j, k, t;
    scanf("%d%d%d%d", &i, &j, &k, &t);
    if (get24(i, j, k, t))
        ;
    else
        printf("no result\n");
    return 0;
}
