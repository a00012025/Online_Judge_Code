#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=100+2 ;
struct mat
{
    LL a[maxn][maxn] ;
    int n,m ;
    mat(int _n,int _m)
    {
        n=_n ; m=_m ;
        memset(a,0,sizeof(a)) ;
    }
};

mat mul(const mat &p,const mat &q)
{
    mat r(p.n,q.m) ;
    for(int i=1;i<=p.n;i++) for(int j=1;j<=q.m;j++)
        for(int k=1;k<=p.m;k++)
        r.a[i][j]=(r.a[i][j]+p.a[i][k]*q.a[k][j])%MOD ;
    return r ;
}

int num[maxn] ;
LL d[maxn] ;
main()
{
    int n,x ; scanf("%d%d",&n,&x) ;
    while(n--)
    {
        int y ; scanf("%d",&y) ;
        num[y]++ ;
    }

    d[0]=1 ;
    for(int i=1;i<maxn;i++)
    {
        d[i]=1 ;
        for(int j=1;j<=i;j++) d[i]=(d[i]+num[j]*d[i-j])%MOD ;
    }

    if(x<=100) {printf("%I64d\n",d[x]) ; return 0 ;}
    mat p(101,101) , q(101,1) ;
    for(int i=1;i<=100;i++) p.a[1][i]=num[i] ;
    for(int i=2;i<=100;i++) p.a[i][i-1]=1 ;
    for(int i=1;i<=100;i++) q.a[i][1]=d[101-i] ;
    q.a[101][1]=1 ;
    p.a[101][101]=1 ;
    p.a[1][101]=1 ;

    for(int y=x-100;y;y/=2)
    {
        if(y&1) q=mul(p,q) ;
        p=mul(p,p) ;
    }
    printf("%I64d\n",q.a[1][1]) ;
}
