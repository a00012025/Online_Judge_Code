#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10,maxm=500000+10 ;

struct P{int x,y;};
vector<int> v[maxn] ;
vector<P> edge ;

int lev[maxn],bcnt ;
vector<int> vb[maxm] ;
int adj[maxn][maxn] ;
bool vis[maxn],ans[maxn] ;
bool vis_e[maxm] ;
stack<int> st ;

int dfs(int x,int l)
{
    int low ;
    vis[x]=1 ; low=lev[x]=l ;
    for(auto i : v[x])
    {
        if(vis_e[i]) continue ;
        vis_e[i]=1 ; st.push(i) ;

        int to= (edge[i].x==x ? edge[i].y : edge[i].x) ;
        if(vis[to]) low=min(low,lev[to]) ;
        else
        {
            int low2=dfs(to,l+1) ;
            low=min(low,low2) ;
            if(low2>=lev[x])
            {
                bcnt++ ; vb[bcnt].clear() ;
                while(1)
                {
                    int t=st.top() ; st.pop() ;
                    vb[bcnt].push_back(t) ;
                    if(t==i) break ;
                }
            }
        }
    }
    return low ;
}

int col[maxn] ;
bool dfs2(int x,int c)
{
    col[x]=c ;
    for(auto i : v[x])
    {
        int to= edge[i].x==x ? edge[i].y : edge[i].x ;
        if(col[to]==c || (col[to]==-1 && !dfs2(to,c^1))) return 0 ;
    }
    return 1 ;
}

int tmp[maxm] ;
main()
{
    int n,m,tc ;
    while(scanf("%d%d",&n,&m)==2 && m+n && ++tc)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        edge.clear() ;
        for(int i=0;i<m;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            adj[x][y]=adj[y][x]=tc ;
        }
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            if(adj[i][j]!=tc)
        {
            edge.push_back((P){i,j}) ;
            int s=edge.size() ;
            v[i].push_back(s-1) ;
            v[j].push_back(s-1) ;
        }

        bcnt=0 ;
        memset(ans,0,sizeof(ans)) ;
        memset(vis,0,sizeof(vis)) ;
        memset(vis_e,0,sizeof(vis_e)) ;
        for(int i=1;i<=n;i++) if(!vis[i] && !v[i].empty())
        {
            while(!st.empty()) st.pop() ;
            dfs(i,0) ;
        }

        for(int i=1;i<=bcnt;i++)
        {
            int sz=0 ;
            for(auto j : vb[i])
                tmp[sz++]=edge[j].x , tmp[sz++]=edge[j].y ;
            for(int j=0;j<sz;j++) v[tmp[j]].clear() , col[tmp[j]]=-1 ;
            for(auto j : vb[i])
                v[edge[j].x].push_back(j) ,
                v[edge[j].y].push_back(j) ;
            if(!dfs2(tmp[0],0))
                for(int j=0;j<sz;j++) ans[tmp[j]]=1 ;
        }
        printf("%d\n",count(ans+1,ans+n+1,false)) ;
    }
}
