#include<bits/stdc++.h>
#define INF 2100000000
using namespace std;
struct P{int to,dis;};

int n,m,w[350],fa[350],d[350] ;
int dp[350][350][54] ;
vector<P> v[350] ;

void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
        d[v[x][i].to]=d[x]+v[x][i].dis , dfs(v[x][i].to) ;

    if(v[x].empty())
    {
        for(int i=x;i!=-1;i=fa[i]) for(int j=0;j<=m+1;j++)
            dp[x][i][j]= j?0:w[x]*(d[x]-d[i]) ;
        return ;
    }

    for(int i=x;i!=-1;i=fa[i]) for(int j=0;j<=m+1;j++)
    {
        int &ans=dp[x][i][j] ; ans=INF ;
        if(j)
        {
            if(v[x].size()==2)
            {
                int l=v[x][0].to , r=v[x][1].to ;
                for(int z=0;z<j;z++)
                    ans=min(ans,dp[l][x][z]+dp[r][x][j-1-z]) ;
            }
            else ans=min(ans,dp[v[x][0].to][x][j-1]) ;
        }
        if(i==0 && x==0 && j==m+1) continue ;
        if(v[x].size()==2)
        {
            int l=v[x][0].to , r=v[x][1].to ;
            for(int z=0;z<=j;z++)
                ans=min(ans,w[x]*(d[x]-d[i])+dp[l][i][z]+dp[r][i][j-z]) ;
        }
        else ans=min(ans,w[x]*(d[x]-d[i])+dp[v[x][0].to][i][j]) ;
    }
}

main()
{
    scanf("%d%d",&n,&m) ;
    fa[0]=-1 ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d%d",&w[i],&x,&y) ;
        v[x].push_back((P){i,y}) ;
        fa[i]=x ;
    }

    int cnt=n+1 ;
    for(int i=0;i<=n;i++) if(v[i].size()>2)
    {
        int sz=v[i].size() , tmp=cnt ;
        for(int j=1;j<sz-2;j++)
            v[cnt].push_back(v[i][j]) , v[cnt].push_back((P){cnt+1,0}) ,
            fa[v[i][j].to]=fa[cnt+1]=cnt , cnt++ ;
        v[cnt].push_back(v[i][sz-2]) ;
        v[cnt].push_back(v[i][sz-1]) ;
        fa[v[i][sz-2].to]=fa[v[i][sz-1].to]=cnt ;
        cnt++ ;
        v[i][1]=(P){tmp,0} ; fa[tmp]=i ;
        v[i].resize(2) ;
    }

    dfs(0) ;
    printf("%d\n",dp[0][0][m+1]) ;
}
