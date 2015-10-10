#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=15010 ;
struct pt
{
    int x,y;
    bool operator < (const pt &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
}p[maxn];
int ptcnt ;

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator * (const pt &a,const int &d) { return (pt){d*a.x,d*a.y} ; }
LL Dis(const pt &a,const pt &b){ return abs((LL)(a.x-b.x))+abs((LL)(a.y-b.y)) ;}

vector<pt> vp[maxn] ;
map<pt,int> mp ;
inline int ID(const pt &p){ return mp[p] ; }

struct Q{int ed ; LL dis;};
vector<Q> v[maxn] ;

void add_pt(const pt &a,int recid)
{
    if(mp.count(a)) return ;
    mp[a]=ptcnt ; p[ptcnt]=a ; vp[recid].push_back(a) ;
    ptcnt++ ;
}

void add_pt(const pt &a,const pt &b,int recid)
{
    int dis= a.x==b.x ? abs(a.y-b.y) : abs(a.x-b.x) ;
    if(mp.count(b))
    {
        v[ID(a)].push_back((Q){ID(b),(LL)dis}) ;
        v[ID(b)].push_back((Q){ID(a),(LL)dis}) ;
        return ;
    }

    p[ptcnt]=b ; mp[b]=ptcnt ;
    vp[recid].push_back(b) ;
    v[ID(a)].push_back((Q){ptcnt,(LL)dis}) ;
    v[ptcnt].push_back((Q){ID(a),(LL)dis}) ;
    ptcnt++ ;
}

struct rec{int x1,x2,y1,y2;}a[maxn];
int Dx[]={-1,0,0,1,1,0,0,-1} , Dy[]={0,1,1,0,0,-1,-1,0} ;
pt get_pt(const rec &R,int x)
{
    if(x<2) return (pt){R.x1,R.y2} ;
    if(x<4) return (pt){R.x2,R.y2} ;
    if(x<6) return (pt){R.x2,R.y1} ;
    return (pt){R.x1,R.y1} ;
}

int n ;
int get_rec(const pt &p,int dx,int dy,LL &dis)
{
    int ret=-1 ; dis=INF ;
    for(int i=1;i<=n+2;i++)
    {
        if(dx==0)
        {
            if(!(a[i].x1<=p.x && a[i].x2>=p.x)) continue ;
            if(dy>0 && a[i].y1>p.y && a[i].y1-p.y<dis) dis=a[ret=i].y1-p.y ;
            if(dy<0 && a[i].y2<p.y && p.y-a[i].y2<dis) dis=p.y-a[ret=i].y2 ;
        }
        else
        {
            if(!(a[i].y1<=p.y && a[i].y2>=p.y)) continue ;
            if(dx>0 && a[i].x1>p.x && a[i].x1-p.x<dis) dis=a[ret=i].x1-p.x ;
            if(dx<0 && a[i].x2<p.x && p.x-a[i].x2<dis) dis=p.x-a[ret=i].x2 ;
        }
    }
    return ret ;
}

void get_rec_dis()
{
    for(int i=1;i<=n+2;i++)
        for(int j=0;j<vp[i].size();j++) for(int k=j+1;k<vp[i].size();k++)
    {
        pt now1=vp[i][j] , now2=vp[i][k] ;
        LL dis=INF ;
        if(now1.x==a[i].x1 && now2.x==a[i].x1) dis=Dis(now1,now2) ;
        else if(now1.x==a[i].x2 && now2.x==a[i].x2) dis=Dis(now1,now2) ;
        else if(now1.y==a[i].y1 && now2.y==a[i].y1) dis=Dis(now1,now2) ;
        else if(now1.y==a[i].y2 && now2.y==a[i].y2) dis=Dis(now1,now2) ;
        else for(int z=0;z<8;z+=2)
        {
            pt now3=get_pt(a[i],z) ;
            dis=min(dis,Dis(now1,now3)+Dis(now2,now3)) ;
        }
        v[ID(now1)].push_back((Q){ID(now2),dis}) ;
        v[ID(now2)].push_back((Q){ID(now1),dis}) ;
    }
}

struct R
{
    int id ; LL dis ;
    bool operator < (const R &rhs) const
    {
        return dis>rhs.dis ;
    }
};

priority_queue<R> pq ;
LL d[maxn] ;
bool done[maxn] ;
LL Dijkstra(int st,int ed)
{
    for(int i=0;i<ptcnt;i++) d[i]=INF ;
    memset(done,0,sizeof(done)) ;
    while(!pq.empty()) pq.pop() ;
    d[st]=0 ; pq.push((R){st,0}) ;
    while(!pq.empty())
    {
        R u=pq.top() ; pq.pop() ;
        if(u.id == ed) return u.dis ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            if(d[v[u.id][i].ed] > d[u.id] + v[u.id][i].dis)
            {
                d[v[u.id][i].ed] = d[u.id] + v[u.id][i].dis ;
                pq.push((R){v[u.id][i].ed,d[v[u.id][i].ed]}) ;
            }
        }
    }
    return INF ;
}

main()
{
    int T ; scanf("%d",&T) ;
    int stx,sty,gx,gy ;
    while(T--)
    {
        ptcnt=0 ;
        mp.clear() ;
        for(int i=0;i<maxn;i++) v[i].clear() ;
        for(int i=0;i<maxn;i++) vp[i].clear() ;
        scanf("%d%d%d%d%d",&stx,&sty,&gx,&gy,&n) ;
        a[1]=(rec){stx,stx,sty,sty} ;
        a[2]=(rec){gx,gx,gy,gy} ;
        for(int i=3;i<=n+2;i++)
        {
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2) ;
            if(a[i].x1>a[i].x2) swap(a[i].x1,a[i].x2) ;
            if(a[i].y1>a[i].y2) swap(a[i].y1,a[i].y2) ;
        }

        for(int i=1;i<=n+2;i++) for(int j=0;j<8;j+=2)
            add_pt(get_pt(a[i],j),i) ;

        for(int i=1;i<=n+2;i++) for(int j=0;j<8;j++)
        {
            LL dis ; int recid ;
            pt nowp=get_pt(a[i],j) ;
            recid = get_rec( nowp , Dx[j] , Dy[j] , dis ) ;
            if(recid!=-1)
                add_pt( nowp , nowp+((pt){Dx[j],Dy[j]})*((int)dis) , recid ) ;
        }

        get_rec_dis() ;

        LL ans=Dijkstra(0,1) ;
        if(ans==INF) printf("No Path\n") ;
        else printf("%lld\n",ans) ;
    }
}
