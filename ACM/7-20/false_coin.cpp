#include <conio.h>
#include <iostream>
#include <stdio.h>

const int MAXN = 1005;
int LP[MAXN / 2];
int RP[MAXN / 2];
int COINS[MAXN];
int N, K;
int p;

template <class T> void print(T arr, int offset, int count) {
    for (int i = offset; i < offset + count; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void remove(int a[], int size) {
    for (int i = 0; i < size; i++) {
        COINS[a[i]] = 0;
    }
}

int main() {
    while (scanf("%d%d", &N, &K) != EOF) {
        for (int i = 1; i < N + 1; i++) {
            COINS[i] = i + 1;
        }
        // for (int k = 0; k < K; k++) {
        // }

        for (int k = 0; k < K; k++) {

            scanf("%d", &p);
            int idx = 0;
            for (int j = 0; j < p; j++) {
                scanf("%d", &LP[idx++]);
            }
            idx = 0;
            print(LP, 0, p);
            for (int j = 0; j < p; j++) {
                scanf("%d", &RP[idx++]);
            }
            print(RP, 0, p);
            // getch() 干掉那个换行
            // _getch();
            // char ch = _getch();
            char ch;
            scanf("%c", &ch);
            switch (ch) {
            case '<':
                remove(LP, p);
                break;
            case '>':
                remove(RP, p);
                break;
            case '=':
                remove(LP, p);
                remove(RP, p);
                break;
            }
        }
        // 输出序列
        bool flag = false;
        for (int i = 1; i < N + 1; i++) {
            if (COINS[i] != 0) {
                printf("%d\n", COINS[i]);
                flag = true;
            }
        }
        // 没有结果输出0
        if (!flag)
            printf("0\n");
    }
    return 0;
}