#include<bits/stdc++.h>
using namespace std;
const int maxn=400 ;

int a[maxn],inv[maxn],ans[maxn] ;
char G[maxn][maxn] ;
bool d[maxn][maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , inv[a[i]]=i ;
    for(int i=1;i<=n;i++) scanf("%s",&G[i][1]) ;
    memset(d,0,sizeof(d)) ;
    for(int i=1;i<=n;i++) d[i][i]=1 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(G[i][j]=='1')
        d[i][j]=1 ;
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(d[k][j]==1) d[i][j]|=d[i][k] ;
    memset(ans,0,sizeof(ans)) ;
    for(int i=1;i<=n;i++)
    {
        int j ;
        for(j=1;ans[j]||!d[inv[i]][j];j++) ;
        ans[j]=i ;
    }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
