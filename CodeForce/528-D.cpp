#include<bits/stdc++.h>
#define DB double
#define comp complex<DB>
using namespace std;
const int maxn=1<<19 ;
const DB PI=2*acos(0.0) ;

comp tmp[maxn] ;
void DFT(comp *a,int n,int idft)
{
    if(n==1) return ;
    for(int i=0;i<n;i++) tmp[i]=a[i] ;
    for(int i=0;i<n;i++) a[i%2 ? n/2+i/2 : i/2]=tmp[i] ;
    comp *a1=a , *a2=a+n/2 ;
    DFT(a1,n/2,idft) ;
    DFT(a2,n/2,idft) ;
    comp w(cos(2*PI/n),sin(2*PI/n)) , now(1,0) ;
    if(idft) w=conj(w) ;
    for(int i=0;i<n/2;i++,now*=w)
    {
        tmp[i]=a1[i]+now*a2[i] ;
        tmp[i+n/2]=a1[i]-now*a2[i] ;
    }
    for(int i=0;i<n;i++) a[i]=tmp[i] ;
}

void mul(comp *a,comp *b,comp *c,int n)
{
    DFT(a,n,0) ;
    DFT(b,n,0) ;
    for(int i=0;i<n;i++) c[i]=a[i]*b[i] ;
    DFT(c,n,1) ;
    for(int i=0;i<n;i++) c[i]/=n ;
}

comp a[maxn],b[maxn],ans[maxn] ;
char s[maxn],t[maxn] ;
int sum[maxn],n,m,k ;

void solve(char ch)
{
    for(int i=0;i<maxn;i++) a[i]=b[i]=(comp){0,0} ;
    for(int i=0;i<m;i++) if(t[i]==ch) b[m-1-i]=(comp){1,0} ;
    for(int i=0;i<n;i++) sum[i+1]=sum[i]+(s[i]==ch) ;
    for(int i=0;i<n;i++) if(sum[min(i+k,n-1)+1]==sum[max(i-k,0)])
        a[i]=(comp){1,0} ;
    mul(a,b,a,maxn) ;
    for(int i=0;i<maxn;i++) ans[i]+=a[i] ;
}

main()
{
    scanf("%d%d%d%s%s",&n,&m,&k,s,t) ;
    for(int i=0;i<4;i++) solve("ATCG"[i]) ;
    int cnt=0 ;
    for(int i=m-1;i<=n-1;i++) if(int(real(ans[i])+0.5)==0)
        cnt++ ;
    printf("%d\n",cnt) ;
}
