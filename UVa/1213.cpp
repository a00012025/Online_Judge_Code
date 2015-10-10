#include<stdio.h>
#include<string.h>
bool a[2000] ;
int p[500],ans ;
int dp[188][20][2000] ;
main()
{
    for(int i=1;i<2000;i++) a[i]=1 ;
    a[1]=0 ; a[2]=1 ;
    for(int i=2;i<2000;i++) if(a[i])
        for(int j=2*i;j<2000;j+=i) a[j]=0 ;
    int cnt=0 ;
    for(int i=1;i<2000;i++) if(a[i]) p[++cnt]=i ;


    memset(dp,0,sizeof(dp)) ;
    dp[0][0][0]=1 ;
    for(int i=1;i<=187;i++) for(int j=0;j<=15;j++) for(int k=0;k<=1120;k++)
    {
        dp[i][j][k]=dp[i-1][j][k] ;
        if(k>=p[i] && j) dp[i][j][k]+=dp[i-1][j-1][k-p[i]] ;
    }
    //for(int i=1;)

    int n,m ;
    while(scanf("%d %d",&n,&m)==2 && n+m)
    {
        printf("%d\n",dp[187][m][n]) ;
    }
}

