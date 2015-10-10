#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[1111][1111] ;
main()
{
    char s[2000],t[2000] ;
    while(gets(s))
    {
        gets(t) ;
        memset(dp,0,sizeof(dp)) ;
        int a=strlen(s) , b=strlen(t) ;
        for(int i=0;i<a;i++) for(int j=0;j<b;j++)
        {
            if(s[i]==t[j] && i && j) dp[i][j]=dp[i-1][j-1]+1 ;
            else if(s[i]==t[j]) dp[i][j]=1 ;
            else
            {
                if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]) ;
                if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]) ;
            }
        }
        printf("%d\n",dp[a-1][b-1]) ;
    }
}
