#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL solve(int x,int n,int k)
{
    if(x>n) return 0LL ;
    int q=k/x ;
    if(q==0) return ((LL)n-x+1)*((LL)k) ;
    int y=min(k/q,n) ;
    return (2*((LL)k)-((LL)q)*((LL)x+y))*((LL)y-x+1)/((LL)2) + solve(y+1,n,k) ;
}

main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF) printf("%lld\n",solve(1,n,k)) ;
}
