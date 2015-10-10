#include<bits/stdc++.h>
using namespace std;

int n,cnt,now[50],ans[50] ;

bool better()
{
    if(ans[1]==-1) return 1 ;
    for(int i=1;i<=n+1;i++) if(ans[i]!=now[i])
        return now[i]>ans[i] ;
    return 0 ;
}

void dfs(int x)
{
    if(x==n+1)
    {
        cnt++ ;
        if(better()) for(int i=1;i<=n+1;i++) ans[i]=now[i] ;
        return ;
    }
    for(int i=1;i<x;i++) if(x%(now[i]+now[i+1])==0)
    {
        for(int j=x+1;j>i+1;j--) now[j]=now[j-1] ;
        now[i+1]=x ;
        dfs(x+1) ;
        for(int j=i+1;j<=x;j++) now[j]=now[j+1] ;
    }
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0 ; ans[1]=-1 ;
        now[1]=0 , now[2]=1 ;
        dfs(2) ;
        printf("%d\n",cnt) ;
        for(int i=1;i<=n+1;i++) printf("%d%c",ans[i],i==n+1?'\n':' ') ;
    }
}
