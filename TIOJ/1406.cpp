#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int n ;
LL pos[maxn],a[maxn],b[maxn] ;

bool check(LL num)
{
    for(int i=1;i<=n;i++) a[i]=b[i] ;
    for(int i=1;i<n;i++)
    {
        if(a[i]>num) a[i+1]+=max(0LL,a[i]-num-(pos[i+1]-pos[i])) ;
        else a[i+1]-=(num-a[i] + pos[i+1]-pos[i]) ;
    }
    return (a[n]>=num) ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%lld%lld",&pos[i],&b[i]) ;

        LL l=0 , r=(LL)(1e12)+100 ;
        while(r-l>1)
        {
            LL mid=(r+l)/2 ;
            if(check(mid)) l=mid ;
            else r=mid ;
        }
        printf("%lld\n",l) ;
    }
}
