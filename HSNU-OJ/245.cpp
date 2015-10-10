#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
LL a,b ;
main()
{
    int n ; scanf("%d",&n) ;
    a=0LL ;
    LL up=INF , dn=-INF ;

    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        b=2*x-a ;
        if(i%2) dn=max(dn,a-b) ;
        else up=min(up,b-a) ;
        a=b ;
    }

    if(dn%2) dn++ ;
    if(up%2) up-- ;
    printf("%lld\n",max(0LL,(up-dn+2)/2)) ;
}
