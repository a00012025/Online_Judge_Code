#include<bits/stdc++.h>
using namespace std;
const int maxn=15 ;

int a[maxn],n,l,r,x ;
bool check(int S)
{
    int s=0,mi=1e7,ma=0 ;
    for(int i=0;i<n;i++) if(S&(1<<i))
    {
        s+=a[i] ;
        mi=min(mi,a[i]) ;
        ma=max(ma,a[i]) ;
    }
    return l<=s && s<=r && ma-mi>=x ;
}
main()
{
    scanf("%d%d%d%d",&n,&l,&r,&x) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    int ans=0 ;
    for(int i=1;i<(1<<n);i++)
        if(__builtin_popcount(i)>1 && check(i))
        ans++ ;
    printf("%d\n",ans) ;
}
