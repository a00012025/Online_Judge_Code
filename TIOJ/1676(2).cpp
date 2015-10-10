#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

LL a[maxn] ;
LL dp[maxn],s[maxn],A[maxn],B[maxn] ;
int dq[maxn] ;

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[n+1-i]) ;

    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i] ;
    dp[0]=0LL ; A[0]=B[0]=0LL ;
    int l=0 , r=1 ; dq[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        while(dq[l]+k<i) l++ ;
        while(l+1<r && A[dq[l]]*i+B[dq[l]] <=
                        A[dq[l+1]]*i+B[dq[l+1]]) l++ ;
        dp[i]=-((LL)i)*((LL)i)+A[dq[l]]*i+B[dq[l]] ;

        A[i]=2*i ; B[i]=dp[i]+s[i]-((LL)i)*((LL)i) ;
        while(l+1<r && (B[dq[r-2]]-B[dq[r-1]])*(A[i]-A[dq[r-1]])
              >= (B[dq[r-1]]-B[i])*(A[dq[r-1]]-A[dq[r-2]]) &&
              (dq[r-2]+k)*(A[i]-A[dq[r-1]]) >=
              B[dq[r-1]]-B[i]) r-- ;
        dq[r++]=i ;
    }
    printf("%lld\n",dp[n]) ;
}
