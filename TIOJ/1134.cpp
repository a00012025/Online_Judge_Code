#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

struct P{int id,val ;};
bool operator < (const int &a,const P &p)
{
    return a>p.val ;
}

int a[maxn][maxn],s[maxn][maxn] ;
int b[maxn] ;
P st[maxn] ;

int solve(int n)
{
    for(int i=1;i<=n;i++) b[i]+=b[i-1] ;
    int sz=1,ret=0 ;
    st[0]=(P){0,0} ;
    for(int i=1;i<=n;i++)
    {
        int id=upper_bound(st,st+sz,b[i])-st ;
        if(id!=sz) ret=max(ret,i-st[id].id) ;
        if(b[i]<st[sz-1].val) st[sz++]=(P){i,b[i]} ;
    }
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]) ;
            a[i][j]=1-2*a[i][j] ;
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j] ;
        }
        int ans=0 ;
        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
                b[k]=s[j][k]-s[j][k-1]-s[i-1][k]+s[i-1][k-1] ;
            ans=max(ans,(j-i+1)*solve(m)) ;
        }
        printf("%d\n",ans) ;
    }
}
