#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
LL a[maxn] ;
main()
{
    int n,k ;
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
    LL sum=0LL , ans=0LL ;
    for(int i=1;i<=n && k+1>=i;i++)
    {
        sum+=a[i] ;
        if(i==1) { ans=a[i] ; continue ; }
        LL val=sum ;
        int num=k-(i-1) ;
        val+= a[i-1]*((num+1)/2) + a[i]*(num/2) ;
        ans=max(ans,val) ;
    }
    if(n==1) printf("%lld\n",((k+1)/2)*a[1]) ;
    else printf("%lld\n",ans) ;
}
