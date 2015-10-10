#include<bits/stdc++.h>
#define LL long long
#define SQR(x) (((LL)x)*((LL)x))
using namespace std;
const int maxn=200000+10 ;

int anc[18][maxn] ;
vector<int> v[maxn],gp[maxn] ;
int n,dep[maxn],in[maxn],tim ;
int val[maxn] ;

void dfs(int x,int f,int d)
{
    anc[0][x]=f ; dep[x]=d ;
    in[x]=++tim ;
    for(auto i : v[x]) if(i!=f)
        dfs(i,x,d+1) ;
}

void build()
{
    for(int i=1;(1<<i)<=n;i++) for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]] ;
}

int query_fa(int x,int d)
{
    if(d==0) return x ;
    for(int i=17;i>=0 && d;i--) if(d&(1<<i))
        x=anc[i][x] , d^=(1<<i) ;
    return x ;
}

int LCA(int x,int y)
{
    if(x==y) return x ;
    if(dep[x]!=dep[y])
    {
        int dif=dep[x]-dep[y] ;
        if(dif>0) return LCA(query_fa(x,dif),y) ;
        else return LCA(x,query_fa(y,-dif)) ;
    }
    for(int i=17;i>=0;i--) if(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ;
    return x==y ? x : anc[0][x] ;
}

struct event
{
    int x,y,lca,dep ;
    bool operator < (const event &rhs) const
    {
        return dep==rhs.dep ? lca<rhs.lca : dep>rhs.dep ;
    }
};

event get_event(int x,int y)
{
    int lca=LCA(x,y) ;
    return (event){x,y,lca,dep[lca]} ;
}

bool cmp(int x,int y)
{
    return in[x]<in[y] ;
}

set<event> st ;
int nex[maxn],las[maxn] ;

LL solve(vector<int> &vec)
{
    int sz=vec.size() ;
    if(sz<=1) return 0LL ;
    st.clear() ;
    sort(vec.begin(),vec.end(),cmp) ;
    for(int i=0;i<sz;i++)
    {
        val[vec[i]]=1 ;
        nex[vec[i]]= ( i==sz-1 ? 0 : vec[i+1] ) ;
        las[vec[i]]= ( i==0 ? 0 : vec[i-1] ) ;
        if(i==sz-1) continue ;
        st.insert(get_event(vec[i],vec[i+1])) ;
    }

    LL ret=0LL ;
    for(int i=1;i<sz;i++)
    {
        event e= *st.begin() ; st.erase(st.begin()) ;
        int L=las[e.x] , R=nex[e.y] ;
        ret+= (dep[e.x]-dep[e.lca])*SQR(val[e.x]) ;
        ret+= (dep[e.y]-dep[e.lca])*SQR(val[e.y]) ;
        if(e.x==e.lca)
        {
            if(R) st.erase(get_event(e.y,R)) ,
                st.insert(get_event(e.x,R)) ;
            val[e.x]+=val[e.y] ;
            nex[e.x]=R ;
            las[R]=e.x ;
        }
        else if(e.y==e.lca)
        {
            if(L) st.erase(get_event(L,e.x)) ,
                st.insert(get_event(L,e.y)) ;
            val[e.y]+=val[e.x] ;
            nex[L]=e.y ;
            las[e.y]=L ;
        }
        else
        {
            if(L) st.erase(get_event(L,e.x)) ,
                st.insert(get_event(L,e.lca)) ;
            if(R) st.erase(get_event(e.y,R)) ,
                st.insert(get_event(e.lca,R)) ;
            val[e.lca]=val[e.x]+val[e.y] ;
            nex[L]=e.lca ; las[e.lca]=L ;
            nex[e.lca]=R ; las[R]=e.lca ;
        }
    }
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int R ; scanf("%d%d",&n,&R) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=R;i++) gp[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            gp[x].push_back(i) ;
        }
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }

        tim=0 ; dfs(1,1,0) ;
        build() ;
        for(int i=1;i<=R;i++)
            printf("%d: %lld\n",i,solve(gp[i])) ;
        printf("\n") ;
    }
}
