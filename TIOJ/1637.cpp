#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

LL a[maxn],st[maxn] ;
LL val[maxn] ;
main()
{
    int n ; scanf("%d",&n) ; n-- ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
    int sz=0 ;
    LL ans=0LL , sum=0LL ;
    for(int i=1;i<=n;i++)
    {
        while(sz && a[st[sz-1]]<=a[i]) sum-=val[sz-1] , sz-- ;
        st[sz++]=i ;
        val[sz-1]= sz==1 ? a[i]*i : a[i]*(i-st[sz-2]) ;
        sum+=val[sz-1] ;
        ans+=sum ;
    }
    printf("%lld\n",ans) ;
}
