#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn] ;
int fa[maxn] ;

struct P{int id,val;}a[maxn];
bool cmp(const P &a,const P &b)
{ return a.val==b.val ? a.id>b.id : a.val>b.val ; }

int d[maxn] ;
void dfs(int x,int dep)
{
    d[x]=dep ; a[x]=(P){x,dep} ;

    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        fa[v[x][i]]=x , dfs(v[x][i],dep+1) ;
}

int cnt[maxn],vis[maxn],vcnt=0 ;
int dfs2(int x,int dep)
{
    vis[x]=vcnt ;
    int ret=-1 ;
    if(cnt[x]) ret=x ;
    if(!dep) return ret ;
    for(int i=0;i<v[x].size();i++) if(vis[v[x][i]]!=vcnt)
    {
        int ret2=dfs2(v[x][i],dep-1) ;
        if(ret==-1 || d[ret2]>d[ret]) ret=ret2 ;
    }
    return ret ;
}

main()
{
    int n,s,k ; scanf("%d%d%d",&n,&s,&k) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    fa[1]=1 ;
    dfs(1,0) ;

    sort(a+1,a+n+1,cmp) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        int x=a[i].id ;
        vcnt++ ;
        int ret=dfs2(x,k) ;
        if(ret==-1)
        {
            int j=x ;
            for(int z=1;z<=k;z++) j=fa[j] ;
            ans++ ; cnt[j]=s-1 ;
        }
        else cnt[ret]-- ;
    }
    printf("%d\n",ans) ;
}
