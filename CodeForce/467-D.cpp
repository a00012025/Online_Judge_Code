#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=300000+10 ;

inline int getr(const string &s)
{
    int ret=0 ;
    for(auto i : s) if(i=='r') ret++ ;
    return ret ;
}

vector<int> v1[maxn],v2[maxn],v[maxn] ;
pii val[maxn],val2[maxn] ;
bool vis[maxn] ;
int topo[maxn],tcnt ;
int scc[maxn],scnt ;
map<string,int> mp ;
int icnt=0 ;
string str[maxn] ;
int ID(const string &s)
{
    auto it=mp.find(s) ;
    if(it==mp.end())
    {
        str[icnt]=s ;
        val[icnt]=(pii){getr(s),s.size()} ;
        return mp[s]=icnt++ ;
    }
    else return it->S ;
}

void dfs1(int x)
{
    vis[x]=1 ;
    for(auto i : v1[x]) if(!vis[i])
        dfs1(i) ;
    topo[--tcnt]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ;
    val2[scnt]=min(val2[scnt],val[x]) ;
    for(auto i : v2[x]) if(!vis[i])
        dfs2(i) ;
}

pii d[maxn] ;
pii DP(int x)
{
    if(d[x].F!=-1) return d[x] ;
    d[x]=val2[x] ;
    for(auto i : v[x]) d[x]=min(d[x],DP(i)) ;
    return d[x] ;
}

int a[maxn] ;
main()
{
    int n,m ; string s,t ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        cin >> s ;
        for(auto &j : s) if(j<='Z') j+='a'-'A' ;
        a[i]=ID(s) ;
    }
    scanf("%d",&m) ;
    while(m--)
    {
        cin >> s >> t ;
        for(auto &j : s) if(j<='Z') j+='a'-'A' ;
        for(auto &j : t) if(j<='Z') j+='a'-'A' ;
        int x,y ;
        v1[x=ID(s)].push_back(y=ID(t)) ;
        v2[y].push_back(x) ;
    }

    tcnt=icnt ;
    for(int i=0;i<icnt;i++) if(!vis[i])
        dfs1(i) ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=0;i<icnt;i++) if(!vis[topo[i]])
    {
        scnt++ ; val2[scnt]=(pii){maxn,maxn} ;
        dfs2(topo[i]) ;
    }

    for(int i=0;i<icnt;i++) for(auto j : v1[i])
        if(scc[i]!=scc[j])
        v[scc[i]].push_back(scc[j]) ;

    memset(d,-1,sizeof(d)) ;
    long long ans1=0,ans2=0 ;
    for(int i=1;i<=n;i++)
    {
        pii p=DP(scc[a[i]]) ;
        ans1+=p.F ; ans2+=p.S ;
    }
    printf("%I64d %I64d\n",ans1,ans2) ;
}
