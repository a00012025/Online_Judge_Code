#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+10 ;

struct P
{
    int c,add,p ;
    bool operator < (const P &rhs) const
    {
        return c==rhs.c ? add>rhs.add : c<rhs.c ;
    }
}a[maxn];

int dp[maxn] ;
main()
{
    int n,c,m ; scanf("%d%d%d",&n,&c,&m) ;
    int n2=0 ;
    for(int i=1;i<=n;i++)
    {
        int x,y,z ; scanf("%d%d%d",&x,&y,&z) ;
        if(y<=x) continue ;
        n2++ ;
        a[n2]=(P){x,y-x,z} ;
    }
    n=n2 ;
    sort(a+1,a+n2+1) ;
    for(int i=1;i<=m;i++) dp[i]=c ;
    for(int i=1;i<=n;i++) for(int j=m;j>a[i].p;j--)
        if(dp[j-a[i].p]>a[i].c)
            dp[j]=max(dp[j],dp[j-a[i].p]+a[i].add) ;
    printf("%d\n",dp[m]) ;
}
