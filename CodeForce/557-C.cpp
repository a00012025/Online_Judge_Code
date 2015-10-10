#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

int cnt[210],sum[maxn] ;
int query(int x)
{
    int ret=0 ;
    for(int i=1;x;x-=min(x,cnt[i]),i++)
        ret+=min(x,cnt[i])*i ;
    return ret ;
}

pii p[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i].F) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i].S) ;
    sort(p+1,p+n+1) ;
    sum[n+1]=0 ;
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]+p[i].S ;
    int ans=1e9 ;
    for(int i=1;i<=n;)
    {
        int i2=i ;
        for(;i2<=n && p[i].F==p[i2].F;i2++) ;
        int add=(i2-i >= i ? 0 : query(2*i-i2)) ;
        ans=min(ans,sum[i2]+add) ;
        for(;i<i2;i++) cnt[p[i].S]++ ;
    }
    printf("%d\n",ans) ;
}
