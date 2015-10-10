#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=30+2 ;

struct mat
{
    int n,m,a[maxn][maxn] ;
    mat(){}
    mat(int _n,int _m){n=_n ; m=_m ; memset(a,0,sizeof(a)) ;}
};

mat operator * (const mat &p,const mat &q)
{
    mat r(p.n,q.m) ;
    for(int i=0;i<p.n;i++) for(int j=0;j<q.m;j++)
        for(int z=0;z<p.m;z++)
        r.a[i][j]+=(LL)p.a[i][z]*q.a[z][j]%MOD ,
        r.a[i][j]%=MOD ;
    return r ;
}

mat M[61][maxn],I[61][maxn] ;
int k ;
LL n ;
void cal_mat()
{
    for(int i=0;i<k;i++)
    {
        M[0][i].n=M[0][i].m=k+1 ;
        I[0][i].n=I[0][i].m=k+1 ;
        for(int j=0;j<=k;j++)
            M[0][i].a[j][j]=I[0][i].a[j][j]=1 ;
        for(int j=0;j<=k;j++) if(j!=i)
            M[0][i].a[i][j]=1 ,
            I[0][i].a[i][j]=MOD-1 ;
    }

    int cnt=0 ;
    for(LL i=n;i;i/=k,cnt++) ;
    for(int i=1;i<cnt;i++)
    {
        M[i][0]=M[i-1][0] ; I[i][0]=I[i-1][0] ;
        for(int j=1;j<k;j++)
            M[i][0]=M[i][0]*M[i-1][j] ,
            I[i][0]=I[i-1][j]*I[i][0] ;
        for(int j=1;j<k;j++)
        {
            M[i][j]= I[i-1][j-1]*M[i][j-1]*M[i-1][j-1] ;
            I[i][j]= I[i-1][j-1]*I[i][j-1]*M[i-1][j-1] ;
        }
    }
}

int cal(LL num)
{
    return num ? (num%k+cal(num/k))%k : 0 ;
}

LL pw[61] ;
int a[61] ;
main()
{
    scanf("%lld%d",&n,&k) ;
    cal_mat() ;

    int cnt=0 ;
    for(;n;n/=k,cnt++) a[cnt]=n%k ;
    for(int i=0;i<cnt;i++) pw[i]= (i ? pw[i-1]*k : 1);

    mat p(k+1,k+1) ; for(int i=0;i<=k;i++) p.a[i][i]=1 ;
    mat q(k+1,1) ; q.a[k][0]=1 ;

    LL now=0LL ;
    for(int i=cnt-1;i>=0;i--) if(a[i])
    {
        int x=cal(now) ;
        for(int j=0;j<a[i];j++) p=p*M[i][(x+j)%k] ;
        now+=a[i]*pw[i] ;
    }
    q=p*q ;
    int ans=0 ;
    for(int i=0;i<=k;i++)
    {
        ans=ans+q.a[i][0] ;
        if(ans>=MOD) ans-=MOD ;
    }
    printf("%d\n",ans) ;
}
