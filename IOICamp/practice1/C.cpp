#include<bits/stdc++.h>
using namespace std;
const int maxn=200+100 ;

int dp[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn] ;
int a[maxn],b[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]) ;
        for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
        {
            if(i==j)
            {
                dp[i][j]= (a[i]==b[i])?0:1 ;
                dp2[i][j]=0 ;
                dp3[i][j]=1 ;
                continue ;
            }

            int l,r ;
            for(l=i+1;l<=j&&b[l]==b[i];l++) ;
            r=l ;
            dp2[i][j]=0 ;
            while(r<=j)
            {
                while(r<=j && b[r]!=b[i]) r++ ;
                dp2[i][j]+=dp3[l][r-1] ;
                for(l=r;l<=j&&b[l]==b[i];l++) ;
                r=l ;
            }

            if(a[i]==b[i]) dp[i][j]=dp[i+1][j] ;
            else if(a[j]==b[j]) dp[i][j]=dp[i][j-1] ;
            else
            {
                dp[i][j]=dp2[i][j]+1 ;
                for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp2[i][k]+dp[k+1][j]+1) ;
            }

            dp3[i][j]=dp2[i][j]+1 ;
            for(int k=i;k<j;k++) dp3[i][j]=min(dp3[i][j],dp2[i][k]+dp3[k+1][j]+1) ;
        }

        printf("%d\n",dp[1][n]) ;
    }
}
