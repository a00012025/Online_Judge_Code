#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;
bool vis[maxn] ;
int cnt,p[maxn],sum[maxn] ;
int ans[maxn] ;
void pre_cal()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
        vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++cnt]=i ;
    sum[0]=0 ;
    for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+p[i] ;
    memset(ans,0,sizeof(ans)) ;
    for(int i=0;i<=cnt;i++) for(int j=i+1;j<=cnt;j++)
        if(sum[j]-sum[i]<maxn) ans[sum[j]-sum[i]]++ ;
}

main()
{
    pre_cal() ;
    int n ;
    while(scanf("%d",&n)==1 && n) printf("%d\n",ans[n]) ;
}
