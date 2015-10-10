#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std ;
const int maxn=100+10 ;
int n ;
LL adj[maxn][maxn] ;
LL vx[maxn],vy[maxn] ;
int mx[maxn],my[maxn] ;
bool visx[maxn],visy[maxn] ;

bool dfs(int x)
{
    visx[x]=1 ;
    for(int i=1;i<=n;i++) if(!visy[i] && vx[x]+vy[i]==adj[x][i])
    {
        visy[i]=1 ;
        if(my[i]==-1 || dfs(my[i]))
        {
            my[i]=x ;
            mx[x]=i ;
            return 1 ;
        }
    }
    return 0 ;
}

void update()
{
    LL a=INF ;
    for(int i=1;i<=n;i++) if(visx[i])
        for(int j=1;j<=n;j++) if(!visy[j])
        a=min(a,vx[i]+vy[j]-adj[i][j]) ;

    for(int i=1;i<=n;i++)
    {
        if(visx[i]) vx[i]-=a ;
        if(visy[i]) vy[i]+=a ;
    }
}

LL t1[maxn],t2[maxn] ;
main()
{
    LL d,r ;
    while(scanf("%d%lld%lld",&n,&d,&r)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%lld",&t1[i]) ;
        for(int i=1;i<=n;i++) scanf("%lld",&t2[i]) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            adj[i][j]= min(0LL,((LL)d-t1[i]-t2[j])*r) ;
        for(int i=1;i<=n;i++)
        {
            vx[i]=0 ;
            LL M=adj[1][i] ;
            for(int j=1;j<=n;j++) M=max(M,adj[j][i]) ;
            vy[i]=M ;
        }
        memset(mx,-1,sizeof(mx)) ;
        memset(my,-1,sizeof(my)) ;
        for(int i=1;i<=n;i++)
        {
            while(1)
            {
                memset(visx,0,sizeof(visx)) ;
                memset(visy,0,sizeof(visy)) ;
                if(!dfs(i)) update() ;
                else break ;
            }
        }
        LL ans=0 ;
        for(int i=1;i<=n;i++) ans+=adj[i][mx[i]] ;
        printf("%lld\n",-ans) ;
    }
}
