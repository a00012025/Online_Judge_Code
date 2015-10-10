#include<bits/stdc++.h>
#define DB long double
#define INF (1e10)
using namespace std;

char s[50],t[50] ;
int n,m ;
DB d[50][50] ;

DB dp(int i,int j)
{
    if(i==n) return -0.3*(m-j) ;
    if(j==m) return -0.3*(n-i) ;
    if(d[i][j]!=INF) return d[i][j] ;
    DB &ans=d[i][j] ; ans=-INF ;
    if(s[i]==t[j]) ans=max(ans,dp(i+1,j+1)+1.0) ;
    else ans=max(ans,dp(i+1,j+1)-0.5) ;
    ans=max(ans,dp(i+1,j)-0.3) ;
    ans=max(ans,dp(i,j+1)-0.3) ;
    return ans ;
}

main()
{
    while(scanf("%s%s",s,t)!=EOF)
    {
        n=strlen(s) ;
        m=strlen(t) ;
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++)
            d[i][j]=INF ;
        DB ans=100*dp(0,0)/((DB)n) ;
        double _ans=ans ;
        printf("%.2f\%\n",_ans) ;
    }
}
