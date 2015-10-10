#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 1000000000
#define F first
#define S second
using namespace std;
struct P{int from,to,dis;};
const int maxn=200000+10 ;
vector<P> edge ;
vector<int> v[maxn];
int n,m,fa[maxn],size ;
bool used[maxn] ;

int get_sz(int x)
{
    int ret=1 ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        int to= edge[v[x][i]].to==x ? edge[v[x][i]].from : edge[v[x][i]].to ;
        if(fa[x]!=to) fa[to]=x , ret+=get_sz(to) ;
    }
    return ret ;
}

int dp(int x,int &num,int &id)
{
    int ret=1,M=0 ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        int to= edge[v[x][i]].to==x ? edge[v[x][i]].from : edge[v[x][i]].to ;
        if(fa[x]==to) continue ;
        fa[to]=x ;
        int tmp=dp(to,num,id) ;
        M=max(M,tmp) ;
        ret+=tmp ;
    }
    M=max(M,size-ret) ;
    if(M<=num) { num=M ; id=x ;  }
    return ret ;
}

int centroid(int x)
{
    fa[x]=x ;
    int num=INF , ret ;
    size=get_sz(x) ;
    dp(x,num,ret) ;
    return ret ;
}

map<int,int> mp,tmp ;

void dfs(int x,int d,int len)
{
    if(d>m) return ;
    if(!tmp.count(d)) tmp[d]=len ;
    else tmp[d]=min(tmp[d],len) ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        int to= edge[v[x][i]].to==x ? edge[v[x][i]].from : edge[v[x][i]].to ;
        if(to!=fa[x]) fa[to]=x , dfs(to,d+edge[v[x][i]].dis,len+1) ;
    }
}

vector<int> son[maxn] ;
int solve(int y)
{
    int x=centroid(y) , ret=INF ;
    debugf("solve %d : centroid = %d\n",y,x) ;
    mp.clear() ; mp[0]=0 ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        used[v[x][i]]=1 ;
        tmp.clear() ;
        int to= edge[v[x][i]].to==x ? edge[v[x][i]].from : edge[v[x][i]].to ;
        son[x].push_back(to) ;
        fa[to]=x ;
        dfs(to,edge[v[x][i]].dis,1) ;
        for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++)
            if(mp.count(m-it->F)) ret=min(ret,it->S+mp[m-it->F]) ;
        for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++)
        {
            if(mp.count(it->F)) mp[it->F]=min(mp[it->F],it->S) ;
            else mp[it->F]=it->S ;
        }
    }

    for(int i=0;i<son[x].size();i++)
        ret=min(ret,solve(son[x][i])) ;

    return ret ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<n;i++)
    {
        int x,y,l ; scanf("%d%d%d",&x,&y,&l) ;
        edge.push_back((P){x,y,l}) ;
        v[x].push_back(i-1) ;
        v[y].push_back(i-1) ;
    }
    int ans=solve(0) ;
    if(ans==INF) printf("-1\n") ;
    else printf("%d\n",ans) ;
}
