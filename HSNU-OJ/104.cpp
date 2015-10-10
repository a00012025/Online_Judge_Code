#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
struct P{int ed,dis;};

vector<P> v[200] ;

int n,cnt[200],d[200] ;
bool inq[200] ;
bool bellmanford(int st)
{
    memset(cnt,0,sizeof(cnt)) ;
    memset(inq,0,sizeof(inq)) ;
    for(int i=1;i<=n+1;i++) d[i]=INF ; d[st]=0 ;
    queue<int> q ;
    q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++)
        {
            if(d[v[u][i].ed] > d[u]+v[u][i].dis)
            {
                d[v[u][i].ed] = d[u]+v[u][i].dis ;
                if(++cnt[v[u][i].ed]>n) return 1 ;
                if(!inq[v[u][i].ed]) q.push(v[u][i].ed) ;
                inq[v[u][i].ed]=1 ;
            }
        }
    }
    return 0 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int m,p ; scanf("%d%d%d",&n,&m,&p) ;
        for(int i=1;i<=n+1;i++) v[i].clear() ;
        while(m--)
        {
            int x,y,a,b ; scanf("%d%d%d%d",&x,&y,&a,&b) ;
            v[x].push_back((P){y,p*b-a}) ;
        }
        for(int i=1;i<=n;i++) v[n+1].push_back((P){i,0}) ;
        if(bellmanford(n+1)) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
