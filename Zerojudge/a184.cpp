#include<bits/stdc++.h>
#define ABS(x) ((x)>0 ? (x) : (-(x)))
using namespace std;
const int maxn=100000+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;
bool vis[maxn] ;
int val[maxn] ;
int ans=0 ;

void dfs(int x,int &mi,int &ma,int d)
{
    vis[x]=1 ; val[x]=d ;
    mi=min(mi,d) ; ma=max(ma,d) ;
    for(auto i : v[x])
    {
        if(vis[i.to]) ans=__gcd(ans,ABS(val[i.to]-val[x]-i.dis)) ;
        else dfs(i.to,mi,ma,d+i.dis) ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back((P){y,1}) ;
        v[y].push_back((P){x,-1}) ;
    }
    int tot=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        int mi=0,ma=0 ;
        dfs(i,mi,ma,0) ;
        tot+=ma-mi+1 ;
    }
    if(ans)
    {
        if(ans<3){printf("-1 -1\n") ; return 0 ;}
        for(int i=3;;i++) if(ans%i==0){printf("%d %d\n",ans,i) ; return 0 ;}
    }
    else
    {
        if(tot<3) printf("-1 -1\n") ;
        else printf("%d 3\n",tot) ;
    }
}
