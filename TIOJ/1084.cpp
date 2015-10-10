#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;
struct P{int x,y;};
vector<P> edge ;
vector<int> v[maxn] ;

bool cmp(int a,int b)
{
    if(edge[a].x==edge[b].x) return edge[a].y<edge[b].y ;
    if(edge[a].x==edge[b].y) return edge[a].y<edge[b].x ;
    if(edge[a].y==edge[b].x) return edge[a].x<edge[b].y ;
    if(edge[a].y==edge[b].y) return edge[a].x<edge[b].x ;
}

bool vis[maxn] ;
int ans[maxn],cnt ;
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
    {
        P &e=edge[v[x][i]] ;
        int to= e.x==x ? e.y : e.x ;
        vis[v[x][i]]=1 ;
        dfs(to) ;
    }
    ans[cnt++]=x ;
}

main()
{
    int m ;
    while(scanf("%d",&m)==1 && m)
    {
        edge.clear() ;
        for(int i=0;i<maxn;i++) v[i].clear() ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<m;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            edge.push_back((P){x,y}) ;
            v[x].push_back(i) ;
            v[y].push_back(i) ;
        }
        bool odd=0 ;
        int st=maxn ;
        for(int i=1;i<maxn;i++) if(!v[i].empty())
        {
            sort(v[i].begin(),v[i].end(),cmp) ;
            if(v[i].size()%2)
            {
                if(!odd) odd=1 , st=i ;
                else st=min(st,i) ;
            }
            else st=min(st,i) ;
        }
        cnt=0 ;
        dfs(st) ;
        for(int i=cnt-1;i>=0;i--) printf("%d\n",ans[i]) ;
        printf("\n") ;
    }
}
