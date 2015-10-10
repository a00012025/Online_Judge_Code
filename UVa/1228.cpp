#include<stdio.h>
#include<string.h>
#define ULL unsigned long long
int a[70],n,d ;
int zero[70],one[70],num0,num1 ;
ULL dp[70][70],N ;

ULL big()
{
    int now0=0 , now1=0 ;
    ULL ret=(ULL)0 ;
    for(int i=1;i<=n;i++)
    {
        if(now0==num0 || (now1<num1 && zero[now0+1]+d>=one[now1+1]))
        {
            ret*=(ULL)2 ;
            ret+=(ULL)1 ;
            now1++ ;
        }
        else
        {
            ret*=(ULL)2 ;
            now0++ ;
        }
    }
    return ret ;
}

ULL small()
{
    int now0=0 , now1=0 ;
    ULL ret=(ULL)0 ;
    for(int i=1;i<=n;i++)
    {
        if(now1==num1 || (now0<num0 && one[now1+1]+d>=zero[now0+1]))
        {
            ret*=(ULL)2 ;
            now0++ ;
        }
        else
        {
            ret*=(ULL)2 ;
            ret+=(ULL)1 ;
            now1++ ;
        }
    }
    return ret ;
}

main()
{
    int tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d%llu",&d,&N) ;
        num1=num0=0 ;
        for(int i=n;i>=1;i--) {a[i]= N%2 ? 1 : 0 ; N=N/2 ;}
        for(int i=1;i<=n;i++)
        {
            if(a[i]) one[++num1]=i ;
            else zero[++num0]=i ;
        }

        memset(dp,(ULL)0,sizeof(dp)) ;
        dp[0][0]=(ULL)1 ;
        for(int i=0;i<=num0;i++) for(int j=0;j<=num1;j++)
        {
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]) ;
            if((i==num0 && j!=num1) || (i<num0 && j<num1 && zero[i+1]+d>=one[j+1]))
                dp[i][j+1] += dp[i][j] ;
            if((j==num1 && i!=num0) || (j<num1 && i<num0 && one[j+1]+d>=zero[i+1]))
                dp[i+1][j] += dp[i][j] ;
        }
        printf("Case %d: %llu %llu %llu\n",++tc,dp[num0][num1],small(),big()) ;
    }
}
