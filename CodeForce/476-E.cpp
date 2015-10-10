#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[2101][2101] ;
main()
{
    char s[3000],t[600] ;
    int low[3000] ;
    for(int i=0;i<3000;i++) low[i]=-1 ;
    scanf("%s %s",s,t) ;
    int l1=strlen(s) , l2=strlen(t) ;
    for(int i=l1-1;i>=0;i--)
    {
        if(s[i]!=t[l2-1] || i<l2-1) continue ;
        int found=l2-1 , last=i ;
        while(found && last>=0)
        {
            last-- ;
            while(last>=0 && s[last]!=t[found-1]) last-- ;
            if(last<0) break ;
            found-- ;
        }
        if(found!=0) continue ;
        low[i]=last ;
    }
        //for(int i=0;i<l1;i++)printf("%d,",low[i]);
        //printf("\n");
    memset(dp,0,sizeof(dp)) ;
    for(int i=0;i<=l1;i++) for(int x=0;x<l1;x++)
    {
        if(low[i]>=0 && x-i+low[i]-1+l2 >=0 && low[i]>=x-i+low[i]-1+l2)
            dp[i][x]=max(dp[i][x],dp[low[i]-1][x-i+low[i]-1+l2]+1) ;
        if(i>=1) dp[i][x]=max(dp[i][x],dp[i-1][x]) ;
        if(i>=1 && x>=1) dp[i][x]=max(dp[i][x],dp[i-1][x-1]) ;
        //printf("dp[%d][%d]=%d\n",i,x,dp[i][x]);
    }
    for(int i=0;i<=l1;i++)printf("%d ",dp[l1-1][i]);
    printf("\n");
}
