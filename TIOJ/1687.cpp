#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn] ;
bool vis[maxn] ;
int dep[maxn],fa[maxn] ;

void dfs(int x)
{
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
        fa[i]=x , dep[i]=dep[x]+1 , dfs(i) ;
}

int n,anc[20][maxn] ;
void build_LCA()
{
    for(int i=0;(1<<i)<=n;i++) for(int j=1;j<=n;j++)
        anc[i][j]= i==0 ? fa[j] : anc[i-1][anc[i-1][j]] ;
}

int query_fa(int x,int dis)
{
    if(!dis) return x ;
    for(int i=19;dis;i--) if(dis>=(1<<i))
    {
        x=anc[i][x] ;
        dis^=(1<<i) ;
    }
    return x ;
}

int LCA(int x,int y,int &a,int &b)
{
    if(x==y) return x ;
    if(dep[x]<dep[y])
    {
        b+=dep[y]-dep[x] ;
        return LCA(x,query_fa(y,dep[y]-dep[x]),a,b) ;
    }
    if(dep[y]<dep[x])
    {
        a+=dep[x]-dep[y] ;
        return LCA(query_fa(x,dep[x]-dep[y]),y,a,b) ;
    }
    for(int i=19;i>=0;i--) if(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ,
        a+=(1<<i) , b+=(1<<i) ;
    a++ ; b++ ;
}

main()
{
    int Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    fa[1]=1 ; dep[1]=0 ;
    dfs(1) ;
    build_LCA() ;
    while(Q--)
    {
        int st,ed,k ; scanf("%d%d%d",&st,&ed,&k) ;
        int a=0 , b=0 ;
        int lca=LCA(st,ed,a,b) ;

        if(lca==st)
        {
            if(k>b) printf("-1\n") ;
            else printf("%d\n",query_fa(ed,b-k)) ;
        }
        else if(lca==ed)
        {
            if(k>a) printf("-1\n") ;
            else printf("%d\n",query_fa(st,k)) ;
        }
        else
        {
            if(k>a+b) printf("-1\n") ;
            else if(k>=a) printf("%d\n",query_fa(ed,a+b-k)) ;
            else printf("%d\n",query_fa(st,k)) ;
        }
    }
}
