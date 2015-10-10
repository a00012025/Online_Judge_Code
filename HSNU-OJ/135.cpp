#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;
struct P{int from,to;};
struct Q{int id,d;};
vector<int> v[maxn] ;
vector<P> edge ;
int d[maxn] ;
bool vis[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        edge.push_back((P){x,y}) ;
        int m=edge.size() ;
        v[x].push_back(m-1) ;
        v[y].push_back(m-1) ;
    }
    int num=0 ;
    for(int i=1;i<=n;i++) if(v[i].size()%2) num++ ;
    printf("%d ",num/2) ;
    if(num==n) { printf("%d\n",n==2?1:2) ; return 0 ; }

    queue<Q> q ;
    for(int i=1;i<=n;i++) if(v[i].size()%2) q.push((Q){i,0}) ;
    while(!q.empty())
    {
        Q u=q.front() ; q.pop() ;
        for(int i=0;i<v[u.id].size();i++) if(!vis[v[u.id][i]])
        {
            vis[v[u.id][i]]=1 ; d[v[u.id][i]]=u.d+1 ;
            if(u.id==edge[v[u.id][i]].from)
                q.push((Q){edge[v[u.id][i]].to,u.d+1}) ;
            else q.push((Q){edge[v[u.id][i]].from,u.d+1}) ;
        }
    }

    int maxd=-1 ;
    for(int i=0;i<edge.size();i++) maxd=max(maxd,d[i]) ;
    int ans=2 ;
    for(int i=1;i<=n;i++)
    {
        bool ok=1 ;
        for(int j=0;j<v[i].size();j++) if(d[v[i][j]]<maxd-1) { ok=0 ; break ; }
        if(!ok) continue ;

        int x=0 , y=0 ;
        for(int j=0;j<v[i].size();j++)
        {
            if(d[v[i][j]]==maxd) x++ ;
            else y++ ;
        }
        if(x<=y) ans=max(ans,2*maxd-1) ;
        else ans=max(ans,2*maxd) ;
    }
    printf("%d\n",ans) ;
}
