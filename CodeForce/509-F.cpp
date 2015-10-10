#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

int a[501] ;
LL dp1[501][501],dp2[501][501] ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
    {
        if(i==j)
        {
            dp1[i][j]=dp2[i][j]=1LL ;
            continue ;
        }
        dp1[i][j]=dp2[i+1][j] ;
        dp2[i][j]=dp2[i+1][j] ;
        for(int k=i+1;k<=j;k++) if(a[k]>a[i])
            dp2[i][j]+= dp1[i][k-1]*dp2[k][j] ,
            dp2[i][j]%=MOD ;
    }
    printf("%I64d\n",dp1[1][n]) ;
}

