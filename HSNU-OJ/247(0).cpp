#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=1000000+100 ;
struct P{int from,to,dis;};
vector<int> v[maxn] ;
vector<P> edge ;
int n ;
int vis[maxn] ;
bool used[maxn],incyc[maxn],evis[maxn] ;

vector<int> cyc_p,cyc_e ;
bool dfs0(int x)
{
    vis[x]=-1 ;
    for(int i=0;i<v[x].size();i++) if(!evis[v[x][i]])
    {
        evis[v[x][i]]=1 ;
        int to= edge[v[x][i]].from==x ? edge[v[x][i]].to : edge[v[x][i]].from ;

        if(vis[to] == -1)
        {
            cyc_p.push_back(to) ;
            incyc[to]=1 ;
            cyc_e.push_back(v[x][i]) ;
            return 1 ;
        }
        if(dfs0(to) && !incyc[to])
        {
            cyc_p.push_back(to) ;
            incyc[to]=1 ;
            cyc_e.push_back(v[x][i]) ;
            return 1 ;
        }
    }

    return 0 ;
}

vector<int> tree[maxn] ;
void dfs1(int x,int tid)
{
    vis[x]=1 ; tree[tid].push_back(x) ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        int to= edge[v[x][i]].from==x ? edge[v[x][i]].to : edge[v[x][i]].from ;
        if(vis[to]!=1) dfs1(to,tid) ;
    }
}

LL d[maxn] ;
void dfs2(int x)
{
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        int to= edge[v[x][i]].from==x ? edge[v[x][i]].to : edge[v[x][i]].from ;
        if(d[to]==INF) { d[to]=d[x]+edge[v[x][i]].dis ; dfs2(to) ; }
    }
}

LL max_length1(int x,int tid)
{
    for(int i=0;i<tree[tid].size();i++) d[tree[tid][i]]=INF  ;
    d[x]=0 ;
    dfs2(x) ;
    LL ret=0LL ;
    for(int i=0;i<tree[tid].size();i++) ret=max(ret,d[tree[tid][i]]) ;
    return ret ;
}

LL max_length2(int tid)
{
    LL M=-1 ; int id ;
    for(int i=0;i<tree[tid].size();i++) if(d[tree[tid][i]] > M)
        M = d[id=tree[tid][i]] ;
    return max_length1(id,tid) ;
}

LL len[maxn] ;
multiset<LL,greater<LL> > mst ;
LL cal(int x)
{
    cyc_p.clear() ;
    cyc_e.clear() ;
    dfs0(x) ;

    int num=cyc_p.size() ;
    for(int i=0;i<num;i++) used[cyc_e[i]]=1 , tree[i].clear() ;
    for(int i=0;i<num;i++) dfs1(cyc_p[i],i) ;
/*
    for(int i=0;i<num;i++) {for(int j=0;j<tree[i].size();j++)
        printf("%d,",tree[i][j]) ; printf("\n") ; }
*/
    LL ret=0LL ;
    for(int i=0;i<num;i++) len[i]=max_length1(cyc_p[i],i) ;
    for(int i=0;i<num;i++) ret=max(ret,max_length2(i)) ;
/*
    for(int i=0;i<num;i++) printf("%d , %d , %I64d\n",cyc_p[i],edge[cyc_e[i]].dis,len[i]);
*/
    mst.clear() ; LL tot=0LL ;
    for(int i=0;i<num;i++) mst.insert(tot+len[i]) , tot+=edge[cyc_e[i]].dis ;
    LL sum=0LL ;
    for(int i=0;i<num;i++)
    {
        mst.erase(mst.find(sum+len[i])) ;
        ret=max(ret,len[i]+(*(mst.begin()))-sum) ;
        mst.insert(tot+sum+len[i]) ;
        sum+=edge[cyc_e[i]].dis ;
    }
    //printf("ret=%I64d\n",ret) ;
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,d ; scanf("%d%d",&x,&d);
        edge.push_back((P){i,x,d}) ;
        v[i].push_back(i-1) ;
        v[x].push_back(i-1) ;
    }
    LL ans=0LL ;
    for(int i=1;i<=n;i++) if(!vis[i]) ans+=cal(i) ;
    printf("%I64d\n",ans) ;
}
