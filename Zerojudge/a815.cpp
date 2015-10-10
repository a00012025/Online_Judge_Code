#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> v[100000] ;
bool a[311][311],vis[100000] ;
int n,m,yes,lev[100000],low[100000] ;
int dx[6]={1,1,0,-1,-1,0} ;
int dy[6]={0,-1,-1,0,1,1} ;

int id(int x,int y)
{
    return (m*(x-1)+y) ;
}

bool dfs(int x,int l)
{
    vis[x]=1 ; lev[x]=l ; low[x]=l ;
    bool ret=0 ;
    for(int i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i]]) low[x]=min(low[x],lev[v[x][i]]) ;
        else
        {
            if(dfs(v[x][i],l+1))
            {
                if(low[v[x][i]]>=l && x!=1) yes=1 ;
                ret=1 ;
            }
            low[x]=min(low[x],low[v[x][i]]) ;
        }
    }
    if(ret) return true ;
    if(x==n*m) return true ;
    return false ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d %d",&n,&m) ;
        for(int i=0;i<=n+1;i++){a[i][0]=1 ; a[i][m+1]=1 ;}
        for(int i=0;i<=m+1;i++){a[0][i]=1 ; a[n+1][i]=1 ;}
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char c ;
            scanf("%c",&c) ;
            while(c!='.' && c!='O') scanf("%c",&c) ;
            if(c=='O') a[i][j]=1 ;
            else a[i][j]=0 ;
        }
        for(int i=0;i<=n*m+10;i++) v[i].clear() ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            if(a[i][j]) continue ;
            for(int k=0;k<6;k++)
                if(!a[i+dx[k]][j+dy[k]])
                    v[id(i,j)].push_back(id(i+dx[k],j+dy[k])) ;
        }
        yes=0 ;
        if(!dfs(1,0)) printf("0\n") ;
        else if(yes) printf("1\n") ;
        else printf("2\n") ;
    }
}
