#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int n,m,head[20001],cost[20001] ;
int next[20001],last[20001],fir,las ;

int solve()
{
    if(n>m) return -1 ;
    fir=1 ; las=m ;
    int ret=0 , now=m ;
    for(int i=1;i<=m;i++) next[i]=i-1 ;
    for(int i=0;i<m;i++) last[i]=i+1 ;
    for(int i=n;i>=1;i--)
    {
        while(now!=0 && cost[now]>=head[i]) now=next[now] ;
        if(now==las) return -1 ;
        now=last[now] ; ret+=cost[now] ;
        if(now==las) {las=next[now] ; now=las ;}
        else
        {
            next[last[now]]=next[now] ;
            last[next[now]]=last[now] ;
            now=last[now] ;
        }

    }
    return ret ;
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        int a;
        for(int i=1;i<=n;i++) scanf("%d",&head[i]) ;
        for(int i=1;i<=m;i++) scanf("%d",&cost[i]) ;
        sort(head+1,head+n+1) ;
        sort(cost+1,cost+m+1) ;
        int ans=solve() ;
        if(ans==-1) printf("Loowater is doomed!\n") ;
        else printf("%d\n",ans) ;
    }
}
