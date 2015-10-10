#include<bits/stdc++.h>
#define DB double
using namespace std;
const int K=400 ;

DB dp[K],p[K] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    p[1]=1 ;
    for(int i=1;i<=n;i++) for(int j=min(i+1,K-1);j>=1;j--)
    {
        int t=j*k ;
        dp[j]=(t+k-1)*dp[j]/(t+k) + p[j]*j/(2*k)
                + dp[j-1]/t + p[j-1]*(j-1)/t ;
        p[j]=p[j]*(t+k-1)/(t+k)+p[j-1]/k/j ;
    }
    DB ans=0 ;
    for(int i=0;i<K;i++) ans+=dp[i] ;
    printf("%.10f\n",ans*k) ;
}
