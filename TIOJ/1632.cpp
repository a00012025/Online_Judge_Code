#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

int a[maxn] ;
int n ;

LL cal(int x)
{
    LL ret=0LL ;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n &&  a[i] >= a[j]-x ) j++ ;
        ret+=j-i-1 ;
    }
    return ret ;
}

main()
{
    LL k ;
    scanf("%d%lld",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+n+1) ;

    int l=0 , r=2000000001 ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(cal(mid)>=k) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r) ;
}
