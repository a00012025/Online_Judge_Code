#include<bits/stdc++.h>
#define CASE_T int __T ; scanf("%d",&__T) ; while(__T--)
using namespace std;
const int maxn=1000+10 ;

int dp[maxn][maxn],type[maxn][maxn] ;
int a[maxn],cnt ;

void print_ans(int l,int r)
{
    if(l>r) return ;
    if(l==r) { printf("%d%c",a[l],--cnt?' ':'\n') ; return ; }
    if(type[l][r]==1) print_ans(l+1,r) ;
    else if(type[l][r]==2) print_ans(l,r-1) ;
    else
    {
        printf("%d%c",a[l],--cnt?' ':'\n') ;
        print_ans(l+1,r-1) ;
        printf("%d%c",a[r],--cnt?' ':'\n') ;
    }
}

main()
{
    CASE_T
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;

        for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
        {
            if(i==j) { dp[i][j]=1 ; continue ; }
            dp[i][j]=-1 ;
            if(dp[i+1][j]>dp[i][j]) dp[i][j]=dp[i+1][j] , type[i][j]=1 ;
            if(dp[i][j-1]>dp[i][j]) dp[i][j]=dp[i][j-1] , type[i][j]=2 ;
            if(a[i]==a[j] && dp[i+1][j-1]+2>dp[i][j])
                dp[i][j]=dp[i+1][j-1]+2 , type[i][j]=3 ;
        }
        cnt=dp[1][n] ;
        print_ans(1,n) ;
    }
}

