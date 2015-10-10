#include<bits/stdc++.h>
using namespace std;
const int maxn=600+10 ;

int dp[maxn][maxn],l[maxn],r[maxn] ;

void print(int L,int R)
{
    if(L==R) { printf("()") ; return ; }
    if(L>R) return ;
    printf("(") ;
    print(L+1,L+(dp[L][R]-1)/2) ;
    printf(")") ;
    print(L+(dp[L][R]+1)/2,R) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]) ;
    memset(dp,-1,sizeof(dp)) ;
    for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
    {
        if(i==j)
        {
            if(l[i]==1) dp[i][j]=1 ;
            continue ;
        }
        if(l[i]==1 && dp[i+1][j]!=-1) { dp[i][j]=1 ; continue ; }
        if(2*(j-i)+1>=l[i] && 2*(j-i)+1<=r[i] && dp[i+1][j]!=-1)
            { dp[i][j]=2*(j-i)+1 ; continue ; }
        for(int x=max(1,l[i]/2);j-i>x && 2*x+1<=r[i];x++)
            if(dp[i+1][i+x]!=-1 && dp[i+x+1][j]!=-1)
                { dp[i][j]=2*x+1 ; break ; }
    }
    if(dp[1][n]==-1) printf("IMPOSSIBLE") ;
    else print(1,n) ;
    printf("\n") ;
}
