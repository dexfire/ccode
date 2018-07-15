#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	printf("\n\n\n\t\t\t\t杨辉三角生成器\n");
	printf("\n\n\t\t请输入要生成的行数(1 ~ 1000)：");
	int n=5;
	scanf("%d",&n);
	long tri[500][500];
	tri[0][0]=1;
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<i;j++){
			if(i!=0 && j==0) tri[i][j] = tri[i-1][j];
				else tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
			printf("\t%ld",tri[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\t\t");
	system("pause");
	return 0;
}

