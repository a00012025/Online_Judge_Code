#include<bits/stdc++.h>
#define DB long double
using namespace std;
const int maxn=100000+10 ;

DB fac[maxn] ;
inline DB C(int x,int y)
{
    return fac[x]-fac[y]-fac[x-y] ;
}

main()
{
    fac[0]=0 ;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]+log(i) ;
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    DB ans=0 ;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++)
    {
        int t=n*(i+j)-i*j ;
        if(t>k) break ;
        DB add=C(m-t,k-t)+C(n,i)+C(n,j)-C(m,k) ;
        ans+=exp(add) ;
    }
    if(ans>1e99){printf("1e99\n") ; return 0 ;}
    double ans2=ans ;
    printf("%.15f\n",ans2) ;
}
