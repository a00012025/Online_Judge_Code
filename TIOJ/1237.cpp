#include<bits/stdc++.h>
#define LL long long
#define INF 2147483647
using namespace std;
const int maxn=2000000+10 ;

int n,a[maxn] ;

bool check(int x)
{
    int fir=-1,last=-1 ;
    for(int i=0;i<n;i++) if(a[i]>=x)
    {
        if(fir==-1) { fir=last=i ; continue ; }
        if(i-last >= (n+1)/2) return 0 ;
        last=i ;
    }
    if( fir-last+n >= (n+1)/2 ) return 0 ;
    return 1 ;
}

main()
{
    scanf("%d",&n) ;
    int l=INF , r=0 ;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]) ,
        l=min(l,a[i]) , r=max(r,a[i]) ;
    r++ ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(check(mid)) l=mid ;
        else r=mid ;
    }
    LL ans=0LL ;
    for(int i=0;i<n;i++) ans+=max(0LL,(LL)a[i]-l) ;
    printf("%lld\n",ans) ;
}
