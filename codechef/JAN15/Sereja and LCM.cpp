#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

int pcnt=0,prime[2000] ;
bool vis[2000] ;
void make_prime()
{
    for(int i=2;i*i<2000;i++) if(!vis[i])
        for(int j=i*i;j<2000;j+=i) vis[j]=1 ;
    for(int i=2;i<2000;i++) if(!vis[i])
        prime[++pcnt]=i ;
}

LL get_pow(LL x,int n)
{
    if(n==0) return 1LL ;
    if(n==1) return x ;
    LL y=get_pow(x,n/2) ;
    if(n%2) return (((y*y)%MOD)*x)%MOD ;
    else return ((y*y)%MOD) ;
}

int n,m ;
LL power[2000] ;
void pre_cal()
{
    power[0]=0 ;
    for(int i=1;i<=m;i++) power[i]=get_pow((LL)i,n) ;
}

int event[200],num[50] ;

int Union(int S)
{
    int ret=0 ;
    for(int S0=S;S0;S0=((S0-1)&S))
    {
        int cnt=0 ;
        for(int j=0;(1<<j)<=S0;j++) if(S0&(1<<j)) cnt++ ;
        if(cnt%2) ret+=event[S0] ;
        else ret-=event[S0] ;
    }
    return ret ;
}

LL cal(int d)
{
    int cnt=0 ;
    for(int i=1;i<=pcnt && d!=1;i++) if(d%prime[i]==0)
    {
        num[cnt]=1 ;
        while(d%prime[i]==0) d/=prime[i] , num[cnt]*=prime[i] ;
        cnt++ ;
    }

    memset(event,0,sizeof(event)) ;
    for(int i=1;i<=m;i++) for(int j=1;j<(1<<cnt);j++)
    {
        bool ok=1 ;
        for(int k=0;k<cnt;k++) if((j&(1<<k)) && (i%num[k])) {ok=0 ; break ;}
        if(ok) event[j]++ ;
    }

    LL ret=power[m] ;
    for(int i=1;i<(1<<cnt);i++)
    {
        int cnt2=0 ;
        for(int j=0;j<cnt;j++) if(i&(1<<j)) cnt2++ ;
        if(cnt2%2) ret-=power[m-Union(i)] ;
        else ret+=power[m-Union(i)] ;
        ret%=MOD ; if(ret<0) ret+=MOD ;
    }
    return ret ;
}

main()
{
    make_prime() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int L,R ; scanf("%d%d%d%d",&n,&m,&L,&R) ;
        pre_cal() ;
        LL ans=0LL ;
        for(int i=L;i<=R;i++) ans=(ans+cal(i))%MOD ;
        printf("%lld\n",ans) ;
    }
}
