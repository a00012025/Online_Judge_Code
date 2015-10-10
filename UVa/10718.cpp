#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;

LL find_min(LL m,LL n)
{
    if(n>=m) return n ;
    int i,j ;
    for(i=40;(1LL<<i)>m;i--) ;
    for(j=40;(1LL<<j)>n;j--) ;
    if(i>j) return find_min(m-(1LL<<i),n) + (1LL<<i) ;
    else return find_min(m-(1LL<<i),n-(1LL<<i)) + (1LL<<i) ;
}

main()
{
    LL L,U,n ;
    while(scanf("%lld%lld%lld",&n,&L,&U)!=EOF)
    {
        LL ans=0 ;
        for(int i=40;i>=0;i--) if(((1LL<<i) & n) == 0)
        {
            LL num=find_min(L,ans+(1LL<<i)) ;
            if(num<=U)
                ans+=(1LL<<i) ;
        }
        //printf("%d\n",ans) ;
        printf("%lld\n",find_min(L,ans)) ;
    }
}
