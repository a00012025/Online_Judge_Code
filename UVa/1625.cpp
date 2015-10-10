#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 200000000
using namespace std;
int dp[5001][5001],num[5001][5001],n,m ;
char s[5001],t[5001] ;
int fir1[27],las1[27],fir2[27],las2[27] ;

void pre_cal()
{
    memset(fir1,-1,sizeof(fir1)) ;
    memset(las1,-1,sizeof(las1)) ;
    memset(fir2,-1,sizeof(fir2)) ;
    memset(las2,-1,sizeof(las2)) ;
    for(int i=1;i<=n;i++) if(fir1[s[i]-'A']==-1) fir1[s[i]-'A']=i ;
    for(int i=1;i<=m;i++) if(fir2[t[i]-'A']==-1) fir2[t[i]-'A']=i ;
    for(int i=n;i>=1;i--) if(las1[s[i]-'A']==-1) las1[s[i]-'A']=i ;
    for(int i=m;i>=1;i--) if(las2[t[i]-'A']==-1) las2[t[i]-'A']=i ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%s",s+1,t+1) ;
        n=strlen(s+1) ; m=strlen(t+1) ;
        pre_cal() ;
        dp[0][0]=0 ; num[0][0]=0 ;
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) if(i||j)
        {
            dp[i][j]=INF ;
            if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+num[i-1][j]) ;
            if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+num[i][j-1]) ;
            num[i][j]= i ? num[i-1][j] : num[i][j-1] ;
            if(i)
            {
                int c=s[i]-'A' ;
                if(fir1[c]==i && (fir2[c]==-1 || fir2[c]>j)) num[i][j]++ ;
                if(las1[c]==i && (las2[c]==-1 || las2[c]<=j)) num[i][j]-- ;
            }
            else
            {
                int c=t[j]-'A' ;
                if(fir2[c]==j && (fir1[c]==-1 || fir1[c]>i)) num[i][j]++ ;
                if(las2[c]==j && (las1[c]==-1 || las1[c]<=i)) num[i][j]-- ;
            }
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]) ;
        }
        printf("%d\n",dp[n][m]) ;
    }
}
