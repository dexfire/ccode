#include <cmath>
#include <cstdio>
#define maxn 100005

#define max(a, b) (a > b ? a : b)
int n, k;
int arr[maxn];

int inv() {
    int inversion = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j])
                inversion++;
        }
    }
    return inversion;
}

int main() {
    int inversion;
    while (~scanf("%d%d", &n, &k)) {
        if (!n)
            return 0;
        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);
        inversion = inv();
        printf("%d\n", max(0, inversion - k));
    }
    return 0;
}