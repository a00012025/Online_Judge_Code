#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10,maxm=400000+10 ;
struct P
{
    int x,y,dis,id ;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};

struct Q{int x,y;};

vector<P> E ;

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

bool ans[maxm] ;
int ver[maxm],cnt ;
int eid[maxm] ;
vector<Q> edge ;
vector<int> v[maxn] ;
bool vis[maxn],evis[maxm] ;
int lev[maxn] ;

int dfs(int x,int l)
{
    int low ;
    lev[x]=low=l ;
    vis[x]=1 ;
    for(auto i : v[x]) if(!evis[i])
    {
        evis[i]=1 ;
        int to= edge[i].x==x ? edge[i].y : edge[i].x ;
        if(vis[to]) low=min(low,lev[to]) ;
        else
        {
            int tmp=dfs(to,l+1) ;
            low=min(low,tmp) ;
            if(tmp > lev[x]) ans[eid[i]]=1 ;
        }
    }
    return low ;
}

void Kruskal()
{
    sort(E.begin(),E.end()) ;
    for(int i=0;i<E.size();)
    {
        cnt=0 ;
        edge.clear() ;
        int j ;
        for(j=i;j<E.size() && E[j].dis==E[i].dis;j++) ;
        for(int k=i;k<j;k++)
        {
            int x=getfa(E[k].x) , y=getfa(E[k].y) ;
            if(x==y) continue ;
            ver[cnt++]=x ; ver[cnt++]=y ;
            v[x].clear() ; v[y].clear() ;
            vis[x]=vis[y]=0 ;
        }
        for(int k=i;k<j;k++)
        {
            int x=getfa(E[k].x) , y=getfa(E[k].y) ;
            if(x==y) continue ;

            edge.push_back((Q){x,y}) ;
            int sz=edge.size() ;
            v[x].push_back(sz-1) ;
            v[y].push_back(sz-1) ;
            eid[sz-1]=E[k].id ;
            evis[sz-1]=0 ;
        }

        for(int k=0;k<cnt;k++) if(!vis[ver[k]])
            dfs(ver[k],0) ;

        for(int k=i;k<j;k++) fa[getfa(E[k].x)]=getfa(E[k].y) ;
        i=j ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) fa[i]=i ;
    for(int i=0;i<m;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        E.push_back((P){x,y,dis,i+1}) ;
    }
    Kruskal() ;
    int num=count(ans+1,ans+m+1,true) ;
    printf("%d\n",num) ;
    if(!num) printf("0\n") ;
    else for(int i=1;i<=m;i++) if(ans[i]) printf("%d%c",i,(--num)?' ':'\n') ;
}
