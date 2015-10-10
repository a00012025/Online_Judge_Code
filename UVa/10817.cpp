#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 1000000000
using namespace std;
int teach[200],cost[200],dp[122][256][256] ;
main()
{
    int s,m,n ;
    while(scanf("%d%d%d",&s,&m,&n)==3 && s+m+n)
    {
        char t[5000] ;
        gets(t) ;
        for(int i=1;i<=m+n;i++)
        {
            gets(t) ;
            sscanf(t,"%d",&cost[i]) ; teach[i]=0 ;
            int j=0 ;
            for(;j<strlen(t) && t[j]>='0' && t[j]<='9';j++) ;
            for(;j<strlen(t) && t[j]==' ';j++) ;
            while(j<strlen(t))
            {
                int a ; sscanf(&t[j],"%d",&a) ;
                teach[i] |= (1<<(a-1)) ;
                for(;j<strlen(t) && t[j]>='0' && t[j]<='9';j++) ;
                for(;j<strlen(t) && t[j]==' ';j++) ;
            }
            //printf("teach[%d]=%d\n",i,teach[i]) ;
        }
        for(int i=m+n+1;i>=1;i--) for(int s1=0;s1<(1<<s);s1++)
            for(int s2=0;s2<(1<<s);s2++) if(!(s1&s2))
        {
            int s0=((1<<s)-1) ; s0^=s1 ; s0^=s2 ;
            if(i==m+n+1) {dp[m+n+1][s1][s2]= (s1||s2 ? INF : 0) ; continue ; }
            dp[i][s1][s2]=INF ;
            int t1=teach[i]&s1 , t2=teach[i]&s2 ;
            dp[i][s1][s2]=min(dp[i][s1][s2],dp[i+1][s1-t1+t2][s2-t2]+cost[i]) ;
            if(i>m) dp[i][s1][s2]=min(dp[i][s1][s2],dp[i+1][s1][s2]) ;
            //printf("dp[%d][%d][%d]=%d\n",i,s1,s2,dp[i][s1][s2]) ;
        }
        printf("%d\n",dp[1][0][(1<<s)-1]) ;
    }
}
