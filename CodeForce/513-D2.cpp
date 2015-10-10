#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
int n ;
int rma[maxn],rmi[maxn],lma[maxn],ma[maxn],mi[maxn] ;
int now=1 ;
int ans[maxn],cnt=1 ;

bool solve()
{
    mi[now]=max(mi[now],rma[now]) ;
    mi[now]=max(mi[now],lma[now]) ;

    if(ma[now]<mi[now]) return 0 ;
    if(lma[now] >= rmi[now]) return 0 ;
    if(rma[now] > ma[now]) return 0 ;

    int tmp=now ; now++ ;
    if(lma[tmp]>=now)
    {
        ma[now]=min(rmi[tmp]-1,ma[tmp]) ;
        mi[now]=lma[tmp] ;
        if(!solve()) return 0 ;
    }
    ans[cnt++]=tmp ;
    if(now<=mi[tmp])
    {
        ma[now]=ma[tmp] ;
        mi[now]=mi[tmp] ;
        if(!solve()) return 0 ;
    }
    return 1 ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) rma[i]=lma[i]=0 , rmi[i]=n+1 ;
    bool no=0 ;
    while(m--)
    {
        int x,y ; char s[20] ;
        scanf("%d%d%s",&x,&y,s) ;
        if(y<=x) no=1 ;
        if(s[0]=='R')
            rma[x]=max(rma[x],y) ,
            rmi[x]=min(rmi[x],y) ;
        else lma[x]=max(lma[x],y) ;
    }

    ma[1]=mi[1]=n ;
    if(no || !solve()) printf("IMPOSSIBLE\n") ;
    else for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
