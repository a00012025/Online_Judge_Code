#include<bits/stdc++.h>
using namespace std;

int d[50][50][50][50] ;

int dp(int n,int m,int x,int y)
{
    if(n==1 && m==1) return 0 ;
    if(d[n][m][x][y]!=-1) return d[n][m][x][y] ;
    int &ans=d[n][m][x][y] ;
    for(int i=x;i<n;i++) if(!dp(i,m,x,y)) return ans=1 ;
    for(int i=y;i<m;i++) if(!dp(n,i,x,y)) return ans=1 ;
    for(int i=1;i<x;i++) if(!dp(n-i,m,x-i,y)) return ans=1 ;
    for(int i=1;i<y;i++) if(!dp(n,m-i,x,y-i)) return ans=1 ;
    return ans=0 ;
}

main()
{
    memset(d,-1,sizeof(d)) ;
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%c",dp(n,m,i,j)?'.':'X') ;
            printf("\n") ;
        }
    }
}
