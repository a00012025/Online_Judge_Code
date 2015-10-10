#include<stdio.h>
#include<string.h>
double dp[21][21][21],ch[21][21] ;
int fa[21][21][21],ans[20] ;

void found_ans(int i,int j,int r)
{
    ans[r]=j ;
    if(r==0) return ;
    found_ans(i,fa[i][j][r],r-1) ;
}

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            if(i==j) ch[i][j]=1 ;
            else scanf("%lf",&ch[i][j]) ;
        memset(dp,0.0,sizeof(dp)) ;
        for(int i=1;i<=n;i++) dp[i][i][0]=1 ;
        bool found=0 ; int ansnum ;
        for(int r=1;r<=n;r++)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=n;k++)
                    if(dp[i][k][r-1]*ch[k][j]>dp[i][j][r])
            {
                dp[i][j][r] = dp[i][k][r-1]*ch[k][j] ;
                fa[i][j][r] = k ;
            }
            for(int i=1;i<=n;i++) if(dp[i][i][r]>1.01)
            {
                found_ans(i,i,r) ;
                ansnum=r ;
                found=1 ;
                break ;
            }
            if(found) break ;
        }
        if(found) for(int i=0;i<=ansnum;i++)
            printf("%d%c",ans[i],i==ansnum?'\n':' ') ;
        else printf("no arbitrage sequence exists\n") ;
    }
}
