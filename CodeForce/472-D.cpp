#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[2001] ;
bool vis[2001] ;
int G[2001][2001],n ;
int dis[2001] ;

bool prim()
{
    int id[2001],key[2001],last=1 ;
    int newid,newnum ;
    memset(vis,0,sizeof(vis)) ;
    bool no=0 ; vis[1]=1 ;
    for(int i=1;i<=n;i++) key[i]=2000000000 ;
    for(int i=2;i<=n;i++)
    {
        newnum=2000000000 ;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]) continue ;
            if(G[j][last]<key[j])
                {key[j]=G[j][last] ; id[j]=last ; no=0 ; }
            else if(G[j][last]==key[j]) no=1 ;

            if(key[j]<newnum) {newnum=key[j] ; newid=j ;}
        }
        if(no) return 0 ;
        v[id[newid]].push_back(newid) ;
        v[newid].push_back(id[newid]) ;
        vis[newid]=1 ; last=newid ;
    }
    return 1;
}

void dfs(int x,int num)
{
    vis[x]=1 ; dis[x]=num ;
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]]) dfs(v[x][i],num+G[x][v[x][i]]) ;
}

bool check()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dis[j]=2000000000 ;
        dis[i]=0 ;
        memset(vis,0,sizeof(vis)) ;
        dfs(i,0) ;
        for(int j=i+1;j<=n;j++) if(G[i][j]!=dis[j]) return 0 ;
    }
    return 1 ;
}

main()
{
    int no=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        scanf("%d",&G[i][j]) ;
        if(i==j && G[i][j]!=0) no=1 ;
        else if(i!=j && G[i][j]==0) no=1 ;
        else if(i>j && G[i][j]!=G[j][i]) no=1 ;
    }
    if(no) printf("NO\n") ;
    else if(!prim()) printf("NO\n");
    else if(!check()) printf("NO\n");
    else printf("YES\n");
}

