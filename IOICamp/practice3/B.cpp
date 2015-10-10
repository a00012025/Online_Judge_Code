#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;
struct P{int x,y,d ;};
bool cmp(const P &a,const P &b){ return a.d<b.d ; }
vector<P> v ;
int n,fa[maxn] ;
int getfa(int x)
{
    return x==fa[x] ? x : fa[x]=getfa(fa[x]) ;
}
int solve()
{
    for(int i=1;i<=n;i++) fa[i]=i ;
    int cnt=0 ;
    for(auto i : v)
    {
        int x=getfa(i.x) , y=getfa(i.y) ;
        if(x!=y) cnt++ , fa[x]=y ;
        if(cnt==n-1) return i.d ;
    }
    return -1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int m ; scanf("%d%d",&n,&m) ;
        v.clear() ;
        while(m--)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            v.push_back((P){x,y,dis}) ;
        }
        sort(v.begin(),v.end(),cmp) ;
        int ans=solve() ;
        if(n==1) ans=0 ;
        if(ans==-1) printf("Earth Worm QAQ\n") ;
        else printf("%d\n",ans) ;
    }
}
