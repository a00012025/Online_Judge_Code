#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=1000+10 ;

int n,d[maxn][maxn] ;
int a[maxn] ;

inline int f(int x,int y)
{
    return a[x]==a[y] ? 1 : 0 ;
}

inline int add(int x)
{
    return (x+1)%n ;
}

inline int sub(int x)
{
    return (x+n-1)%n ;
}

int dp(int l,int r)
{
    if(l==r) return -INF ;
    if(r==add(l)) return f(l,r) ;
    if(d[l][r]!=-1) return d[l][r] ;
    int &ans=d[l][r] ;
    ans= dp((l+2)%n,r)+f(l,add(l)) ;
    ans=max(ans, f(l,r)+dp(add(l),sub(r)) ) ;
    for(int i=add(add(l));i!=r;i=add(i))
        ans=max(ans, f(l,i)+dp(add(l),sub(i))+dp(add(i),r) ) ;
    return ans ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
        if(n%2) { printf("0\n") ; continue ; }
        memset(d,-1,sizeof(d)) ;
        printf("%d\n",dp(0,n-1)) ;
    }
}
