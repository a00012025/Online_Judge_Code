#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v[4*maxn] ;
inline void add_edge(int a,int b)
{
    v[a].push_back(b) ;
    v[b].push_back(a) ;
}

int x[maxn],y[maxn] ;
int u[maxn],d[maxn],l[maxn],r[maxn],deg[maxn] ;
int gp[4*maxn],ccnt ;
bool vis[4*maxn] ;
vector<int> v0[maxn],cc[2*maxn] ;
int lev[2*maxn],n,m ;

void dfs(int now)
{
    vis[now]=1 ; gp[now]=ccnt ; cc[ccnt].push_back(now) ;
    for(int i=0;i<v[now].size();i++) if(!vis[v[now][i]])
        dfs(v[now][i]) ;
}

void dfs2(int now,int &id,int &My)
{
    vis[now]=1 ; if(y[now]>My) My=y[id=now] ;
    for(int i=0;i<v0[now].size();i++) if(!vis[v0[now][i]])
        dfs2(v0[now][i],id,My) ;
}

queue<int> q ;
vector<int> ans ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]) ;
    scanf("%d",&m) ;
    for(int i=1;i<=m;i++)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        v0[a].push_back(b) ; v0[b].push_back(a) ;
        deg[a]++ ; deg[b]++ ;
        if(x[a]==x[b])
        {
            if(y[a]>y[b]) d[a]=u[b]=i ;
            else u[a]=d[b]=i ;
        }
        else
        {
            if(x[a]>x[b]) l[a]=r[b]=i ;
            else r[a]=l[b]=i ;
        }
    }
    for(int i=1;i<=n;i++) if(deg[i])
    {
        if(deg[i]==1)
        {
            if(u[i]) add_edge(u[i],u[i]+m) ;
            else if(d[i]) add_edge(d[i],d[i]+m) ;
            else if(l[i]) add_edge(l[i],l[i]+m) ;
            else add_edge(r[i],r[i]+m) ;
            continue ;
        }
        if(u[i] && r[i])
        {
            add_edge(u[i]+m,r[i]) ;
            if(!d[i] && !l[i]) add_edge(u[i],r[i]+m) ;
        }
        if(r[i] && d[i])
        {
            add_edge(r[i]+m,d[i]+m) ;
            if(!l[i] && !u[i]) add_edge(r[i],d[i]) ;
        }
        if(d[i] && l[i])
        {
            add_edge(d[i],l[i]+m) ;
            if(!u[i] && !r[i]) add_edge(d[i]+m,l[i]) ;
        }
        if(l[i] && u[i])
        {
            add_edge(l[i],u[i]) ;
            if(!r[i] && !d[i]) add_edge(l[i]+m,u[i]+m) ;
        }
        if(deg[i]==4) continue ;
        if(l[i] && r[i])
        {
            if(!u[i]) add_edge(l[i],r[i]) ;
            if(!d[i]) add_edge(l[i]+m,r[i]+m) ;
        }
        if(u[i] && d[i])
        {
            if(!l[i]) add_edge(u[i],d[i]) ;
            if(!r[i]) add_edge(u[i]+m,d[i]+m) ;
        }
    }

    ccnt=0 ;
    for(int i=1;i<=2*m;i++) if(!vis[i])
        ccnt++ , dfs(i) ;

    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(deg[i] && !vis[i])
    {
        int st,M=-1 ;
        dfs2(i,st,M) ;
        if(l[st]) st=gp[l[st]] ;
        else if(r[st]) st=gp[r[st]] ;
        else st=gp[d[st]] ;

        lev[st]=1 ;
        for(int i=0;i<cc[st].size();i++) q.push(cc[st][i]) ;
    }

    while(!q.empty())
    {
        int now=q.front() ; q.pop() ;
        int now2= now>m ? now-m : now+m ;
        if(!lev[gp[now2]])
        {
            lev[gp[now2]]=lev[gp[now]]+1 ;
            for(int i=0;i<cc[gp[now2]].size();i++)
                q.push(cc[gp[now2]][i]) ;
        }
        else if(now<=m && lev[gp[now2]]==lev[gp[now]]) ans.push_back(now) ;
    }

    sort(ans.begin(),ans.end()) ;
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]) ;
}

