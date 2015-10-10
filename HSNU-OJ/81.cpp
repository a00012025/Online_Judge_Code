#include<bits/stdc++.h>
using namespace std;

int sum[3][1001][1001] ;
int G[1001][1001] ;
char s[1001] ;
main()
{
    int n,m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1) ;
        for(int j=1;j<=m;j++)
        {
            if(s[j]=='J') G[i][j]=0 ;
            if(s[j]=='O') G[i][j]=1 ;
            if(s[j]=='I') G[i][j]=2 ;
        }
    }
    for(int k=0;k<3;k++) for(int i=0;i<=1000;i++) sum[k][0][i]=sum[k][i][0]=0 ;
    for(int k=0;k<3;k++) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        int add= G[i][j]==k ? 1 : 0 ;
        sum[k][i][j]=sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1]+add ;
    }
    while(Q--)
    {
        int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
        for(int i=0;i<3;i++)
        {
            int ans=sum[i][x2][y2]-sum[i][x2][y1-1]-sum[i][x1-1][y2]+sum[i][x1-1][y1-1] ;
            printf("%d%c",ans,i==2?'\n':' ') ;
        }
    }
}
