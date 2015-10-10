#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=300000+10 , X=137 ;

LL power(LL x,int n)
{
    if(n<=1) return n ? x : 1 ;
    LL t=power(x,n/2) ;
    if(n%2) return (t*t%MOD)*x%MOD ;
    else return t*t%MOD ;
}
LL inv(int x)
{
    return power(x,MOD-2) ;
}

LL bit[2][maxn] ;
void add(int id,int x,LL val)
{
    for(;x<maxn;x+=lowbit(x)) bit[id][x]+=val ;
}
LL query(int id,int l,int r)
{
    LL ret=0 ;
    for(;r;r-=lowbit(r)) ret+=bit[id][r] ;
    for(l=l-1;l;l-=lowbit(l)) ret-=bit[id][l] ;
    ret%=MOD ;
    return ret<0 ? ret+MOD : ret ;
}

LL pw[maxn],ipw[maxn] ;
LL query_hash(int id,int l,int r)
{
    LL tmp=query(id,l,r) ;
    return tmp*ipw[l-1]%MOD ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<=n;i++) pw[i]= i?(pw[i-1]*X%MOD):1 ;
    LL invx=inv(X) ;
    for(int i=0;i<=n;i++) ipw[i]= i?(ipw[i-1]*invx%MOD):1 ;

    for(int i=0;i<n;i++)
    {
        int x ; scanf("%d",&x) ;
        int len=min(x-1,n-x) ;
        if(len && query_hash(0,x-len,x-1)!=query_hash(1,n+1-x-len,n-x))
            {printf("YES\n") ; return 0 ;}
        add(0,x,pw[x-1]) ;
        add(1,n+1-x,pw[n-x]) ;
    }
    printf("NO\n") ;
}
