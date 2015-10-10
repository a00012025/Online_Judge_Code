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
    int id,val ;
    bool operator < (const P &rhs) const
    {
        if(val!=rhs.val) return val<rhs.val ;
        else return id<rhs.id ;
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

P get_longest1(int x)
{
    memset(d,-1,sizeof(d)) ;
    dfs(x,0) ;
    int ret=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>ret) ret=d[id=i] ;
    return (P){id,ret} ;
}

P get_longest2(int x)
{
    memset(d,-1,sizeof(d)) ;
    dfs(x,0) ;
    int md=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>md) md=d[id=i] ;
    P ret=get_longest1(id) ;
    return (P){id,ret.val} ;
}

int ans ;
priority_queue<P> pq1,pq2 ;
vector<int> path ;
void delete_path(int x)
{
    P u=get_longest1(x) ; debugf("u=(%d,%d)\nuse %d\n",u.id,u.val,x) ;
    ans+=u.val+1 ;
    get_longest1(u.id) ;

    used[x]=1 ;
    path.clear() ; path.push_back(x) ;
    for(int i=x;i!=u.id;)
    {
        int j ;
        for(j=0;j<v[i].size();j++)
            if(d[v[i][j]]==d[i]-1) break ;
        used[v[i][j]]=1 ; debugf("use %d\n",v[i][j]) ;
        i=v[i][j] ; path.push_back(i) ;
    }
    for(int i=0;i<path.size();i++)
    {
        int x=path[i] ;
        for(int j=0;j<v[x].size();j++) if(!used[v[x][j]])
        {
            debugf("x=%d , add %d\n",x,v[x][j]) ;
            P tmp1=get_longest2(v[x][j]) ; debugf("pq1 push (%d,%d)\n",tmp1.id,tmp1.val);
            pq1.push(tmp1) ;
            P tmp2=get_longest1(v[x][j]) ;
            pq2.push((P){v[x][j],tmp2.val}) ; debugf("pq2 push (%d,%d)\n",v[x][j],tmp2.val);
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

    ans=0 ;
    pq1.push(get_longest2(1)) ;
    for(int z=1;z<=k;z++)
    {
        debugf("XD\n") ;
        if(pq1.top().val==0){ printf("%d\n",ans+2*(k-z+1)) ; return 0 ; }
        int M=0 ;
        P tmp ;
        if(pq2.size()>=2)
        {
            tmp=pq2.top() ; pq2.pop() ;
            M=tmp.val+pq2.top().val+2 ;
        }
        while(used[pq1.top().id]) pq1.pop() ;
        if(pq1.top().val+1>=M)
        {
            if(M) pq2.push(tmp) ;
            P u=pq1.top() ; pq1.pop() ;
            debugf("pq1 : (%d,%d)\n",u.id,u.val) ;
            delete_path(u.id) ;
        }
        else
        {
            P u1=tmp , u2=pq2.top() ; pq2.pop() ;
            debugf("pq2 : (%d,%d) , (%d,%d)\n",u1.id,u1.val,u2.id,u2.val) ;
            delete_path(u1.id) ;
            delete_path(u2.id) ;
        }
    }
    printf("%d\n",ans) ;
}
