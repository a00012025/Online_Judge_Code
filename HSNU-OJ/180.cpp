#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+100 ;

vector<int> v[maxn] ;
bool G[maxn] ;
int col[maxn],d[maxn] ;
int n ;

void dfs(int x,int c)
{
    col[x]=c ;
    for(int i=0;i<v[x].size();i++) if(col[v[x][i]]==-1)
        dfs(v[x][i],1-c) ;
}

bool check()
{
    memset(col,-1,sizeof(col)) ;
    dfs(1,0) ;
    int c=-1 ;
    for(int i=1;i<=n;i++) if(G[i])
    {
        if(c==-1) c=col[i] ;
        else if(c!=col[i]) return 0 ;
    }
    return 1 ;
}

void dfs2(int x,int lev)
{
    d[x]=lev ;
    for(int i=0;i<v[x].size();i++) if(d[v[x][i]]==-1)
        dfs2(v[x][i],lev+1) ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    assert(m==n-1) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    int k ; scanf("%d",&k) ;
    while(k--)
    {
        int x ; scanf("%d",&x) ;
        G[x]=1 ;
    }
    if(!check()) { printf("NIE\n") ; return 0 ; }

    memset(d,-1,sizeof(d)) ;
    int id1 ; for(id1=1;!G[id1];id1++) ;
    dfs2(id1,0) ;
    int M=-1 , id2 ;
    for(int i=1;i<=n;i++) if(G[i] && d[i]>M) M=d[id2=i] ;

    memset(d,-1,sizeof(d)) ;
    dfs2(id2,0) ;
    M=-1 ; for(int i=1;i<=n;i++) if(G[i]) M=max(M,d[i]) ;
    printf("%d\n",M/2) ;
}
