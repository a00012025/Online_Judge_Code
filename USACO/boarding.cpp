#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=200000+10 ;

int bit[maxn] ;
void add(int x,int val)
{
    while(x<maxn) bit[x]+=val , x+=lowbit(x) ;
}

int query(int x)
{
    int ret=0 ;
    while(x) ret+=bit[x] , x-=lowbit(x) ;
    return ret ;
}

int p[maxn],t[maxn] ;
main()
{
    freopen("boarding.in","r",stdin) ;
    freopen("boarding.out","w",stdout) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&t[i]) ;
    int ans=0 ;
    for(int i=n;i>=1;i--)
    {
        ans=max(ans,p[i]+n-i+t[i]+query(p[i])) ;
        add(p[i],t[i]) ;
    }
    printf("%d\n",ans) ;
}
