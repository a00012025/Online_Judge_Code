#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        LL n,m ; scanf("%lld%lld",&n,&m) ;
        m=((m+1)/2)*((m+1)/2) ;
        if(n!=2 && n!=m-2 && n<=m) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
