#include<bits/stdc++.h>
using namespace std;
bool dp[150001] ;
int a[2001],b[2001],Q,n,m ;

bool DP()
{
    int sum=0 ;
    dp[0]=1 ;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i] ;
        if(dp[Q-a[i]]) return 1 ;
        for(int j=min(Q,sum);j>=a[i];j--) if(dp[j-a[i]])
            dp[j]=1 ;
    }
    return 0 ;
}

main()
{
    scanf("%d%d%d",&Q,&n,&m) ;
    int sum=0 ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , sum+=a[i] ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    if(DP()) printf("%d\n",Q) ;
    else if(sum>Q) printf("%d\n",Q-1) ;
    else
    {
        sort(b+1,b+m+1) ;
        int subs=0 ;
        for(int i=m;i>=1;i--) { subs++ ; sum+=b[i] ; if(sum>=Q) break ; }
        printf("%d\n",Q-subs) ;
    }
}
