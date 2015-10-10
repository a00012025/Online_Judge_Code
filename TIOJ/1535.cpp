#include<bits/stdc++.h>
using namespace std;
const int maxp=12000000+10,maxn=110000+10 ;

bool vis[maxp] ;
int p[maxn],pcnt=0 ;
void prime()
{
    for(int i=2;i*i<maxp;i++) if(!vis[i])
            for(int j=i*i;j<maxp;j+=i) vis[j]=1 ;
    for(int i=2;i<maxp/10;i++) if(!vis[i])
        p[++pcnt]=i ;
}

int a[30] ;
int inv(int x)
{
    int ret=0,cnt=0 ;
    while(x) a[cnt++]=x%10 , x/=10 ;
    for(int i=0;i<cnt;i++) ret=ret*10+a[i] ;
    return ret ;
}

bool isp(int x)
{
    if(x<maxp) return !vis[x] ;
    for(int i=1;p[i]*p[i]<=x;i++) if(x%p[i]==0)
        return 0 ;
    return 1 ;
}

int ans[maxn] ;
main()
{
    prime() ;
    int cnt=0 ;
    for(int i=13;i<maxp;i++) if(!vis[i])
    {
        int x=inv(i) ;
        if(x!=i && isp(x)) ans[++cnt]=i ;
    }
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int x ; scanf("%d",&x) ;
        printf("%d\n",ans[x]) ;
    }
}
