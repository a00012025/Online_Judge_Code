#include<bits/stdc++.h>
using namespace std;
const int maxn=200 ;

char G[maxn][maxn] ;
int n,m ;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1} ;

int cal(char a,char b)
{
    int ret=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]==a)
        for(int z=0;z<8;z++)
    {
        bool ok=1 ;
        for(int t=1;t<3;t++)
        {
            int nx=i+t*dx[z] , ny=j+t*dy[z] ;
            if(nx<0||nx>=n||ny<0||ny>=m) { ok=0 ; break ; }
            if(G[nx][ny]!=b) { ok=0 ; break ; }
        }
        if(ok) ret++ ;
    }
    return ret ;
}

main()
{
    freopen("moocrypt.in","r",stdin) ;
    freopen("moocrypt.out","w",stdout) ;
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    int ans=0 ;
    for(int i=0;i<26;i++) if('A'+i!='M')
        for(int j=0;j<26;j++) if('A'+j!='O')
        if(i!=j) ans=max(ans,cal('A'+i,'A'+j)) ;
    printf("%d\n",ans) ;
}
