#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct P
{
    int from,to,dis;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};

struct Q{int x,y,id;};
bool cmp1(const Q &a,const Q &b)
{
    if(a.x==b.x) return a.y<b.y ;
    return a.x<b.x ;
}
bool cmp2(const Q &a,const Q &b)
{
    if(a.y==b.y) return a.x<b.x ;
    return a.y<b.y ;
}

Q a[maxn] ;
vector<P> edge ;
int n,fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

LL Kruskal()
{
    for(int i=1;i<=n;i++) fa[i]=i ;
    LL ans=0LL ;
    sort(edge.begin(),edge.end()) ;
    for(auto i : edge)
    {
        int x=getfa(i.from) , y=getfa(i.to) ;
        if(x!=y) fa[x]=y , ans+=i.dis ;
    }
    return ans ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        edge.clear() ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y) , a[i].id=i ;

        sort(a+1,a+n+1,cmp1) ;
        for(int i=1;i<n;i++) if(a[i].x==a[i+1].x)
            edge.push_back((P){a[i].id,a[i+1].id,a[i+1].y-a[i].y}) ;

        sort(a+1,a+n+1,cmp2) ;
        for(int i=1;i<n;i++) if(a[i].y==a[i+1].y)
            edge.push_back((P){a[i].id,a[i+1].id,a[i+1].x-a[i].x}) ;

        printf("%lld\n",Kruskal()) ;
    }
}
