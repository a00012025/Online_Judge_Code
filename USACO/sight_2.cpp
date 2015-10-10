#include<bits/stdc++.h>
#define LL long long
#define DB double
#define pii pair<DB,DB>
#define F first
#define S second
using namespace std;
const int maxn=50000+10 ;
const DB PI=2*acos(0.0) ;

pii p[2*maxn] ;
main()
{
    freopen("sight.in","r",stdin) ;
    freopen("sight.out","w",stdout) ;
    int n ; DB r ; scanf("%d%lf",&n,&r) ;
    for(int i=1;i<=n;i++)
    {
        DB x,y ; scanf("%lf%lf",&x,&y) ;
        DB a=atan2(y,x) , b=acos(r/sqrt(x*x+y*y)) ;
        if(a-b<0) a+=2*PI ;
        p[i]=(pii){a-b,a+b} ;
    }

    sort(p+1,p+n+1) ;
    for(int i=1;i<=n;i++) p[i+n]=(pii){p[i].F+2*PI,p[i].S+2*PI} ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
        ans+=lower_bound(p+1,p+2*n+1,(pii){p[i].S,p[i].S})-p-i-1 ;

    printf("%d\n",ans) ;
}
