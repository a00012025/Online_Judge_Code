#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+n+1) ;
    LL ans=0LL ;
    for(int i=n,x=0;i>=2;i--) if(a[i-1]>=a[i]-1)
    {
        if(x!=0) ans+=(LL)x*a[i-1] , x=0 , i-- ;
        else x=a[i-1] , i-- ;
    }
    printf("%I64d\n",ans) ;
}
