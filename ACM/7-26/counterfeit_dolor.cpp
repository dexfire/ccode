#include <cstdio>
#include <cstring>
//#include <iostream>
int n;
struct cmp {
    char left[4];
    char right[4];
    bool real;
} weigh[3];

char find_fake(int id_fake) {
    // 比较
    for (int i = 0; i < 3; i++) { //从假币那组数据中去除所有真币
        if (i == id_fake)
            continue;
        for (int a = 0; a < 4; a++) {
            for (int c = 0; c < 4; c++) {
                if (weigh[id_fake].left[a] == weigh[i].left[c])
                    weigh[id_fake].left[a] = ' ';
                if (weigh[id_fake].left[a] == weigh[i].right[c])
                    weigh[id_fake].left[a] = ' ';
                if (weigh[id_fake].right[a] == weigh[i].left[c])
                    weigh[id_fake].right[a] = ' ';
                if (weigh[id_fake].right[a] == weigh[i].right[c])
                    weigh[id_fake].right[a] = ' ';
            }
        }
    }
    for (int a = 0; a < 4; a++) {
        if (weigh[id_fake].left[a] != ' ')
            return weigh[id_fake].left[a];
        if (weigh[id_fake].right[a] != ' ')
            return weigh[id_fake].right[a];
    }
    return ' ';
}
int main() {
    // freopen("counterfeit_dolor.txt", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        getchar();
        int idxFake;
        for (int t = 0; t < 3; t++) {
            for (int s = 0; s < 4; s++)
                scanf("%c", &(weigh[t].left[s]));
            getchar();
            for (int s = 0; s < 4; s++)
                scanf("%c", &(weigh[t].right[s]));
            getchar();
            char result[5];
            gets(result);
            if (strcmp(result, "even ") == 0 || strcmp(result, "even") == 0)
                weigh[t].real = true;
            else {
                weigh[t].real = false;
                idxFake = t;
            }
        }
        printf("%c\n", find_fake(idxFake));
    }
    return 0;
}