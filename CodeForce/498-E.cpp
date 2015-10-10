#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=7 ;

struct mat
{
    int n,m ;
    int a[(1<<maxn)+1][(1<<maxn)+1] ;
    mat(){}
    mat(int _n,int _m)
    {
        memset(a,0,sizeof(a)) ;
        n=_n , m=_m ;
    }
};

mat mul(const mat &p,const mat &q)
{
    mat r(p.n,q.m) ;
    for(int i=0;i<p.n;i++) for(int j=0;j<q.m;j++)
        for(int k=0;k<p.m;k++)
        r.a[i][j]+=(LL)p.a[i][k]*q.a[k][j]%MOD ,
        r.a[i][j]%=MOD ;
    return r ;
}

mat pow(const mat &p,int x)
{
    mat q=p , r(p.n,p.n) ;
    for(int i=0;i<p.n;i++) r.a[i][i]=1 ;
    while(x)
    {
        if(x&1) r=mul(q,r) ;
        x>>=1 ;
        q=mul(q,q) ;
    }
    return r ;
}

bool check(int S1,int S2,int S,int x)
{
    S=2*S+1 ; S|=(1<<x) ;
    for(int i=0;i<x;i++)
        if((S1&(1<<i)) && (S2&(1<<i)) &&
           (S&(1<<i)) && (S&(1<<(i+1))))
        return 0 ;
    return 1 ;
}

mat M[maxn+5] ;
void cal_mat()
{
    for(int i=1;i<=7;i++)
    {
        M[i].n=M[i].m=(1<<i) ;
        for(int j=0;j<(1<<i);j++) for(int k=0;k<(1<<i);k++)
        {
            int &ans=M[i].a[k][j] ; ans=0 ;
            for(int S=0;S<(1<<(i-1));S++)
                if(check(j,k,S,i)) ans++ ;
        }
    }
}

int a[maxn+5] ;
main()
{
    cal_mat() ;
    for(int i=1;i<=7;i++) scanf("%d",&a[i]) ;

    mat now ;
    int fir=1 ; while(!a[fir]) fir++ ;
    now.n=(1<<fir) ; now.m=1 ;
    now.a[(1<<fir)-1][0]=1 ;

    for(int i=fir;i<=7;)
    {
        now=mul(pow(M[i],a[i]),now) ;
        int i2 ;
        for(i2=i+1;i2<=7 && !a[i2];i2++) ;
        if(i2==8) printf("%d\n",now.a[(1<<i)-1][0]) ;
        else
        {
            int val=(1<<i2)-(1<<i) ;
            now.n=(1<<i2) ;
            for(int j=0;j<(1<<i);j++)
                now.a[j^val][0]=now.a[j][0] ,
                now.a[j][0]=0 ;
        }
        i=i2 ;
    }
}
