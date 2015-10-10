#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

bool vis[maxn] ;
int p[80000],pcnt=0 ;

void prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

int m ;
LL power(LL a,int x)
{
    if(!x) return 1LL ;
    if(x==1) return a ;
    LL tmp=power(a,x/2) ;
    if(x%2) return (tmp*tmp%m)*a%m ;
    else return (tmp*tmp)%m ;
}

main()
{
    prime() ;
    int n ;
    while(scanf("%d%d",&n,&m)==2 && m+n)
    {
        LL ans=1LL ;
        for(int i=1;p[i]<=n;i++)
        {
            int x=0,tmp=n ;
            while(tmp) x+=tmp/p[i] , tmp/=p[i] ;
            ans=ans*power(p[i],x)%m ;
        }
        printf("%lld\n",ans) ;
    }
}
