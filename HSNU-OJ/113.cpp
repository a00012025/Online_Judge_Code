#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct P{int from,to ; LL dis;};
vector<P> edge ;
vector<int> v[100001] ;
bool used[100001] ;
int n,vis_cnt ;
int vis[100001] ;
LL MOD,ans ;

int dfs_cnt(int x)
{
    vis[x]=vis_cnt ;
    int ret=1 ;
    for(int i=0;i<v[x].size();i++)
    {
        if(!used[v[x][i]] && vis[ edge[v[x][i]].from ]!=vis_cnt)
            ret += dfs_cnt( edge[v[x][i]].from ) ;
        else if(!used[v[x][i]] && vis[ edge[v[x][i]].to ]!=vis_cnt)
            ret += dfs_cnt( edge[v[x][i]].to ) ;
    }
    return ret ;
}

int dfs_get_edge(int x,int sz,int &newsz,int &eid)
{
    vis[x]=vis_cnt ;
    int ret=1 ;
    for(int i=0;i<v[x].size();i++)
    {
        if(!used[v[x][i]] && vis[ edge[v[x][i]].from ]!=vis_cnt)
        {
            int add=dfs_get_edge( edge[v[x][i]].from,sz,newsz,eid ) ; ret+=add ;
            if(abs(2*newsz-sz) >= abs(2*add-sz)) newsz=add , eid=v[x][i] ;
        }
        else if(!used[v[x][i]] && vis[ edge[v[x][i]].to ]!=vis_cnt)
        {
            int add=dfs_get_edge( edge[v[x][i]].to,sz,newsz,eid ) ; ret+=add ;
            if(abs(2*newsz-sz) >= abs(2*add-sz)) newsz=add , eid=v[x][i] ;
        }
    }
    return ret ;
}

set<LL> st ;
vector<LL> tmp ;

void dfs_get_dis(int x,LL dis,int type)
{
    vis[x]=vis_cnt ;
    if(type==0) st.insert(dis) ;
    else tmp.push_back(dis) ;
    for(int i=0;i<v[x].size();i++)
    {
        if(!used[v[x][i]] && vis[ edge[v[x][i]].from ]!=vis_cnt)
            dfs_get_dis( edge[v[x][i]].from,(dis+edge[v[x][i]].dis) % MOD , type ) ;
        else if(!used[v[x][i]] && vis[ edge[v[x][i]].to ]!=vis_cnt)
            dfs_get_dis( edge[v[x][i]].to,(dis+edge[v[x][i]].dis) % MOD , type ) ;
    }
}

void solve(int x)
{
    bool no=1 ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]]) {no=0 ; break ; }
    if(no) return ;

    vis_cnt++ ;
    int sz=dfs_cnt(x) , newsz=0 , eid ;

    vis_cnt++ ;
    dfs_get_edge(x,sz,newsz,eid) ;

    used[eid]=1 ;
    int p=edge[eid].from , q=edge[eid].to ; debugf("solve %d : p=%d,q=%d\n",x,p,q);
    st.clear() ; tmp.clear() ;
    vis_cnt++ ;
    dfs_get_dis(p,0,0) ; //for(set<LL>::iterator it=st.begin();it!=st.end();it++) debugf("%d,",*it) ; debugf("\n") ;
    dfs_get_dis(q,0,1) ; //for(int i=0;i<tmp.size();i++) debugf("%d,",tmp[i]) ; debugf("\n") ;
    for(int i=0;i<tmp.size();i++)
    {
        LL goal=((-1-edge[eid].dis-tmp[i])%MOD + MOD) % MOD ;
        set<LL>::iterator it=st.upper_bound(goal) ;
        if(it==st.begin()) it=st.end() ;
        it-- ;
        ans=max(ans,((*it)+tmp[i]+edge[eid].dis)%MOD) ;
    }
    solve(p) ; solve(q) ;
}

main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%lld",&n,&MOD) ;
        for(int i=0;i<=n;i++) v[i].clear() ; edge.clear() ;
        for(int i=0;i<n-1;i++)
        {
            int x,y ; LL z ; scanf("%d%d%lld",&x,&y,&z) ;
            edge.push_back((P){x,y,z}) ;
            v[x].push_back(i) ;
            v[y].push_back(i) ;
        }
        memset(used,0,sizeof(used)) ;
        ans=0LL ;
        memset(vis,0,sizeof(vis)) ; vis_cnt=0 ;
        solve(1) ;
        printf("%lld\n",ans) ;
    }
}
