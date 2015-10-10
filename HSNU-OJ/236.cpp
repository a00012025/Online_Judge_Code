#include<bits/stdc++.h>
#define LL long long
#define DB double
#define INF (1LL<<60)
using namespace std;

int a,b,c ;
int n ;
LL S[1000001],dp[1000001] ;
int deq[2000001] ;

inline LL cal(int k,LL x)
{
    return -2*a*S[k]*x+dp[k]+a*S[k]*S[k] ;
}

inline DB getx(int x,int y)
{
    return ( (DB)dp[y]+a*S[y]*S[y]-dp[x]-a*S[x]*S[x] )/( (DB)S[x]-S[y] ) ;
}

main()
{
    scanf("%d",&n) ;
    scanf("%d%d%d",&a,&b,&c) ;
    S[0]=0LL ;
    for(int i=1;i<=n;i++) scanf("%lld",&S[i]) , S[i]+=S[i-1] ;
    dp[0]=0 ;
    int l=0 , r=0 ; deq[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        while(r>l && cal(deq[l],S[i])<=cal(deq[l+1],S[i])) l++ ;
        dp[i]= a*(S[i]-S[deq[l]])*(S[i]-S[deq[l]])+c+dp[deq[l]] ;
        while(r>l && getx(deq[r-1],deq[r])>=getx(deq[r],i) ) r-- ;
        deq[++r]=i ;
    }
    printf("%lld\n",dp[n]+b*S[n]) ;
}
