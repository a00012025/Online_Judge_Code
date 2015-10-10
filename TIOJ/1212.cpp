#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=500+5 ;

int d[maxn][maxn] ;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            d[i][j]=INF ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            d[x][y]=1 ;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]) ;
        int ans=INF ;
        for(int i=1;i<=n;i++) ans=min(ans,d[i][i]) ;
        printf("%d\n",ans==INF ? 0 : ans) ;
    }
}
