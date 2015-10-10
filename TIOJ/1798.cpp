#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10,maxd=18 ;
vector<int> v[maxn] ;
int dep[maxn],fa[maxn] ;

void dfs(int x)
{
    for(auto i : v[x]) if(i!=fa[x])
        fa[i]=x , dep[i]=dep[x]+1 , dfs(i) ;
}

int n,anc[maxd][maxn] ;
void build_LCA()
{
    for(int i=0;(1<<i)<=n && i<maxd;i++) for(int j=1;j<=n;j++)
        anc[i][j]= i==0 ? fa[j] : anc[i-1][anc[i-1][j]] ;
}

int query_fa(int x,int dis)
{
    if(!dis) return x ;
    for(int i=maxd-1;dis;i--) while(dis>=(1<<i))
    {
        x=anc[i][x] ;
        dis-=(1<<i) ;
    }
    return x ;
}

int LCA(int x,int y)
{
    if(x==y) return x ;

    if(dep[x]<dep[y])
        return LCA(x,query_fa(y,dep[y]-dep[x])) ;

    if(dep[y]<dep[x])
        return LCA(query_fa(x,dep[x]-dep[y]),y) ;

    for(int i=maxd-1;i>=0;i--) while(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ;
    return fa[x] ;
}

int fa2[maxn] ;
int getfa(int x)
{
    return fa2[x]==x ? x : fa2[x]=getfa(fa2[x]) ;
}

main()
{
    int m,k,Q ; scanf("%d%d%d%d",&n,&m,&k,&Q) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ; v[y].push_back(x) ;
    }

    fa[1]=1 ; dep[1]=1 ;
    dfs(1) ;
    build_LCA() ;

    for(int i=1;i<=n;i++) fa2[i]=i ;
    while(k--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        int lca=LCA(x,y) ;
        lca=getfa(lca) ;
        while(1)
        {
            int x2=getfa(x) ;
            if(dep[x2]<=dep[lca]) break ;
            fa2[x2]=lca ;
            x=fa[x2] ;
        }
        while(1)
        {
            int y2=getfa(y) ;
            if(dep[y2]<=dep[lca]) break ;
            fa2[y2]=lca ;
            y=fa[y2] ;
        }
    }
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        printf("%d\n",getfa(x)==getfa(y)) ;
    }
}
