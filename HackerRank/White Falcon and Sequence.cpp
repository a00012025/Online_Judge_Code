#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=3000+10 ;

LL c[maxn] ;
LL cal(int n)
{
    for(int i=1;i<n;i++) c[i]+=c[i-1] ;
    LL ret=0 , mi=0 ;
    for(int i=0;i<n;i++) ret=max(ret,c[i]-mi) , mi=min(mi,c[i]) ;
    return ret ;
}

LL a[maxn] ;
int main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
    LL ans=-1e12 ;
    for(int i=3;i<=2*n-1;i++)
    {
        int x=i/2 , y=i-x ;
        if(x==y) x-- , y++ ;
        for(int j=0;x-j>=1 && y+j<=n;j++) c[j]=a[x-j]*a[y+j] ;
        ans=max(ans,cal(min(x,n-y+1))) ;
    }
    printf("%lld\n",ans) ;
}
