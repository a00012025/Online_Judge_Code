#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool ok[1000][1000] ;
char s[2000] ;
int dp[2000] ;
main()
{
    int T ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s) ;
        int n=strlen(s) ;
        for(int i=0;i<n;i++) ok[i][i]=ok[i+1][i]=1 ;
        for(int len=2;len<=n;len++) for(int i=0;i+len-1<n;i++)
            ok[i][i+len-1]=ok[i+1][i+len-2] && s[i]==s[i+len-1] ;
        dp[0]=1 ;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+1 ;
            for(int j=i;j>=0;j--) if(ok[j][i])
                dp[i]=min(dp[i],dp[j-1]+1) ;
        }
        printf("%d\n",dp[n-1]) ;
    }
}
