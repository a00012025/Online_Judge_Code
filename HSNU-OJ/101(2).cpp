#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
struct P
{
    int val,pthid ;
    bool operator < (const P &rhs) const
    {
        if(val!=rhs.val) return val<rhs.val ;
        else return pthid<rhs.pthid ;
    }
};
vector<int> v[maxn] ;
bool used[maxn] ;
int d[maxn],n ;

void dfs(int x,int k)
{
    d[x]=k ;
    for(int i=0;i<v[x].size();i++) if(d[v[x][i]]==-1 && !used[v[x][i]])
        dfs(v[x][i],k+1) ;
}

vector<int> path[maxn] ;
int pth_cnt=0 ;
P get_longest1(int x)
{
    memset(d,-1,sizeof(d)) ;
    dfs(x,0) ;
    int ret=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>ret) ret=d[id=i] ;
    path[pth_cnt].push_back(id) ;
    for(int i=id;i!=x;)
    {
        int j ;
        for(j=0;j<v[i].size();j++) if(d[v[i][j]]==d[i]-1) break ;
        i=v[i][j] ;
        path[pth_cnt].push_back(i) ;
    }
    pth_cnt++ ;
    return (P){ret,pth_cnt-1} ;
}

P get_longest2(int x)
{
    memset(d,-1,sizeof(d)) ;
    dfs(x,0) ;
    int md=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>md) md=d[id=i] ;
    P ret=get_longest1(id) ;
    return (P){ret.val,ret.pthid} ;
}

bool check(const vector<int> &v0)
{
    for(int i=0;i<v0.size();i++) if(used[v0[i]]) return 0 ;
    return 1 ;
}

priority_queue<P> pq1,pq2 ;
void delete_path(int pthid)
{
    for(int i=0;i<path[pthid].size();i++) used[path[pthid][i]]=1 ;
    for(int i=0;i<path[pthid].size();i++)
    {
        int u=path[pthid][i] ;
        for(int j=0;j<v[u].size();j++) if(!used[v[u][j]])
        {
            pq1.push(get_longest2(v[u][j])) ;
            pq2.push(get_longest1(v[u][j])) ;
        }
    }
}

main()
{
    int k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    int num=0 ;
    for(int i=1;i<=n;i++) if(v[i].size()==1) num++ ;
    if(2*k>=num) { printf("%d\n",n) ; return 0 ; }

    int ans=0 ;
    pq1.push(get_longest2(1)) ;
    for(int z=1;z<=k;z++)
    {
        debugf("XD\n") ;
        if(pq1.top().val==0){ printf("%d\n",ans+2*(k-z+1)) ; return 0 ; }

        int M=0 ; P u1,u2 ;
        while(!pq2.empty() && !check(path[pq2.top().pthid])) pq2.pop() ;
        if(!pq2.empty())
        {
            M+=pq2.top().val+1 ;
            u1=pq2.top() ; pq2.pop() ;
            while(!pq2.empty() && !check(path[pq2.top().pthid])) pq2.pop() ;
            if(pq2.empty()) M=0 , pq2.push(u1) ;
            else M+=pq2.top().val+1 ;
        }

        while(!pq1.empty() && !check(path[pq1.top().pthid])) pq1.pop() ;
        if(!pq1.empty() && pq1.top().val+1>=M)
        {
            if(M) pq2.push(u1) ;
            ans+=pq1.top().val+1 ;
            u1=pq1.top() ; pq1.pop() ;
            delete_path(u1.pthid) ;
        }
        else
        {
            u2=pq2.top() ; pq2.pop() ;
            delete_path(u1.pthid) ;
            delete_path(u2.pthid) ;
            ans+=M ;
        }
    }
    printf("%d\n",ans) ;
}
