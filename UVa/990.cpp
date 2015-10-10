#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int dp[31][100001],d[31],v[31] ;
int anc[31][100001],ANS[50] ;
main()
{
    int tc=0,m,t ;
    while(scanf("%d %d",&m,&t)!=EOF)
    {
        int n ;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d %d",&d[i],&v[i]) ;
        memset(anc,0,sizeof(anc)) ;
        memset(dp,0,sizeof(dp)) ;
        memset(ANS,0,sizeof(ANS)) ;
        for(int i=1;i<=m;i++) dp[0][i]=-2100000000;
        int ans=0,ansnum ;
        for(int i=1;i<=n;i++)
        {
            int w=(d[i]*t)*3 ;
            for(int j=0;j<=m;j++)
            {
                if(j+w<=m)
                    {dp[i][j+w]=dp[i-1][j]+v[i] ; anc[i][j+w]=j ;}
                if(dp[i-1][j]>dp[i][j])
                    {dp[i][j]=dp[i-1][j] ; anc[i][j]=j ;}
                if(i==n && dp[i][j]>ans) {ans=dp[i][j] ; ansnum=j ;}
            }
        }
        if(tc++) printf("\n") ;
        printf("%d\n",ans) ;
        int cnt=0 , j=ansnum ;
        for(int i=n;i>=1 && j;i--)
        {
            if(anc[i][j]!=j) ANS[++cnt]=i ;
            j=anc[i][j] ;
        }
        printf("%d\n",cnt) ;
        for(int i=cnt;i>=1;i--)printf("%d %d\n",d[ANS[i]],v[ANS[i]]) ;
    }
}
