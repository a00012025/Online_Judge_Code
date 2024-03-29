#include<bits/stdc++.h>
using namespace std;
const int maxn=50+10 ;

struct P{int x,y;}a[maxn*maxn];
char ans[2*maxn][2*maxn],G[maxn][maxn] ;
int n,cnt=0 ;

bool check(int dx,int dy)
{
    for(int j=0;j<cnt;j++)
    {
        int nx=a[j].x+dx , ny=a[j].y+dy ;
        if(nx<0||nx>=n||ny<0||ny>=n) continue ;
        if(G[nx][ny]=='.') return 0 ;
    }
    return 1 ;
}

void add(int dx,int dy)
{
    ans[n-1+dx][n-1+dy]='x' ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<2*n-1;i++) for(int j=0;j<2*n-1;j++)
        ans[i][j]='.' ;
    ans[n-1][n-1]='o' ;
    for(int i=0;i<n;i++)
    {
        scanf("%s",G[i]) ;
        for(int j=0;j<n;j++) if(G[i][j]=='o')
            a[cnt++]=(P){i,j} ;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(G[i][j]=='x')
    {
        bool ok=0 ;
        for(int k=0;k<cnt;k++) if(check(i-a[k].x,j-a[k].y))
        {
            add(i-a[k].x,j-a[k].y) ;
            ok=1 ;
            break ;
        }
        if(!ok) {printf("NO\n") ; return 0 ;}
    }
    printf("YES\n") ;
    for(int i=0;i<2*n-1;i++) printf("%s\n",ans[i]) ;
}
