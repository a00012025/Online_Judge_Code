#include<bits/stdc++.h>
using namespace std;

bool G[3001][3001] ;
bool vis[3001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        G[x][y]=G[y][x]=1 ;
    }
    int num=n ;
    for(int i=1;i<=n && num>n/3;i++) if(!vis[i])
    {
        for(int j=i+1;j<=n;j++) if(!vis[j] && !G[i][j])
        {
            vis[i]=vis[j]=1 ;
            num-=2 ; break ;
        }
    }
    int cnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        cnt++ ;
        printf("%d%c",i,cnt==n/3?'\n':' ') ;
        if(cnt==n/3) break ;
    }
}
