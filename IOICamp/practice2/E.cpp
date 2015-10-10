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


main()
{
    make_prime() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL a,b ; scanf("%lld%lld",&a,&b) ;
        if(a>b) swap(a,b) ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=pcnt;i++)
        {
            LL x=max(2LL,(a-1)/p[i]+1) ; x*=p[i] ;
            while(x<=b) vis[x-a]=1 , x+=p[i] ;
        }
        if(a==1) vis[0]=1 ;
        printf("%d\n",count(vis,vis+b-a+1,0)) ;
    }
}
