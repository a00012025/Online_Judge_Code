#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct P
{
    int x,y,dis ;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};
vector<P> E ;

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

bool solve()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    E.clear() ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        E.push_back((P){x,y,dis}) ;
    }
    sort(E.begin(),E.end()) ;

    for(int i=0;i<n;i++) fa[i]=i ;
    int mi=0 , ma=0 ;
    for(auto i : E) if(getfa(i.x)!=getfa(i.y))
        fa[getfa(i.x)]=getfa(i.y) , mi+=i.dis ;

    for(int i=0;i<n;i++) fa[i]=i ;
    for(auto i=E.rbegin();i!=E.rend();i++) if(getfa(i->x)!=getfa(i->y))
        fa[getfa(i->x)]=getfa(i->y) , ma+=i->dis ;
    return ma>mi || (mi%2==0) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) printf("%s\n",solve()?"Yes":"No") ;
}
