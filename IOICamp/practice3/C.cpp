#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

struct P{LL x,y;};

inline P mul(const P &p,const P &q)
{
    LL x=((p.x*q.x)%MOD) + 3*((p.y*q.y)%MOD) ; x%=MOD ;
    LL y= p.x*q.y + p.y*q.x ; y%=MOD ;
    return (P){x,y} ;
}

P power(const P &p,int n)
{
    if(n==0) return ((P){1LL,0LL}) ;
    if(n==1) return p ;
    P tmp=power(p,n/2) ;
    if(n%2) return mul(mul(tmp,tmp),p) ;
    else return mul(tmp,tmp) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        P p=power((P){2LL,1LL},n) ;
        printf("%lld\n",p.y) ;
    }
}
