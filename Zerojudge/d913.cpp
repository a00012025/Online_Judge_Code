#include<bits/stdc++.h>
using namespace std;

int a[10][10],num[10] ;
int now[10] ;

bool check()
{
    for(int i=1;i<=6;i++)
    {
        int yes=0 ;
        for(int j=1;j<=6;j++) if(now[j]==a[i][j]) yes++ ;
        if(num[i]!=yes) return 0 ;
    }
    return 1 ;
}

bool vis[10] ;
bool dfs(int num)
{
    if(num==6)
    {
        if(check())
        {
            for(int i=1;i<=6;i++) printf("%d%c",now[i],i==6?'\n':' ') ;
            return 1 ;
        }
        return 0 ;
    }
    for(int i=1;i<=6;i++) if(!vis[i])
    {
        now[num+1]=i ; vis[i]=1 ;
        if(dfs(num+1)) return 1 ;
        vis[i]=0 ;
    }
    return 0 ;
}

main()
{
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++) scanf("%d",&a[i][j]) ;
        scanf("%d",&num[i]) ;
    }
    memset(vis,0,sizeof(vis)) ;
    dfs(0) ;
}
