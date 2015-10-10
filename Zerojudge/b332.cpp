#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=5000000+10 ;
LL a[maxn],b[maxn],c[maxn] ;

main()
{
    int n ; LL p ;
    scanf("%d%lld",&n,&p) ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
    LL M,m=0LL,now=0LL ;
    for(int i=1;i<=n;i++)
    {
        now+=a[i] ;
        b[i]= i==1 ? a[1] : max(b[i-1],now) ;
        now=max(now,0LL) ;
    }
    LL ans ;
    for(int i=1;i<=n;i++)
    {
        if(i==1) c[i]=b[i] , M=b[i]+c[i] , ans=c[i] ;
        else c[i]=M , M=max(M,b[i]+c[i]) , ans=max(ans,c[i]) ;
    }
    printf("%lld\n",ans%p) ;
}
