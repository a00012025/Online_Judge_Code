#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

struct P
{
    LL x,y ;
    bool operator < (const P &rhs) const
    {
        return x>rhs.x ;
    }
}a[maxn],b[maxn];

P f[maxn],g[maxn] ;

bool solve(int n,int m)
{
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<m && g[j+1].x<f[i].x) j++ ;
        LL t=(g[j+1].y-g[j].y)/(g[j+1].x-g[j].x) ;
        if(g[j].y + t * (f[i].x-g[j].x) < f[i].y) return 0 ;
    }
    return 1 ;
}

main()
{
    int n,m ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&a[i].x,&a[i].y) ;
    scanf("%d",&m) ;
    for(int i=1;i<=m;i++) scanf("%I64d%I64d",&b[i].x,&b[i].y) ;
    sort(a+1,a+n+1) ;
    sort(b+1,b+m+1) ;

    for(int i=1;i<=n;i++)
        f[i]=(P){f[i-1].x+a[i].y,f[i-1].y+a[i].x*a[i].y} ;
    LL sum=0LL ;
    for(int i=1;i<=m;i++) sum+=b[i].y ;
    for(int i=m;i>=1;i--)
    {
        g[m+1-i].x=b[i].x ;
        g[m+1-i].y=g[m-i].y+(b[i].x-b[i+1].x)*sum ;
        sum-=b[i].y ;
    }
    if(f[n].x > g[m].x) g[m+1]=(P){f[n].x,g[m].y} , m++ ;
    if(solve(n,m)) printf("1\n") ;
    else printf("0\n") ;
}
