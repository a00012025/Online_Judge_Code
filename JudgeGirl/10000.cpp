#include<stdio.h>
#include<stdlib.h>
#define LL long long
LL gcd( LL a, LL b)
{
    return b ? gcd(b,a%b) : a ;
}

LL mul(LL a,LL b,LL mod)
{
    return (a*b-(LL)((long double)a*b/mod)*mod)%mod ;
}

int ch(LL x,LL k)
{
	LL ans=1;
	for(LL now=x%k,a=k-1;a;a/=2,now=mul(now,now,k))
		if(a%2) ans=mul(ans,now,k) ;
    return ans%k==1 ;
}

int isp(LL x)
{
	if(x==46856248255981LL)return 0 ;
	if(x==2||x==3||x==7||x==61||x==24251)return 1 ;
	if(ch(2,x)&&ch(3,x)&&ch(7,x)&&ch(61,x)&&ch(24251,x)) return 1 ;
	return 0 ;
}

LL ran()
{
    static LL num=5 ;
    return num=(num*num+2)%1000000007 ;
}

LL get_fac(LL num)
{
    int sz=2 ;
    LL ret=1 ;
	for (LL x0=ran(),x=x0;ret==1;sz*=2,x0=x)
		for (int i=1;i<=sz && ret==1;i++)
    {
     	x=mul(x,x,num)+1 ;
        ret=gcd(x-x0,num) ;
        if(ret<0) ret=-ret ;
	}
    return ret ;
}

LL fac[100000],t[100000] ;
int cnt ;
void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    for(int i=l,j=mid+1,cnt=l;i<=mid||j<=r;)
        if(j==r+1 || (i!=mid+1 && fac[i]<=fac[j])) t[cnt++]=fac[i++] ;
        else t[cnt++]=fac[j++] ;
    for(int i=l;i<=r;i++) fac[i]=t[i] ;
}

void solve(LL x)
{
    if(x==1) return ;
    if(isp(x)){fac[cnt++]=x ; return ;}
    int cnt=0 ;
    while(1)
    {
        LL t=get_fac(x) ;
        if(t==x) continue ;
        solve(t) ; solve(x/t) ;
        break ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL x ; scanf("%lld",&x) ;
        cnt=0 ;
        printf("%lld = ",x) ;
        solve(x) ;
        mer(0,cnt-1) ;
        for(int i=0;i<cnt;)
        {
            int j=i ;
            for(;j<cnt && fac[j]==fac[i];j++) ;
            printf("%lld",fac[i]) ;
            if(j>i+1) printf("^%d",j-i) ;
            if(j!=cnt) printf(" * ") ;
            i=j ;
        }
        printf("\n") ;
    }
}
