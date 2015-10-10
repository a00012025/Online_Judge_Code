#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10,maxm=500000+10 ;

struct P{int x,y;};
vector<P> edge ;
vector<int> v[maxn] ;
int E[maxn],ans[maxm],cnt=0 ;
bool vis[maxm] ;

void dfs(int x)
{
    for(int &i=E[x];i<v[x].size();i++) if(!vis[v[x][i]])
    {
        int to=edge[v[x][i]].x==x ?
            edge[v[x][i]].y : edge[v[x][i]].x ;
        int tmp=v[x][i] ;
        vis[v[x][i]]=1 ; i++ ;
        dfs(to) ;
    }
    ans[cnt++]=x ;
}

int in[maxn],out[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        edge.push_back((P){x,y}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    for(int i=1,last=-1;i<=n;i++) if(v[i].size()%2)
    {
        if(last==-1) last=i ;
        else
        {
            edge.push_back((P){i,last}) ;
            int s=edge.size() ;
            v[i].push_back(s-1) ;
            v[last].push_back(s-1) ;
            last=-1 ;
        }
    }
    if(edge.size()%2)
    {
        edge.push_back((P){1,1}) ;
        int s=edge.size() ;
        v[1].push_back(s-1) ;
        v[1].push_back(s-1) ;
    }

    dfs(1) ;
    printf("%d\n",edge.size()) ;
    for(int i=0;i<cnt-1;i++)
    {
        if(i%2==0) printf("%d %d\n",ans[i],ans[i+1]) ;
        else printf("%d %d\n",ans[i+1],ans[i]) ;
    }
}
