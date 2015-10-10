#include<bits/stdc++.h>
using namespace std;
const int maxn=600000+10 ;

int fa[maxn],fcnt ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

int val[maxn] ;
void join(int x,int y)
{
    x=getfa(x) ; y=getfa(y) ;
    if(x==y) return ;
    val[++fcnt]=max(max(val[x],val[y]),1+(val[x]+1)/2+(val[y]+1)/2) ;
    fa[fcnt]=fcnt ;
    fa[x]=fa[y]=fcnt ;
}

vector<int> v[maxn] ;
int d[maxn] ;
void dfs(int x,int f,int dep,int &id,int &M)
{
    d[x]=dep ;
    if(dep>M) M=dep , id=x ;
    for(auto i : v[x]) if(i!=f)
        dfs(i,x,dep+1,id,M) ;
}

int getlen(int x)
{
    int id,M=-1 ;
    dfs(x,-1,0,id,M) ;
    M=-1 ;
    dfs(id,-1,0,id,M) ;
    return M ;
}

main()
{
    int n,m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
    for(int i=1;i<=n;i++) fa[i]=i , fcnt++ ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ; v[y].push_back(x) ;
        fa[getfa(x)]=getfa(y) ;
    }
    for(int i=1;i<=n;i++) if(fa[i]==i)
        val[i]=getlen(i) ;
    while(Q--)
    {
        int t,x,y ; scanf("%d",&t) ;
        if(t==1) scanf("%d",&x) , printf("%d\n",val[getfa(x)]) ;
        else scanf("%d%d",&x,&y) , join(x,y) ;
    }
}
