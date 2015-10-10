#include<bits/stdc++.h>
#define LL long long
#define INF 2100000000
using namespace std;
const int maxn=200000+10 ;

struct pt
{
    int x,y,id ;
    bool operator < (const pt &rhs) const
    {
        return x==rhs.x ? y>rhs.y : x>rhs.x ;
    }
};

struct P
{
    int y,val,id ;
    bool operator < (const P &rhs) const
    {
        return y==rhs.y ? val>rhs.val : y<rhs.y ;
    }
};

struct edge
{
    int x,y,dis ;
    bool operator < (const edge &rhs) const
    {
        return dis<rhs.dis ;
    }
};

void get_pt(pt p0,pt &np,int t)
{
    int x=p0.x , y=p0.y ;
    if(t==1) np=(pt){2*x,y-x,0} ;
    if(t==2) np=(pt){2*y,x-y,0} ;
    if(t==3) np=(pt){-2*y,x+y,0} ;
    if(t==4) np=(pt){2*x,-x-y,0} ;
}

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

int n ;
pt p[maxn],q[maxn] ;

vector<edge> E ;
LL Kruskal()
{
    for(int i=1;i<=n;i++) fa[i]=i ;
    LL ret=0LL ;
    sort(E.begin(),E.end()) ;
    for(auto i : E)
    {
        int x=getfa(i.x) , y=getfa(i.y) ;
        if(x!=y) fa[x]=y , ret+=i.dis ;
    }
    return ret ;
}

set<P> st ;
void Insert(const P &np)
{
    st.insert(np) ; auto it=st.find(np) ;

    bool keep=1 ;
    it++ ;
    if(it!=st.end() && np.val >= it->val)
        keep=0 ;
    it-- ;
    if(!keep) { st.erase(it) ; return ; }

    while(it!=st.begin())
    {
        auto it2=it ; it2-- ;
        if(it2->val >= np.val) st.erase(it2) ;
        else break ;
    }
}

void cal()
{
    st.clear() ;
    for(int i=1;i<=n;i++)
    {
        auto it=st.lower_bound((P){q[i].y,INF,0}) ;
        if(it!=st.end())
        {
            int from=q[i].id , to=it->id ;
            int dis=it->val - q[i].x - q[i].y ;
            E.push_back((edge){from,to,dis}) ;
        }
        Insert((P){q[i].y,q[i].x+q[i].y,q[i].id}) ;
    }
}

main()
{
    int N,M ; scanf("%d%d%d",&N,&M,&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y) ;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n;j++) get_pt(p[j],q[j],i) , q[j].id=j ;
        sort(q+1,q+n+1) ;
        cal() ;
    }
    printf("%lld\n",Kruskal()) ;
}
