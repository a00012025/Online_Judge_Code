#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int n ; LL k ;
    scanf("%d%lld",&n,&k) ;
    int ans=0 ;
    LL now=k ;
    for(int i=1;i<=n;i++)
    {
        LL x ; scanf("%lld",&x) ;
        if(x>=k) { printf("-1\n") ; return 0 ; }
        if(x<now) now-=x ;
        else now=k-x , ans++ ;
    }
    printf("%d\n",ans) ;
}
