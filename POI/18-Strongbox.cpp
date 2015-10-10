#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=250000+10 ;

LL getll()
{
    char c=getchar() ;
    while(c<'0'||c>'9') c=getchar() ;
    LL x=0 ;
    while(1)
    {
        x=x*10+c-'0' ;
        c=getchar() ;
        if(c<'0'||c>'9') return x ;
    }
}

int dcnt=0 ;
LL di[maxn] ;

void get_div(LL val)
{
    LL x=(LL)sqrt(val+0.5) ;
    for(int i=1;i<=x;i++) if(val%i==0)
        di[dcnt++]=i , di[dcnt++]=val/i ;
    sort(di,di+dcnt) ;
    return ;
}

LL a[maxn],v[maxn] ;
int vcnt=0 ;
main()
{
    LL n ; int k ;
    scanf("%lld%d",&n,&k) ;
    for(int i=1;i<=k;i++) a[i]=getll() ;

    LL val=__gcd(n,a[k]) ;
    get_div(val) ;

    for(int i=1;i<k;i++) v[vcnt++]=__gcd(val,a[i]) ;
    sort(v,v+vcnt) ;
    vcnt = unique(v,v+vcnt)-v ;

    for(int i=0;i<dcnt;i++)
    {
        bool ok=1 ;
        for(int j=0;j<vcnt;j++) if(v[j]%di[i]==0)
            { ok=0 ; break ; }
        if(ok) { printf("%lld\n",n/di[i]) ; return 0 ; }
    }
}
