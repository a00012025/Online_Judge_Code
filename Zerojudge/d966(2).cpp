#include<bits/stdc++.h>
using namespace std;
int n,m,t,topo[500],scc[500] ;
vector<int> v[500],v2[500] ;
bool vis[5000] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs1(v[x][i]) ;
    topo[--t]=x ;
}

int scc_cnt ;
void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scc_cnt ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs2(v2[x][i]) ;
}

void find_SCC()
{
    memset(vis,0,sizeof(vis)) ;
    t=2*(m+n) ;
    for(int i=0;i<2*(m+n);i++) if(!vis[i]) dfs1(i) ;
    for(int i=0;i<2*(m+n);i++) v2[i].clear();
    for(int i=0;i<2*(m+n);i++) for(int j=0;j<v[i].size();j++) v2[v[i][j]].push_back(i) ;
    memset(vis,0,sizeof(vis)) ;
    scc_cnt=0 ;
    for(int i=0;i<2*(m+n);i++) if(!vis[topo[i]])
    {
        scc_cnt++ ;
        dfs2(topo[i]) ;
    }

    // 0 ~ 2*(m+n)-1 !!!!!!!!!!
}

main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        int k ;
        scanf("%d%d%d",&n,&m,&k) ;
        for(int i=0;i<2*(n+m);i++) v[i].clear() ;
        while(k--)
        {
            int x,y,type ; scanf("%d%d%d",&x,&y,&type) ;
            if(type==0)
            {
                v[y].push_back(y+m+n) ;
                v[x+m].push_back(x+2*m+n) ;
            }
            else if(type==1)
            {
                v[y+m+n].push_back(y) ;
                v[x+2*m+n].push_back(x+m) ;
            }
            else if(type==2)
            {
                v[y].push_back(x+2*m+n) ;
                v[x+m].push_back(y+m+n) ;
            }
            else
            {
                v[y+m+n].push_back(x+m) ;
                v[x+2*m+n].push_back(y) ;
            }
        }
            // 0 ~ 2(m+n)-1 !!!!!!!!!!
        find_SCC() ;
        bool yes=1 ;
        for(int i=0;i<m+n;i++) if(scc[i]==scc[i+m+n]) {yes=0 ; break ;}
        if(yes) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
