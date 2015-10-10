#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

vector<int> v[maxn] ;
int col[maxn] ;
bool dfs(int x,int c)
{
    col[x]=c ;
    for(auto i : v[x])
    {
        if(col[i]==-1 && !dfs(i,c^1)) return 0 ;
        else if(col[i]!=-1 && col[i]==c) return 0 ;
    }
    return 1 ;
}

bool vis[maxn] ;
int tmp[maxn],d[maxn],cnt ;

queue<int> q ;
int BFS(int x,int type)
{
    int ret=0 ;
    memset(d,-1,sizeof(d)) ;
    q.push(x) ; d[x]=0 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        ret=max(ret,d[u]) ;
        if(type==1) tmp[cnt++]=u ;
        for(auto i : v[u]) if(d[i]==-1)
            d[i]=d[u]+1 , q.push(i) ;
    }
    return ret ;
}

int solve(int x)
{
    int ret=0 ;
    cnt=0 ;
    for(int st=x,i=1;;i++)
    {
        ret=max(ret,BFS(st,st==x)) ;
        if(i==cnt) break ;
        st=tmp[i] ;
    }
    for(int i=0;i<cnt;i++) vis[tmp[i]]=1 ;
    return ret ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    memset(col,-1,sizeof(col)) ;
    for(int i=1;i<=n;i++) if(col[i]==-1 && !dfs(i,0))
        {printf("-1\n") ; return 0 ;}

    int ans=0 ;
    for(int i=1;i<=n;i++) if(!vis[i]) ans+=solve(i) ;
    printf("%d\n",ans) ;
}
