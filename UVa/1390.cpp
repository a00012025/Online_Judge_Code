#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define DB double
using namespace std;
vector<int> v[40] ;
bool vis[40] ;
int cnt ;

void dfs(int x)
{
    vis[x]=1 ; cnt++ ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs(v[x][i]) ;
}

map<vector<int>,DB> mp ;
int n ;

DB dp(const vector<int> &v)
{
        debugf("dp : ") ;
        for(int i=0;i<v.size();i++) debugf("%d%c",v[i],i==v.size()-1?'\n':',') ;
    if(v.size()==1) return 0.0 ;
    if(mp.count(v)) return mp[v] ;
    int sumsq=0 ;
    for(int i=0;i<v.size();i++) sumsq+=v[i]*(v[i]-1)/2 ;
    DB ret=0.0 , all=(DB)n*(n-1)/2 ;
    vector<int> tmp ;
    for(int i=0;i<v.size();i++) for(int j=i+1;j<v.size();j++)
    {
        tmp.clear() ;
        for(int k=0;k<v.size();k++) if(k!=i && k!=j) tmp.push_back(v[k]) ;
        tmp.push_back(v[i]+v[j]) ;
        sort(tmp.begin(),tmp.end()) ;
        ret+=(1+dp(tmp))*( v[i]*v[j]/all ) ;
    }
    ret += sumsq/all ; ret /= (all-sumsq)/all ;
    return mp[v]=ret ;
}

main()
{
    int m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        memset(vis,0,sizeof(vis)) ;
        vector<int> st ;
        for(int i=1;i<=n;i++) if(!vis[i])
        {
            cnt=0 ; dfs(i) ; st.push_back(cnt) ;
        }
        sort(st.begin(),st.end()) ; mp.clear() ;
        printf("%.6lf\n",dp(st)) ;
    }
}
