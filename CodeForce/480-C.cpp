#include<stdio.h>
#define LL long long
#define MOD 1000000007
LL dp[5001][5001]={0} ;
main()
{
    int n,a,b,k ;
    scanf("%d%d%d%d",&n,&a,&b,&k) ;
    if(a>b) {a=n+1-a ; b=n+1-b ;}
    dp[a][0]=1LL ;
    for(int i=1;i<=k;i++)
    {
        LL sum=0 ;
        int r=b-2 ;
        for(int j=1;j<=b-2;j++) {sum+=dp[j][i-1] ; sum%=MOD ;}
        for(int j=b-1;j>=1;j--)
        {
            while(2*r-b+1>j)
            {
                sum -= dp[r][i-1] ;
                if(sum<0) sum+=MOD ;
                sum%=MOD ; r-- ;
            }
            dp[j][i]=sum ;
            if(r>=j)
            {
                dp[j][i]-=dp[j][i-1] ;
                if(dp[j][i]<0) dp[j][i]+=MOD ;
                dp[j][i]%=MOD ;
            }
        }
    }
    LL ans=0LL ;
    for(int i=1;i<b;i++) {ans+=dp[i][k] ; ans%=MOD ;}
    printf("%I64d\n",ans) ;
}
