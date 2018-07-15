#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fan(int m);
    printf("\n\n\n\t\t请输入一个整数：");
    int m;
    scanf("%d", &m);                                                                                                                    // 输入数字
    printf("\n\n\t\t各位数字之和为：%d\n\n\n\n\n\t\t", fan(m));
    system("pause");
}

/**
 *         函数签名： int fan( int m ) 
 *         对参数m的各位求和，并返回求和值。
 **/
int fan(int m)
{
    int sum = 0;
    while ( m >= 10)
    {
        sum += m % 10;                                                                                                                // 统计值 加上 现在的个位数值
        m /= 10;                                                                                                                            // 数值除以十，相当于移位【舍弃低位】
    }
    return sum+m;                                                                                                                      // 加上最终的个位数值
}