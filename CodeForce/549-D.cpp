#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

char G[maxn][maxn] ;
int now[maxn][maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    int ans=0 ;
    for(int i=n-1;i>=0;i--) for(int j=m-1;j>=0;j--)
    {
        if(G[i][j]=='W')
        {
            if(now[i][j]==1) continue ;
            int val=1-now[i][j] ;
            for(int x=0;x<=i;x++) for(int y=0;y<=j;y++)
                now[x][y]+=val ;
            ans++ ;
        }
        else
        {
            if(now[i][j]==-1) continue ;
            int val=-1-now[i][j] ;
            for(int x=0;x<=i;x++) for(int y=0;y<=j;y++)
                now[x][y]+=val  ;
            ans++ ;
        }
    }
    printf("%d\n",ans) ;
}
