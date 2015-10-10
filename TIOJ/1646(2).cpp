#include<bits/stdc++.h>
#define LL long long
#define SQR(x) (((LL)x)*((LL)x))
using namespace std;
const int maxn=200000+10 ;

int anc[20][maxn] ;
vector<int> v[maxn],gp[maxn] ;
int n,dep[maxn],in[maxn],tim ;
int t[maxn] ;
int val[maxn] ;

int LEN[2*maxn] ;
int G[20][2*maxn] ;
void build_LEN()
{
    for(int i=1,j=0;i<2*maxn;i++)
    {
        if(i>=(1<<j)) j++ ;
        LEN[i]=j-1 ;
    }
}

void dfs(int x,int f,int d)
{
    anc[0][x]=f ; dep[x]=d ;
    in[x]=++tim ; t[tim]=x ;
    for(auto i : v[x]) if(i!=f)
        dfs(i,x,d+1) , t[++tim]=x ;
}

void build()
{
    for(int i=1;(1<<i)<=n;i++) for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]] ;
    for(int i=0;(1<<i)<=tim;i++) for(int j=1;j+(1<<i)-1<=tim;j++)
        G[i][j]= i==0?dep[t[j]]:min(G[i-1][j],G[i-1][j+(1<<(i-1))]) ;
}

int query_fa(int x,int d)
{
    if(d==0) return x ;
    for(int i=19;i>=0 && d;i--) if(d&(1<<i))
        x=anc[i][x] , d^=(1<<i) ;
    return x ;
}
/*
int LCA(int x,int y)
{
    if(x==y) return x ;
    if(dep[x]!=dep[y])
    {
        int dif=dep[x]-dep[y] ;
        if(dif>0) return LCA(query_fa(x,dif),y) ;
        else return LCA(x,query_fa(y,-dif)) ;
    }
    for(int i=19;i>=0;i--) if(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ;
    return x==y ? x : anc[0][x] ;
}
*/
int RMQ(int x,int y)
{
    int l=LEN[y-x+1] ;
    return min(G[l][x],G[l][y-(1<<l)+1]) ;
}

struct event
{
    int x,y,dep ;
    bool operator < (const event &rhs) const
    {
        return dep>rhs.dep ;
    }
};

event get_event(int x,int y)
{
//    int lca=LCA(x,y) ;
    return (event){x,y,RMQ(in[x],in[y])} ;
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
        int lca=query_fa(e.x,dep[e.x]-e.dep) ;
        ret+= (dep[e.x]-dep[lca])*SQR(val[e.x]) ;
        ret+= (dep[e.y]-dep[lca])*SQR(val[e.y]) ;
        if(e.x==lca)
        {
            if(R) st.erase(get_event(e.y,R)) ,
                st.insert(get_event(e.x,R)) ;
            val[e.x]+=val[e.y] ;
            nex[e.x]=R ;
            las[R]=e.x ;
        }
        else if(e.y==lca)
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
                st.insert(get_event(L,lca)) ;
            if(R) st.erase(get_event(e.y,R)) ,
                st.insert(get_event(lca,R)) ;
            val[lca]=val[e.x]+val[e.y] ;
            nex[L]=lca ; las[lca]=L ;
            nex[lca]=R ; las[R]=lca ;
        }
    }
    return ret ;
}

main()
{
    build_LEN() ;
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
