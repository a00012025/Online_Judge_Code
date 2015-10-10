#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=30+10,maxk=200+10 ;

DB dp[maxk][maxn][maxn] ;
int a[maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int m=1;m<=k;m++) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
    {
        DB &d=dp[m][i][j] ;
        for(int x=1;x<=n;x++) for(int y=x;y<=n;y++)
        {
            if(x>j || y<i || (i<x && y<j)) d+=dp[m-1][i][j] ;
            else if(x<=i && j<=y) d+=1-dp[m-1][x+y-j][x+y-i] ;
            else if(x<=i && i<=y) d+=dp[m-1][x+y-i][j] ;
            else d+=dp[m-1][i][x+y-j] ;
        }
        d/=(n*(n+1)/2) ;
    }
    DB ans=0 ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        ans+=(a[i]>a[j] ? (1-dp[k][i][j]) : dp[k][i][j]) ;
    printf("%.10f\n",ans) ;
}
