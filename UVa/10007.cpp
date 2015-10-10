#include<stdio.h>
int ans[301][1000]={{0}} ;
main()
{
    ans[1][0]=1 ;
    for(int n=2;n<=300;n++)
    {
        ans[n][0]=n+2 ;
        for(int j=n+3;j<=2*n;j++)
        {
            int num ;
            for(num=999;ans[n][num]==0;num--) ;
            for(int k=num;k>=0;k--) ans[n][k]*=j ;
            for(int k=0;k<=num+3;k++) if(ans[n][k]>=10000)
            {
                ans[n][k+1]+=ans[n][k]/10000 ;
                ans[n][k]%=10000 ;
            }
        }
    }
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        int num ;
        for(num=999;ans[n][num]==0;num--) ;
        printf("%d",ans[n][num]) ;
        for(int k=num-1;k>=0;k--)printf("%04d",ans[n][k]);
        printf("\n");
    }
}
