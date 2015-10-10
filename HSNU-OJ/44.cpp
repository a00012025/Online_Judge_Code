#include<bits/stdc++.h>
using namespace std;

int a[1001],sum[1001],dp1[1001][1001],dp2[1001][1001] ;

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        sum[0]=0 ;
        for(int i=1;i<=n;i++) { scanf("%d",&a[i]) ; sum[i]=sum[i-1]+a[i] ; }
        for(int len=1;len<=n;len++) for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1 ;
            if(len==1) { dp1[i][j]=0 ; dp2[i][j]=a[i] ; continue ; }
            if(len%2 == 0)
                dp1[i][j]=max(dp1[i+1][j]+a[i],dp1[i][j-1]+a[j]) ,
                dp2[i][j]=sum[j]-sum[i-1]-dp1[i][j] ;
            else
                dp2[i][j]=max(a[i]+dp2[i+1][j],a[j]+dp2[i][j-1]) ,
                dp1[i][j]=sum[j]-sum[i-1]-dp2[i][j] ;
        }
        printf("%d %d\n",dp1[1][n],sum[n]-dp1[1][n]) ;
    }
}
