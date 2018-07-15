#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int nmax=7,mmax=7;
bool maze[nmax][mmax];
int m,n,t;
int sx,sy,dx,dy;
bool victory;
int wall;

void DFS(int n,int x,int y)
{
    int check=t-n-abs(x-dx)-abs(y-dy);
    if(check < 0 || (check&1))
        return;
    
    if(victory==1 || !maze[x][y])
        return;
    else if(x==dx && y==dy && n==t)
        victory=1;
    else if(n==t)
        return;
    
    maze[x][y]=0;
    if(x<n) DFS(n+1,x+1,y);
    if(y<m) DFS(n+1,x,y+1);
    if(x!=0)DFS(n+1,x-1,y);
    if(y!=0)DFS(n+1,x,y-1);
    maze[x][y]=1;
}

int main()
{
    ios::sync_with_stdio(false);
//    freopen("/Users/fromfire/Desktop/acm/ACM/in.txt", "r", stdin);
    
    while(cin >> n >> m >> t && n)
    {
        //initialize
        victory=0;wall=0;
        
        //input
        char temp;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> temp;
                switch(temp)
                {
                    case 'X':   maze[i][j]=0;   wall++; break;
                    case '.':   maze[i][j]=1;   break;
                    case 'S':   maze[i][j]=1;   sx=i;   sy=j;   break;
                    case 'D':   maze[i][j]=1;   dx=i;   dy=j;   break;
                }
            }
        
        if(t>n*m-wall-1)
        {
            cout << "NO" << endl;
            continue;
        }
        
        DFS(0,sx,sy);
        if(victory)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
