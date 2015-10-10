#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;
int n ;
LL d[maxn] ;
int dfs(int x,int f,int &id,int &mi)
{
    int sz=1,maxs=0 ;
    for(auto i : v[x]) if(i.to!=f)
    {
        d[i.to]=d[x]+i.dis ;
        int tmp=dfs(i.to,x,id,mi) ;
        sz+=tmp ; maxs=max(maxs,tmp) ;
    }
    int val=max(maxs,n-sz) ;
    if(val<mi) mi=val , id=x ;
    return sz ;
}
void dfs(int x)
{
    int id,mi ;
    dfs(x,-1,id,mi) ; /// calculate dis
}

void dfs2(int x,int f,set<int> &s)
{
    s.insert(x) ;
    for(auto i : v[x]) if(i.to!=f)
        dfs2(i.to,x,s) ;
}

int cent ; /// centroid, also root of tree
set<int> st[maxn],st2 ;
set<pii> st0 ;
int id[maxn],sz,ioval[maxn] ; /// in + out number
bool ruse=0 ; /// whether root used as in point
inline void sub(int pos)
{
    st0.erase(pii(ioval[pos],pos)) ;
    ioval[pos]-- ;
    st0.insert(pii(ioval[pos],pos)) ;
}

int solve(int x)
{
    if(x!=cent) sub(id[x]) ;
    pii r=*st0.rbegin() ;
    if(r.F==n-x+1)
    {
        int pos=r.S , ret=*st[pos].begin() ;
        st2.erase(*st[pos].begin()) ;
        st[pos].erase(st[pos].begin()) ;
        if(!st[pos].empty()) st2.insert(*st[pos].begin()) ;
        sub(pos) ;
        return ret ;
    }

    int tmp=-1 ;
    if(x!=cent && !st[id[x]].empty()) st2.erase(tmp = *st[id[x]].begin()) ;
    int ret=st2.empty() ? cent : *st2.begin() ;
    if(!ruse && cent<ret) ruse=1 , ret=cent ;
    if(tmp!=-1) st2.insert(tmp) ;

    if(ret==cent) return ret ;
    int pos=id[ret] ;
    sub(pos) ;
    st2.erase(*st[pos].begin()) ;
    st[pos].erase(st[pos].begin()) ;
    if(!st[pos].empty()) st2.insert(*st[pos].begin()) ;
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }

    int mi=n ;
    dfs(1,-1,cent,mi) ;
    d[cent]=0 ; dfs(cent) ;

    LL ans=0LL ;
    for(int i=1;i<=n;i++) ans+=d[i] ;
    printf("%I64d\n",2*ans) ;
    if(n==1){printf("1\n") ; return 0 ;}
    if(n==2){printf("2 1\n") ; return 0 ;}

    sz=v[cent].size() ;
    for(int i=0;i<sz;i++)
    {
        dfs2(v[cent][i].to,cent,st[i]) ;
        for(auto j : st[i]) id[j]=i ;
    }
    for(int i=0;i<sz;i++) st2.insert(*st[i].begin()) ;
    for(int i=0;i<sz;i++)
        st0.insert(pii(2*st[i].size(),i)) ,
        ioval[i]=2*st[i].size() ;

    for(int i=1;i<=n;i++) printf("%d%c",solve(i),i==n?'\n':' ') ;
}
