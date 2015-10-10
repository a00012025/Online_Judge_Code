#include<bits/stdc++.h>
#define INF 1100000000
using namespace std;
const int maxn=1000+10 , maxq=1000000+10 , maxc=100000+10 ;

struct P
{
    int l,r,c,id;
    bool operator < (const P &rhs) const
    {
        return l==rhs.l ? r<rhs.r : l<rhs.l ;
    }
}a[maxn],q[maxq] ;

int dp[maxc] ;
bool ans[maxq] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].c,&a[i].l,&a[i].r) ;
    int Q ; scanf("%d",&Q) ;
    for(int i=1;i<=Q;i++)
        scanf("%d%d%d",&q[i].l,&q[i].c,&q[i].r) ,
        q[i].id=i ,
        q[i].r+=q[i].l+1 ;

    sort(a+1,a+n+1) ; sort(q+1,q+Q+1) ;
    dp[0]=INF ;
    for(int i=1,j=1;i<=Q;i++)
    {
        while(j<=n && a[j].l <= q[i].l)
        {
            for(int k=maxc-1;k>=a[j].c;k--)
                dp[k]=max(dp[k],min(dp[k-a[j].c],a[j].r)) ;
            j++ ;
        }
        ans[q[i].id]= (q[i].r<=dp[q[i].c] ? 1 : 0) ;
    }
    for(int i=1;i<=Q;i++) printf("%s\n",ans[i]?"TAK":"NIE") ;
}
