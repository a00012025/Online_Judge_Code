#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=4000+5 ;

int dp[maxn][maxn] ;
pii a[maxn] ;

bool ok(int l,int r,int t)
{
    if(t==0) return a[r].F-a[l].F>a[l].S ;
    else return a[r].F-a[l].F>a[r].S ;
}

main()
{
    freopen("trapped.in","r",stdin) ;
    freopen("trapped.out","w",stdout) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].S,&a[i].F) ;
    sort(a+1,a+n+1) ;
    for(int l=n-1;l>=1;l--) for(int i=1;i+l<=n;i++)
    {
        int j=i+l ;
        if(ok(i,j,0))
        {
            if(i==1) dp[i][j]=1 ;
            else if(dp[i-1][j]) dp[i][j]=1 ;
        }
        if(ok(i,j,1))
        {
            if(j==n) dp[i][j]=1 ;
            else if(dp[i][j+1]) dp[i][j]=1 ;
        }
    }

    int ans=0 ;
    for(int i=1;i<n;i++) if(!dp[i][i+1])
        ans+=a[i+1].F-a[i].F ;
    printf("%d\n",ans) ;
}
