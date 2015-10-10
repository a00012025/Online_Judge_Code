#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=1000000+10 ;

DB fac[maxn] ;
DB C(int x,int y)
{
    return fac[x]-fac[y]-fac[x-y] ;
}
DB solve(int n,int m)
{
    if(n==1) return 1 ;
    if(m==1) return 1.0/n ;
    DB ans=0 ;
    for(int i=1;i<=m && i<=n;i++)
    {
        DB add=2*log(i)+C(m,i)+C(n*m-m,n-i)-C(n*m,n)-log(n) ;
        ans+=exp(add) ;
    }
    return ans ;
}

main()
{
    fac[0]=0 ;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]+log(i) ;
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF) printf("%.15f\n",solve(n,m)) ;
}
