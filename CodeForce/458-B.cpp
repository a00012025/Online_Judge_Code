#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int n,m ;
int a[maxn],b[maxn] ;
LL solve()
{
    LL sa=0,sb=0,ret=1LL<<60 ;
    for(int i=1;i<=n;i++) sa+=a[i] ;
    for(int i=m;i>=1;i--)
    {
        if(ret>sb && (ret-sb)/i>sa-2)
            ret=min(ret,i*sa+sb) ;
        sb+=b[i] ;
    }
    return ret ;
}
main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    sort(a+1,a+n+1,greater<int>()) ;
    sort(b+1,b+m+1,greater<int>()) ;
    LL ans=solve() ;
    swap(a,b) ; swap(n,m) ;
    printf("%I64d\n",min(ans,solve())) ;
}
