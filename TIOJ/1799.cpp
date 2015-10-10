#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=5000000+10 ;
LL a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    LL sum=0LL ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) , sum+=a[i] ;
    sum/=n ;
    for(int i=1;i<=n;i++) a[i]=a[i]-sum+a[i-1] ;
    sort(a+1,a+n+1) ;
    LL ans=0LL , mid=a[(n+1)/2] ;
    for(int i=1;i<=n;i++) ans+= a[i]>=mid ? a[i]-mid : mid-a[i] ;
    printf("%lld\n",ans) ;
}
