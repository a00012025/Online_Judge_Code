#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
struct P{int to,dis;};
const int maxn=100000+10 ;
vector<P> v[maxn] ;
bool vis[maxn] ;
int ans=0 ;
int fa[maxn],d[maxn] ;
void dfs(int x,int &M,int &id)
{
    vis[x]=1 ;
    if(d[x]>M) M=d[id=x] ;
    for(int i=0;i<v[x].size();i++) if(v[x][i].to!=fa[x])
    {
        fa[v[x][i].to]=x ;
        d[v[x][i].to]=d[x]+v[x][i].dis ;
        dfs(v[x][i].to,M,id) ;
    }
}

int min_len(int x)
{
    if(v[x].empty()) return 0 ;
    fa[x]=x ; d[x]=0 ;
    int id,M=-1 ;
    dfs(x,M,id) ;
    fa[id]=id ; d[id]=0 ;
    int id2 ; M=-1 ;
    dfs(id,M,id2) ;
    ans=max(ans,M) ;
    int ret=INF ;
    for(int i=id2;i!=id;i=fa[i])
        ret=min(ret,max(d[i],M-d[i])) ;
    return ret ;
}

priority_queue<int> pq ;
main()
{
    int n,m,L ; scanf("%d%d%d",&n,&m,&L) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    for(int i=0;i<n;i++) if(!vis[i]) pq.push(min_len(i)) ;
    while(pq.size()>1)
    {
        int x=pq.top() ; pq.pop() ;
        int y=pq.top() ; pq.pop() ;
        ans=max(ans,x+y+L) ;
        int newx=min(max(x,y+L),max(y,x+L)) ;
        pq.push(newx) ;
    }
    printf("%d\n",ans) ;
}
