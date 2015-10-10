#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

int d[101][101] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            {scanf("%d",&d[i][j]) ; if(!d[i][j]) d[i][j]=INF ;}
        for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]) ;
        int ans=INF ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            ans=min(ans,d[i][j]+d[j][i]) ;
        if(ans==INF) printf("-1\n") ;
        else printf("%d\n",ans) ;
    }
}
