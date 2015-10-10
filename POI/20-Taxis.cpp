#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500000+10 ;

LL m,d ; int n ;
LL a[maxn] ;

int solve()
{
    sort(a+1,a+n+1) ;
    if(a[n]<m-d) return 0 ;
    if(a[n]>=d+m) return 1 ;

    LL tmp ;
    for(int i=1;;i++) if(a[i]>=m-d)
    {
        tmp=a[i] ;
        for(int j=i;j<n;j++) a[j]=a[j+1] ;
        n-- ; break ;
    }

    int ans=1 ; LL now=0LL ;
    for(int i=n;i>=1;i--)
    {
        if(a[i]<=d-now) return 0 ;
        ans++ ; now+=a[i]-(d-now) ;
        if(now>=d) break ;
        if(2*(d-now)+m-d <= tmp) return ans ;
    }
    if(now<d) return 0 ;
    if(now>=m) return now>=m ? ans-1 : ans ;
}

main()
{
    scanf("%lld%lld%d",&m,&d,&n) ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
    printf("%d\n",solve()) ;
}
