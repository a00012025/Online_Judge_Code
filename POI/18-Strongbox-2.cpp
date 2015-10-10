#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=250000+10 ;

LL getll()
{
    char c=getchar() ;
    while(c<'0'||c>'9') c=getchar() ;
    LL x=0 ;
    while(1)
    {
        x=x*10+c-'0' ;
        c=getchar() ;
        if(c<'0'||c>'9') return x ;
    }
}

LL a[maxn] ;
set<LL> st,del ;

int cnt=0,num[maxn],num2[maxn] ;
LL p[maxn] ;

void DEL(int x,LL now)
{
    if(x==cnt) { del.insert(now) ; return ; }
    if(del.find(now)!=del.end()) return ;
    DEL(x+1,now) ;
    for(int i=1;i<=num2[x];i++)
    {
        now/=p[x] ;
        DEL(x+1,now) ;
    }
}

void dfs(int x,LL now)
{
    if(x==cnt)
    {
        if(st.find(now)!=st.end()) DEL(0,now) ;
        return ;
    }
    if(del.find(now)!=del.end()) return ;
    dfs(x+1,now) ;
    for(int i=1;i<=num[x];i++)
    {
        now/=p[x] ; num2[x]-- ;
        dfs(x+1,now) ;
    }
    num2[x]=num[x] ;
}

main()
{
    LL n ; int m ;
    scanf("%lld%d",&n,&m) ;
    for(int i=1;i<=m;i++) a[i]=getll() ;

    a[m]=__gcd(a[m],n) ;
    for(int i=1;i<m;i++) st.insert(__gcd(a[i],a[m])) ;

    int sq=(int)sqrtl(a[m]+0.5) ;
    LL tmp=a[m] ;
    for(int i=2;i<=sq && i<tmp;i++) if(tmp%i==0)
    {
        p[cnt]=i ; num[cnt]=0 ;
        while(tmp%i==0) num[cnt]++ , tmp/=i ;
        num2[cnt]=num[cnt] ;
        cnt++ ;
    }
    if(tmp!=1) p[cnt]=tmp , num[cnt]=num2[cnt]=1 , cnt++ ;

    dfs(0,a[m]) ;

    LL ans=0LL ;
    for(int i=1;i<=sq;i++) if(a[m]%i==0)
    {
        if(del.find(i)==del.end()) ans=max(ans,n/i) ;
        if(del.find(a[m]/i)==del.end()) ans=max(ans,n/(a[m]/i)) ;
    }
    printf("%lld\n",ans) ;
}
