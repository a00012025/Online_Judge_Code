#include<bits/stdc++.h>
using namespace std;
const int maxn=40000 ;
bool vis[maxn] ;
int cnt,p[maxn] ;
void pre_cal()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
        vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++cnt]=i ;
}

int div_num(int x)
{
    int ret=1 ;
    for(int i=1;x!=1 && i<=cnt;i++) if((x%p[i])==0)
    {
        int t=0 ;
        while((x%p[i])==0) t++ , x/=p[i] ;
        ret *= (t+1) ;
    }
    if(x!=1) ret*=2 ;
    return ret ;
}

main()
{
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int ans=0,ansid,l,r ;
        scanf("%d%d",&l,&r) ;
        for(int i=l;i<=r;i++) if(div_num(i)>ans) ans=div_num(i) , ansid=i ;
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,r,ansid,ans) ;
    }
}
