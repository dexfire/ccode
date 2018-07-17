#include <stdio.h>
int main()
{
    int n, m, i, a, b, c, flag = 0;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        flag = 0;
        int arr[m-n];
        int idx;
        for (i = n; i <= m; i++)
        {
            a = i % 10;
            b = ((i - a) / 10) % 10;
            c = i / 100;
            if (i == (a * a * a + b * b * b + c * c * c))
            {
                flag = 1;
                arr[idx++] = i;
                //printf( i != m ? "%d ": "%d\n", i);
            }
        }
            if (flag == 0)
                printf("no\n");
            else{
                for (int i = 0; i < idx-1; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("%d\n", arr[idx-1]);
            }
    }
    return 0;
}
