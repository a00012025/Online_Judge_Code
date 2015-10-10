#include<bits/stdc++.h>
#define LL long long
using namespace std;
int MOD ;

struct mat
{
    int n,m ; LL a[2][2] ;
    mat(int _n,int _m){n=_n , m=_m ; memset(a,0,sizeof(a)) ;}
};

mat operator * (const mat &p,const mat &q)
{
    mat r(p.n,q.m) ;
    for(int i=0;i<p.n;i++) for(int j=0;j<q.m;j++)
        for(int k=0;k<p.m;k++)
        r.a[i][j]+=p.a[i][k]*q.a[k][j] ,
        r.a[i][j]%=MOD ;
    return r ;
}

LL power(LL x,LL n)
{
    if(n<=1) return n ? x : 1LL ;
    LL t=power(x,n/2) ;
    if(n%2) return (t*t%MOD)*x%MOD ;
    else return t*t%MOD ;
}

main()
{
    LL n,k ; int l ;
    scanf("%I64d%I64d%d%d",&n,&k,&l,&MOD) ;
    for(int i=l;i<63;i++) if(k&(1LL<<i)){printf("0\n") ; return 0 ;}
    mat p(2,2) , q(2,1) ;
    p.a[0][0]=p.a[1][0]=p.a[0][1]=1 ;
    q.a[0][0]=2 , q.a[1][0]=1 ;
    for(LL n2=n-1;n2;n2/=2)
    {
        if(n2%2) q=p*q ;
        p=p*p ;
    }
    LL x=q.a[0][0] , y=(power(2,n)-x)%MOD , ans=1%MOD ;
    if(y<0) y+=MOD ;
    for(int i=0;i<l;i++)
        ans*=((k&(1LL<<i)) ? y : x) , ans%=MOD ;
    printf("%I64d\n",ans) ;
}
