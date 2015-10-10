#include<bits/stdc++.h>
#define DB double
#define LD long double
using namespace std;
int n ; DB p ; LD logc[500001] ;

LD v1(int x)
{
    LD ret=logc[2*n-x]-logc[n]-logc[n-x] ;
    ret += (n+1)*log(p)+(n-x)*log(1-p) ;
    return exp(ret) ;
}

LD v2(int x)
{
    LD ret=logc[2*n-x]-logc[n]-logc[n-x] ;
    ret += (n+1)*log(1-p)+(n-x)*log(p) ;
    return exp(ret) ;
}

main()
{
    int tc=0 ;
    logc[0]=(LD)0.0 ;
    for(int i=1;i<=400001;i++) logc[i]=logc[i-1]+log((LD)i) ;
    while(scanf("%d%lf",&n,&p)==2)
    {
        DB ans=0.0 ;
        for(int i=1;i<=n;i++) ans+=i*(v1(i)+v2(i)) ;
        printf("Case %d: %.6lf\n",++tc,ans) ;
    }
}
