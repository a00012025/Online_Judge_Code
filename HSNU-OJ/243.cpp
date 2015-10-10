#include<bits/stdc++.h>
#define INF 1100000000
#define LL long long
#define DB double
#define F first
#define S second
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=100000 + 100 , arr[4][3]={{0,7,11},{3,5,9},{1,6,10},{2,4,8}} ;
const int Dx[4][3]={{1,1,1},{-1,0,1},{-1,-1,-1},{-1,0,1}} ;
const int Dy[4][3]={{1,0,-1},{-1,-1,-1},{1,0,-1},{1,1,1}} ;
const int mpid[4][3]={{9,1,4},{11,2,6},{5,0,8},{7,3,10}} ;
struct P
{
    int x,y,dir;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
}a[maxn];
P operator - (const P &p,const P &q) { return (P){p.x-q.x,p.y-q.y,0} ; }

map<int,set<P> >mp[12] ;

int f(const P &p,int type)
{
    if(type<=1) return p.y ;
    if(type<=3) return p.x ;
    if(type<=7) return p.x+p.y ;
    return p.x-p.y ;
}

DB search_in_map(const set<P> &st,const P &p,int dx,int dy)
{
    bool half= !(dx&&dy) ;
    if(dx==-1 || (dx==0 && dy==-1))
    {
        set<P>::iterator it=st.lower_bound(p) ;
        if(it==st.begin()) return INF ;
        it-- ;
        int dx2=(it->x)-p.x , dy2=(it->y)-p.y ;
        if(half) return dx2 ? dx2/dx/2.0 : dy2/dy/2.0 ;
        else return dx2 ? dx2/dx : dy2/dy ;
    }
    else
    {
        set<P>::iterator it=st.upper_bound(p) ;
        if(it==st.end()) return INF ;
        int dx2=(it->x)-p.x , dy2=(it->y)-p.y ;
        if(half) return dx2 ? dx2/dx/2.0 : dy2/dy/2.0 ;
        else return dx2 ? dx2/dx : dy2/dy ;
    }
}

int W,H,k ;
DB get_time(int i)
{
    DB ret ;
    if(a[i].dir==0) ret=W-a[i].x ;
    if(a[i].dir==1) ret=a[i].y-1 ;
    if(a[i].dir==2) ret=a[i].x-1 ;
    if(a[i].dir==3) ret=H-a[i].y ;
    for(int j=0;j<3;j++)
    {
        int Mid=mpid[a[i].dir][j] ;
        int dx=Dx[a[i].dir][j] , dy=Dy[a[i].dir][j] ;
        int val=f(a[i],Mid) ;
        if(!mp[Mid].count(val)) continue ;
        ret=min(ret,search_in_map(mp[Mid][val],a[i],dx,dy)) ;
    }
    return ret ;
}

struct Q
{
    int id ; DB val ;
    bool operator < (const Q &rhs) const
    {
        if(val!=rhs.val) return val>rhs.val ;
        else return id>rhs.id ;
    }
};

DB t[maxn] ;
priority_queue<Q> pq ;
vector<Q> tmp ;
void Dijkstra()
{
    for(int i=1;i<=k;i++)
    {
        t[i]=get_time(i) ;
        pq.push((Q){i,t[i]}) ;
    }
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        DB t2=get_time(u.id) ;
        if(t2!=u.val) { t[u.id]=t2 ; pq.push((Q){u.id,t[u.id]}) ; continue ; }

        tmp.clear() ; tmp.push_back(u) ;
        while(!pq.empty() && pq.top().val==u.val)
        {
            Q v=pq.top() ; pq.pop() ;
            t2=get_time(v.id) ;
            if(t2!=v.val)
                { t[v.id]=t2 ; pq.push((Q){v.id,t[v.id]}) ; continue ; }
            tmp.push_back(v) ;
        }

        for(int i=0;i<tmp.size();i++) for(int j=0;j<3;j++)
        {
            int id=arr[a[tmp[i].id].dir][j] ;
            int val=f(a[tmp[i].id],id) ;
            map<int,set<P> >::iterator it=mp[id].find(val) ;
            if((it->S).size() == 1) mp[id].erase(it) ;
            else (it->S).erase(a[tmp[i].id]) ;
        }
    }
}

struct R
{
    int x,y,z ;
    bool operator < (const R &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        if(y!=rhs.y) return y<rhs.y ;
        return z<rhs.z ;
    }
} ;

R tmp2[maxn] ;
void normalize_vector(vector<R> &v)
{
    sort(v.begin(),v.end()) ;
    int num=0 ;
    for(int i=0;i<v.size();i++)
    {
        if(num && tmp2[num-1].x==v[i].x && tmp2[num-1].z>=v[i].y)
            { tmp2[num-1].z=max(tmp2[num-1].z,v[i].z) ; continue ; }
        tmp2[num++]=v[i] ;
    }
    v.clear() ; for(int i=0;i<num;i++) v.push_back(tmp2[i]) ;
}

vector<R> ver,hor ;
void get_segment()
{
    for(int i=1;i<=k;i++)
    {
        int d=floor(t[i]+0.1) ;
        if(a[i].dir==0)
            hor.push_back((R){a[i].y,a[i].x, a[i].x+d }) ;
        if(a[i].dir==1)
            ver.push_back((R){a[i].x, a[i].y-d ,a[i].y}) ;
        if(a[i].dir==2)
            hor.push_back((R){a[i].y, a[i].x-d ,a[i].x}) ;
        if(a[i].dir==3)
            ver.push_back((R){a[i].x,a[i].y, a[i].y+d }) ;
    }
    normalize_vector(hor) ;
    normalize_vector(ver) ;
}

int search_in_v(const vector<int> &v,int val)
{
    int l=0 , r=v.size() ;
    if(v[0]==val) return 0 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[mid]==val) return mid ;
        if(v[mid]>val) r=mid ;
        else l=mid ;
    }
}

vector<int> ver2,hor2 ;
void discrete()
{
    for(int i=0;i<hor.size();i++)
        ver2.push_back(hor[i].y) , ver2.push_back(hor[i].z) ,
        hor2.push_back(hor[i].x) ;
    for(int i=0;i<ver.size();i++)
        hor2.push_back(ver[i].y) , hor2.push_back(ver[i].z) ,
        ver2.push_back(ver[i].x) ;
    sort(ver2.begin(),ver2.end()) ;
    ver2.resize(unique(ver2.begin(),ver2.end())-ver2.begin()) ;
    sort(hor2.begin(),hor2.end()) ;
    hor2.resize(unique(hor2.begin(),hor2.end())-hor2.begin()) ;
    for(int i=0;i<hor.size();i++)
        hor[i].x=search_in_v(hor2,hor[i].x)+1 ,
        hor[i].y=search_in_v(ver2,hor[i].y)+1 ,
        hor[i].z=search_in_v(ver2,hor[i].z)+1 ;
    for(int i=0;i<ver.size();i++)
        ver[i].x=search_in_v(ver2,ver[i].x)+1 ,
        ver[i].y=search_in_v(hor2,ver[i].y)+1 ,
        ver[i].z=search_in_v(hor2,ver[i].z)+1 ;
}

typedef pair<int,int> Event ;
vector<Event> event[maxn] ;
void get_event()
{
    for(int i=0;i<ver.size();i++)
        event[ver[i].y].push_back(make_pair(ver[i].x,1)) ,
        event[ver[i].z+1].push_back(make_pair(ver[i].x,-1)) ;
}

int bit[2*maxn] ;
void modify(int x,int add)
{
    while(x<2*maxn) bit[x]+=add , x+=lowbit(x) ;
}

int query(int l,int r)
{
    int ret1=0,ret2=0 ;
    l-- ;
    while(l) ret1+=bit[l] , l-=lowbit(l) ;
    while(r) ret2+=bit[r] , r-=lowbit(r) ;
    return ret2-ret1 ;
}

main()
{
    scanf("%d%d%d",&W,&H,&k) ;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].dir) ;
        for(int j=0;j<3;j++)
        {
            int id=arr[a[i].dir][j] ;
            int val=f(a[i],id) ;
            mp[id][val].insert(a[i]) ;
        }
    }

    Dijkstra() ;
    get_segment() ;

    LL ans=0LL ;
    for(int i=0;i<hor.size();i++) ans+= hor[i].z-hor[i].y+1 ;
    for(int i=0;i<ver.size();i++) ans+= ver[i].z-ver[i].y+1 ;
    discrete() ;
    get_event() ;
    int num_h=hor2.size() , num_v=ver2.size() ;
    int nowid=0 ;
    for(int i=1;i<=num_h;i++)
    {
        for(int j=0;j<event[i].size();j++)
            modify(event[i][j].F,event[i][j].S) ;
        while(nowid<hor.size() && hor[nowid].x==i)
            ans-=query(hor[nowid].y,hor[nowid].z) , nowid++ ;
    }
    printf("%lld\n",ans) ;
}
