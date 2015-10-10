#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=2000000000 ;
int a[200001],dp[300001],n ;
int g[200001],f[200001] ;

void init()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; dp[i]=INF ;}
    g[1]=1 ;
    for(int i=2;i<=n;i++)
        g[i]= a[i]>a[i-1] ? g[i-1]+1 : 1 ;
    f[n]=1 ;
    for(int i=n-1;i>=1;i--)
        f[i]= a[i+1]>a[i] ? f[i+1]+1 : 1 ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        init() ;
        int ans=1 , num=1 ; dp[1]=a[1] ;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>dp[num]) ans=max(ans,num+f[i]) ;
            else
            {
                int id=lower_bound(dp+1,dp+num+1,a[i]) - dp ;
                id-- ;
                ans=max(ans,id+f[i]) ;
            }
            if(dp[g[i]]==INF) num=g[i] ;
            for(int j=g[i];j>=1 && dp[j]>a[i];j--) dp[j]=a[i] ;
        }
        printf("%d\n",ans) ;
    }
}
