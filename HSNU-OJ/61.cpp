#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[100001] ;

LL solve(int n)
{
    if(n<=2) return (LL)a[n] ;
    if(n==3) return (LL)a[1]+a[2]+a[3] ;
    int x=2*a[1]+a[n-1]+a[n] , y=a[1]+2*a[2]+a[n] ;
    return (LL)min(x,y)+solve(n-2) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+n+1) ;
    printf("%lld\n",solve(n)) ;
}
