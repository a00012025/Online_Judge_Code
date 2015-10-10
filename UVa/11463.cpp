#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=10000000 ;
int d[101][101] ;
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,st,ed;
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            d[i][j]= (i==j ? 0 : INF) ;
        while(m--)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            d[a][b]=1 ; d[b][a]=1 ;
        }
        scanf("%d%d",&st,&ed) ;
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]) ;
        int ans=0 ;
        for(int i=0;i<n;i++) ans=max(ans,d[st][i]+d[i][ed]) ;
        printf("Case %d: %d\n",++tc,ans) ;
    }
}
