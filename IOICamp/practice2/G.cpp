#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int p[100000],pcnt=0 ;
bool vis[maxn] ;
void make_prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

int val[maxn],sum[maxn] ;
void get_val()
{
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i]) { val[i]=-1 ; sum[i]=sum[i-1]+val[i] ; continue ; }
        bool ok=1 ;
        int num=0,tmp=i ;
        for(int j=1;j<=pcnt;j++) if(tmp%p[j]==0)
        {
            num++ ; tmp/=p[j] ;
            if(tmp%p[j]==0) { ok=0 ; break ; }
            if(!vis[tmp]) { num++ ; break ; }
        }
        if(!ok) val[i]=0 ;
        else if(num%2) val[i]=-1 ;
        else val[i]=1 ;
        sum[i]=sum[i-1]+val[i] ;
    }
}

main()
{
    make_prime() ;
    get_val() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        if(a>b) swap(a,b) ;
        LL ans=((LL)a)*((LL)b) ;
        for(int i=2;i<=a;)
        {
            int j= min(a/(a/i),b/(b/i)) ;
            ans+= ((LL)sum[j]-sum[i-1])*((LL)a/i)*((LL)b/i) ;
            i=j+1 ;
        }
        printf("%lld\n",ans) ;
    }
}
