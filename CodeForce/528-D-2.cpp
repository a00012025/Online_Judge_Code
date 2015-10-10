#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1<<19 ;
const int MOD=2013265921,MAX=MOD/2 ; /// MOD=15*2^27+1, which is a prime
const int gen=440564289 ; /// 31 is primitive root of MOD , gen = (31^15)%MOD
/**
 * This FFT can handle polynomial multiplication with all the
 * absolute values of coefficients < MAX = MOD/2.
 */
LL power(LL x,int n)
{
    if(n<=1) return n ? x : 1LL ;
    LL t=power(x,n/2) ;
    if(n&1) return (t*t%MOD)*x%MOD ;
    else return t*t%MOD ;
}

LL tmp[maxn] ;
void DFT(LL *a,LL x,int n)
{
    if(n==1)
    {
        a[0]%=MOD ;
        if(a[0]<0) a[0]+=MOD ;
        return ;
    }
    for(int i=0;i<n;i++) tmp[i]=a[i] ;
    for(int i=0;i<n;i++) a[i%2 ? n/2+i/2 : i/2]=tmp[i] ;
    LL *a1=a , *a2=a+n/2 , xx=x*x%MOD ;
    DFT(a1,xx,n/2) ;
    DFT(a2,xx,n/2) ;
    LL now=1 ;
    for(int i=0;i<n/2;i++,now=now*x%MOD)
    {
        LL val=now*a2[i]%MOD ;
        tmp[i]=a1[i]+val-MOD ;
        tmp[i+n/2]=a1[i]-val ;
    }
    for(int i=0;i<n;i++) a[i]=(tmp[i]<0?tmp[i]+MOD:tmp[i]) ;
}

void mul(LL *a,LL *b,LL *c,int n)
{
    LL x=power(gen,(1<<27)/n) , xinv=power(x,n-1) ;
    LL ninv=power(n,MOD-2) ;
    DFT(a,x,n) ;
    DFT(b,x,n) ;
    for(int i=0;i<n;i++) c[i]=a[i]*b[i]%MOD ;
    DFT(c,xinv,n) ;
    for(int i=0;i<n;i++)
    {
        c[i]=c[i]*ninv%MOD ;
        if(c[i]>MAX) c[i]-=MOD ;
    }
}

LL a[maxn],b[maxn],ans[maxn] ;
char s[maxn],t[maxn] ;
int sum[maxn],n,m,k ;

void solve(char ch)
{
    memset(a,0,sizeof(a)) ;
    memset(b,0,sizeof(b)) ;
    for(int i=0;i<m;i++) if(t[i]==ch) b[m-1-i]=1 ;
    for(int i=0;i<n;i++) sum[i+1]=sum[i]+(s[i]==ch) ;
    for(int i=0;i<n;i++) if(sum[min(i+k,n-1)+1]==sum[max(i-k,0)])
        a[i]=1 ;
    mul(a,b,a,maxn) ;
    for(int i=0;i<maxn;i++) ans[i]+=a[i] ;
}

main()
{
    scanf("%d%d%d%s%s",&n,&m,&k,s,t) ;
    for(int i=0;i<4;i++) solve("ATCG"[i]) ;
    int cnt=0 ;
    for(int i=m-1;i<=n-1;i++) if(!ans[i])
        cnt++ ;
    printf("%d\n",cnt) ;
}
