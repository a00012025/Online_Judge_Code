#include<stdio.h>
#include<string.h>
bool dp[1000001] ;
main()
{
    int T,a[50001],s[50001];
    scanf("%d",&T) ;
    while(T--)
    {
        int n ;
        scanf("%d",&n) ; s[0]=0 ;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; s[i]=s[i-1]+a[i];}
        if(n>=20){printf("Yes\n") ; continue ;}
        memset(dp,0,sizeof(dp)) ; dp[0]=1 ;
        int yes=0 ;
        for(int i=1;i<=n;i++)
        {
            for(int j=s[n];j>=1;j--)
            {
                if(!dp[j] && j>=a[i]) dp[j]=dp[j-a[i]] ;
                else if(dp[j] && j>=a[i] && dp[j-a[i]]) yes=1 ;
                if(yes) break ;
            }
            if(yes)break ;
        }
        if(yes) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
