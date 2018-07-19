#include<stdio.h>
#include<iostream>
using namespace std;
char a[102][102];
int n,m;
const char w='W';
const char d='.';
void A(int n,int m)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j];
	for(int i=0;i<=m+1;i++)
	{
		a[0][i]=d;
		a[n+1][i]=d;
	}
	for(int j=1;j<=n;j++)
	{
		a[j][0]=d;
		a[j][m+1]=d;
	}
}
bool dfs(int x,int y)
{
	if(a[x][y]==w)
	{
		a[x][y]=d;
		for(int i=y-1;i<=y+1;i++)
		{
			dfs(x-1,i);
			dfs(x+1,i);
		}
		dfs(x,y-1);
		dfs(x,y+1);
		return true;
	}
	return false;
}
int main()
{
	while(std::cin>>n>>m)
	{
	A(n,m);
	int count=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(dfs(i,j))
		count++;
	}
	cout<<count<<endl;
	}
	
	return 0;
}
