#include<bits/stdc++.h>
#define DB long double
using namespace std;
const int maxn=100000+10 ;

int a[maxn],v[maxn] ;
int n ;

DB cal(DB x)
{
    DB M,m ;
    for(int i=1;i<=n;i++)
    {
        if(i==1) M=m=a[i]+x*v[i] ;
        else M=max(M,a[i]+x*v[i]) , m=min(m,a[i]+x*v[i]) ;
    }
    return M-m ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&a[i]) ;

    DB l=0.0 , r=1e10 ;
    while(r-l>1e-5)
    {
        DB l2=(2*l+r)/3 , r2=(2*r+l)/3 ;
        DB d1,d2,d3,d4 ;
        d1=cal(l) , d2=cal(l2) ;
        d3=cal(r2) , d4=cal(r) ;
        if(d2<=d3 && d3<=d4) r=r2 ;
        else l=l2 ;
    }
    assert(cal(l)<=cal(l+1.0)) ;
    assert(cal(l)<=cal(l-1.0)) ;
    int x=int(r*100) ;
    double ans=min(cal(x/100.0),cal((x+1)/100.0)) ;
    if(x>=1) ans=min((DB)ans,cal((x-1)/100.0)) ;
    printf("%.2f\n",ans+1e-7) ;
}
