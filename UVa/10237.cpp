#include<stdio.h>
#define LL long long
LL dp1[31][1000],dp2[31][1000] ;

void init()
{
    for(int i=0;i<=30;i++) for(int j=0;j<1000;j++) dp1[i][j]=dp2[i][j]=(LL)0 ;
    for(int i=0;i<=30;i++) {dp1[i][0]=(LL)1 ; dp2[i][0]=(LL)1 ;}
    dp1[1][1]=(LL)1 ;
    for(int i=2;i<=30;i++)
    {
        int n=2*((i-1)/2)+1 ;
        for(int j=1;j<=900;j++)
            dp1[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*((LL)n-j+1) ;
    }

    for(int i=2;i<=30;i++)
    {
        int n=(i/2)*2 ;
        for(int j=1;j<=900;j++)
            dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1]*((LL)n-j+1) ;
    }
}

main()
{
    init() ;
    int n,k ;
    while(scanf("%d %d",&n,&k)==2 && n+k)
    {
        LL ans=0 ;
        for(int i=0;i<=k;i++) ans+=dp1[n][i]*dp2[n][k-i] ;
        printf("%lld\n",ans) ;
    }

}
