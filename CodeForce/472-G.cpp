#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int maxn=1<<18 ;
const int MOD=2013265921,MAX=MOD/2 ; /// MOD=15*2^27+1, which is a prime
const int gen=440564289 ; /// 31 is primitive root of MOD , gen = (31^15)%MOD

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

int n,m,Q,L ;
char s[maxn],t[maxn] ;
ULL sbit[maxn],tbit[maxn] ;
int match(int x,int y,int len)
{
    int ret=0 ;
    for(;len>=64;len-=64,x+=64,y+=64)
        ret+=__builtin_popcountll(sbit[x]^tbit[y]) ;
    if(len) ret+=__builtin_popcountll(
                (sbit[x]<<(64-len))^(tbit[y]<<(64-len))) ;
    return ret ;
}

LL *poly[maxn],a[maxn],b[maxn] ;
void precal()
{
    n=strlen(s) , m=strlen(t) ;
    for(int i=0;i<n;i++) for(int j=0;j<64&&i+j<n;j++)
        if(s[i+j]=='1') sbit[i]|=(1ULL<<j) ;
    for(int i=0;i<m;i++) for(int j=0;j<64&&i+j<m;j++)
        if(t[i+j]=='1') tbit[i]|=(1ULL<<j) ;

    L=n*sqrt(150*log2(n)/Q) ;
    int n2=1 ;
    while(n2<L+m) n2*=2 ;
    for(int i=0;i<n;i+=L)
    {
        poly[i/L]=new LL[n2] ;
        memset(a,0,sizeof(a)) ;
        memset(b,0,sizeof(b)) ;
        for(int j=0;j<L && i+j<n;j++) a[j]=(s[i+j]=='0' ? -1 : 1) ;
        for(int j=0;j<m;j++) b[m-1-j]=(t[j]=='0' ? -1 : 1) ;
        mul(a,b,poly[i/L],n2) ;
    }
}

main()
{
    scanf("%s%s%d",s,t,&Q) ;
    precal() ;
    while(Q--)
    {
        int x,y,l ; scanf("%d%d%d",&x,&y,&l) ;
        if(l<=L){printf("%d\n",match(x,y,l)) ; continue ;}
        int ans=0 ;
        if(x%L)
        {
            int l2=L-x%L ;
            ans+=match(x,y,l2) ;
            x+=l2 ; y+=l2 ; l-=l2 ;
        }
        if((x+l)%L)
        {
            int l2=(x+l-1)%L+1 ;
            ans+=match(x+l-l2,y+l-l2,l2) ;
            l-=l2 ;
        }
        if(!l){printf("%d\n",ans) ; continue ;}
        for(int i=x,j=y;l;i+=L,j+=L,l-=L)
            ans+=(L-poly[i/L][m-1-j])/2 ;
        printf("%d\n",ans) ;
    }
}
