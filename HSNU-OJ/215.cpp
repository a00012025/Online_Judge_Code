#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100+10 ;

struct P
{
    int x,y,dis ;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};

vector<P> E,tmp ;
int fa[maxn],fa2[maxn] ;
int getfa(int x,int *f)
{
    return x==f[x] ? x : f[x]=getfa(f[x],f) ;
}
bool check(int bit)
{
    for(int i=0;i<tmp.size();i++) if(bit&(1<<i))
    {
        int x=tmp[i].x , y=tmp[i].y ;
        if(getfa(x,fa2)==getfa(y,fa2)) return 0 ;
        fa2[getfa(x,fa2)]=getfa(y,fa2) ;
    }
    return 1 ;
}

void solve()
{
    int n,m,MOD ; scanf("%d%d%d",&n,&m,&MOD) ;
    for(int i=1;i<=n;i++) fa[i]=fa2[i]=i ;
    E.clear() ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        E.push_back((P){x,y,dis}) ;
    }
    sort(E.begin(),E.end()) ;

    LL ans=1 ;
    for(int i=0;i<E.size();)
    {
        int j=i ;
        tmp.clear() ;
        for(;j<E.size() && E[j].dis==E[i].dis;j++)
        {
            int x=getfa(E[j].x,fa) , y=getfa(E[j].y,fa) ;
            if(x==y) continue ;
            fa2[x]=x ; fa2[y]=y ;
            tmp.push_back((P){x,y,0}) ;
        }
        int num=0 ;
        for(auto k : tmp)
            if(getfa(k.x,fa2)!=getfa(k.y,fa2))
            num++ , fa2[getfa(k.x,fa2)]=getfa(k.y,fa2) ;

        int mul=0 ;
        for(int k=0;k<(1<<tmp.size());k++) if(__builtin_popcount(k)==num)
        {
            for(auto e : tmp)
                fa2[e.x]=e.x , fa2[e.y]=e.y ;
            if(check(k)) mul++ ;
        }
        ans=ans*mul%MOD ;
        for(;i<j;i++) fa[getfa(E[i].x,fa)]=getfa(E[i].y,fa) ;
    }
    for(int i=1;i<n;i++) if(getfa(i,fa)!=getfa(i+1,fa))
        {printf("-1\n") ; return ;}
    printf("%lld\n",ans) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
