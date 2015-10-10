#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=300 ;
bool adj[maxn][maxn] ;
bool visy[maxn] ;
int mx[maxn] , my[maxn] , n,m ; /// X : 0~n-1 , Y : 0~m-1 (bipartite)

bool dfs(int x)
{
    for(int i=0;i<m;i++) if(adj[x][i] && !visy[i])
    {
        visy[i]=1 ;
        if(my[i]==-1 || dfs(my[i]))
        {
            my[i]=x ; mx[x]=i ;
            return 1 ;
        }
    }
    return 0 ;
}

int bipartite_maching()
{
    fill(mx,mx+n,-1) ;
    fill(my,my+m,-1) ;
    int ret=0 ;
    for(int i=0;i<n;i++) if(mx[i]==-1)
    {
        fill(visy,visy+m,0) ;
        if(dfs(i)) ret++ ;
    }
    return ret ;
}

bool check(LL x,LL y)
{
    if(__gcd(x,y)!=1) return 0 ;
    LL z=x*x+y*y ;
    LL sq=(LL)sqrt(z+0.5) ;
    return z==sq*sq || z==(sq-1)*(sq-1) || z==(sq+1)*(sq+1) ;
}

int a[maxn],b[maxn] ;
main()
{
    int N ;
    while(scanf("%d",&N)!=EOF)
    {
        n=m=0 ;
        for(int i=0;i<N;i++)
        {
            int x ; scanf("%d",&x) ;
            if(x%2) a[n++]=x ;
            else b[m++]=x ;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            adj[i][j]=check(a[i],b[j]) ;
        printf("%d\n",bipartite_maching()) ;
    }
}
