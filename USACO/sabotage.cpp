#include<bits/stdc++.h>
#define DB double
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[2*maxn] ;
int s[2*maxn] ;
main()
{
    if(fopen("sabotage.in","r"))
    {
        freopen("sabotage.in","r",stdin) ;
        freopen("sabotage.out","w",stdout) ;
    }
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        a[i]=a[i-1]+x ;
    }
    for(int i=n+1;i<2*n;i++) a[i]=a[n]+a[i-n] ;

    DB ans=1e6 ;
    int sz=0 ;
    for(int i=2*n-2,j=0;i>=n+1;i--)
    {
        while(sz>=2 && (LL)(s[sz-2]-s[sz-1])*(a[s[sz-1]]-a[i-n+1])
              <= (LL)(a[s[sz-2]]-a[s[sz-1]])*(s[sz-1]-(i-n+1)))
            sz-- ;
        s[sz++]=i-n+1 ;
        j=min(j+1,sz-1) ;
        while(j && (LL)(i-s[j-1])*(a[i]-a[s[j]])
                >= (LL)(a[i]-a[s[j-1]])*(i-s[j]))
            j-- , sz-- ;
        ans=min(ans, ((DB)a[i]-a[s[j]])/((DB)i-s[j]) ) ;
    }
    printf("%.3f\n",ans) ;
}
