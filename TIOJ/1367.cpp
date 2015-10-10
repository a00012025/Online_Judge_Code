#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=50000+10 ;

int a[maxn],b[maxn] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
        for(int i=0;i<n;i++) scanf("%d",&b[i]) ;
        sort(a,a+n) ;
        sort(b,b+n) ;
        LL ans=0LL ;
        for(int i=0;i<n;i++) ans+=a[i]*b[n-1-i] ;
        printf("%lld\n",ans) ;
    }
}
