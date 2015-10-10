#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;
int ans1,ans2 ;
struct pii{int x,y;};
pii cal(const vector<pii> &p)
{
    int mx1=0,idx=0,mx2=0 ;
    int my1=0,idy=0,my2=0 ;
    int retx=-1 , rety=-1 ;
    for(int i=0;i<p.size();i++)
    {
        if(p[i].x>=mx1) mx2=mx1 , mx1=p[i].x , idx=i ;
        else mx2=max(mx2,p[i].x) ;
        if(p[i].y>=my1) my2=my1 , my1=p[i].y , idy=i ;
        else my2=max(my2,p[i].y) ;
        retx=max(retx,p[i].x) ;
        rety=max(rety,p[i].y) ;
    }
    if(mx2) ans2=max(ans2,mx1+mx2) ;
    ans2=max(ans2,my1+my2) ;
    for(int i=0;i<p.size();i++) if(p[i].x)
        ans1=max(ans1,p[i].x+(i==idy ? my2 : my1)) ;
    return (pii){retx,rety} ;
}

pii dfs(int x,int f)
{
    if(x!=f && v[x].size()==1) return (pii){0,0} ;
    vector<pii> tmp ;
    for(auto i : v[x]) if(i.to!=f)
    {
        pii p=dfs(i.to,x) ;
        if(i.dis==1) tmp.push_back((pii){p.y+1,p.x ? p.x+1 : 0}) ;
        else tmp.push_back((pii){p.x ? p.x+2 : 0,p.y+2}) ;
    }
    pii ret=cal(tmp) ;
    ans1=max(ans1,ret.x) ;
    ans2=max(ans2,ret.y) ;
    return ret ;
}

main()
{
    int n,q ;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<n;i++)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            v[x].push_back((P){y,dis}) ;
            v[y].push_back((P){x,dis}) ;
        }
        ans1=ans2=0 ;
        dfs(1,1) ;
        while(q--)
        {
            int x ; scanf("%d",&x) ;
            if((x%2) && x<=ans1) printf("Y") ;
            else if(!(x%2) && x<=ans2) printf("Y") ;
            else printf("N") ;
        }
        printf("\n") ;
    }
}
