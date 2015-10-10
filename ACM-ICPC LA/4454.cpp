#include<bits/stdc++.h>
#define MIN(X,Y,Z) min(min(X,Y),Z)
#define MAX(X,Y,Z) max(max(X,Y),Z)
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=400+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;
void dfs0(int x,int f)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].to==f)
        {
            swap(v[x][i],v[x].back()) ;
            v[x].pop_back() ;
            i-- ;
        }
        else dfs0(v[x][i].to,x) ;
    }
}

int n,n2 ;
void get_binary()
{
    n2=n ; dfs0(1,1) ;
    for(int i=1;i<=n;i++) if(v[i].size()>2)
    {
        int sz=v[i].size() ;
        for(int j=1;j<sz-2;j++)
            v[n2+j].push_back(v[i][j]) ,
            v[n2+j].push_back((P){n2+j+1,0}) ;
        v[n2+sz-2].push_back(v[i][sz-2]) ;
        v[n2+sz-2].push_back(v[i][sz-1]) ;
        v[i][1]=(P){n2+1,0} ; v[i].resize(2) ;
        n2+=sz-2 ;
    }
}

int lb1(const vector<pii> &p,int x)
{
    return lower_bound(p.begin(),p.end(),pii(x,-1e9))-p.begin() ;
}
int lb2(const vector<pii> &p,int x)
{
    int l=-1 , r=p.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(p[mid].S>=x) r=mid ;
        else l=mid ;
    }
    return r ;
}

bool cmp(const pii &a,const pii &b)
{
    return a.F!=b.F ? a.F<b.F : a.S>b.S ;
}
void normalize(vector<pii> &vp)
{
    sort(vp.begin(),vp.end(),cmp) ;
    int sz2=0 ;
    for(int i=0;i<vp.size();i++)
    {
        while(sz2 && vp[i].S<=vp[sz2-1].S) sz2-- ;
        vp[sz2++]=vp[i] ;
    }
    vp.resize(sz2) ;
}

void process(int dx,int dy,const pii &p,const vector<pii> &vp,vector<pii> &r,int M)
{
    int a1=p.F , b1=p.S ;
    if(a1+dx<-M || a1+dx>M || b1+dx<-M || b1+dx>M) return ;
    int id=max(lb1(vp,MAX(-M-dx-dy-a1,dx-dy+a1,-M-dy)),
               lb2(vp,max(-M-dx-dy-b1,-M-dy))) ;
    if(id==vp.size()) return ;
    int a2=vp[id].F , b2=vp[id].S ;
    if(a2<=min(M-dy,M-dx-dy-a1) && b2<=min(M-dx-dy-b1,M-dy))
        r.push_back(pii(MIN(a1+dx,a2+dy,0),MAX(b1+dx,b2+dy,0))) ;
}

vector<pii> dp[maxn] ;
bool vis[maxn] ;
bool DP(int x,int M,int f=-1)
{
    vis[x]=1 ;
    dp[x].clear() ;
    if(v[x].empty())
    {
        dp[x].push_back((pii){0,0}) ;
        return 1 ;
    }
    for(auto i : v[x]) if(!DP(i.to,M,x)) return 0 ;
    if(v[x].size()==1)
    {
        P &son=v[x][0] ;
        for(int i=son.dis/60*60,t=0;t<2;t++,i+=60)
        {
            int dx=i-son.dis ;
            for(auto it : dp[son.to])
                if(it.F+dx>=-M && it.F+dx<=M && it.S+dx>=-M && it.S+dx<=M)
                dp[x].push_back(pii(min(0,it.F+dx),max(0,it.S+dx))) ;
        }
        normalize(dp[x]) ;
        return !dp[x].empty() ;
    }

    for(int i=v[x][0].dis/60*60,t1=0;t1<2;t1++,i+=60)
        for(int j=v[x][1].dis/60*60,t2=0;t2<2;t2++,j+=60)
    {
        int dx=i-v[x][0].dis , dy=j-v[x][1].dis ;
        for(auto it : dp[v[x][0].to]) process(dx,dy,it,dp[v[x][1].to],dp[x],M) ;
        for(auto it : dp[v[x][1].to]) process(dy,dx,it,dp[v[x][0].to],dp[x],M) ;
    }
    normalize(dp[x]) ;
    return !dp[x].empty()  ;
}

bool check(int M)
{
    return DP(1,M) ;
}

void solve(int tc)
{
    for(int i=0;i<=2*n;i++) v[i].clear() , dp[i].clear() ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    get_binary() ;

    int l=-1 , r=60*n ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("Case %d: %d\n",tc,r) ;
}

main()
{
    int tc=0 ;
    while(scanf("%d",&n)==1 && n) solve(++tc) ;
}
