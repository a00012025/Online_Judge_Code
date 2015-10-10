#include<bits/stdc++.h>
#define INF 1100000000
#define lowbit(x) (x&-x)
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

int bit[2*maxn] ;
void add(int x,int val)
{
    while(x<2*maxn) bit[x]+=val , x+=lowbit(x) ;
}

int query(int l,int r)
{
    l-- ;
    int ret=0 ;
    while(r) ret+=bit[r] , r-=lowbit(r) ;
    while(l) ret-=bit[l] , l-=lowbit(l) ;
    return ret ;
}

struct seg
{
    int x1,y1,x2,y2 ;
    bool operator < (const seg &rhs) const
    {
        return y1<rhs.y1 ;
    }
};

struct event
{
    int t,pos,val ;
    bool operator < (const event &rhs) const
    {
        return t<rhs.t ;
    }
}eve[2*maxn];

vector<int> tv ;
LL cal(vector<seg> &ver,vector<seg> &hor)
{
    if(ver.empty() || hor.empty()) return 0LL ;
    memset(bit,0,sizeof(bit)) ;
    tv.clear() ;
    for(auto i : ver) tv.push_back(i.x1) ;
    for(auto i : hor)
        tv.push_back(i.x1) ,
        tv.push_back(i.x2) ;
    sort(tv.begin(),tv.end()) ;
    tv.resize(unique(tv.begin(),tv.end())-tv.begin()) ;

    int ecnt=0 ;
    for(auto i : ver)
    {
        int x=lower_bound(tv.begin(),tv.end(),i.x1)-tv.begin() ;
        x++ ;
        int y1=min(i.y1,i.y2) , y2=max(i.y1,i.y2) ;
        eve[ecnt++]=(event){y1,x,1} ;
        eve[ecnt++]=(event){y2,x,-1} ;
    }
    sort(eve,eve+ecnt) ;
    sort(hor.begin(),hor.end()) ;

    LL ans=0LL ;
    int j=0 ;
    for(auto i : hor)
    {
        while(j<ecnt && eve[j].t<i.y1)
        {
            add(eve[j].pos,eve[j].val) ;
            j++ ;
        }
        int x1=lower_bound(tv.begin(),tv.end(),i.x1)-tv.begin() ;
        int x2=lower_bound(tv.begin(),tv.end(),i.x2)-tv.begin() ;
        x1++ ; x2++ ;
        if(x1>x2) swap(x1,x2) ;
        ans+=query(x1,x2) ;
    }
    return ans ;
}

struct pt
{
    int x,y,type ; /// type=1 : \ , type=2 : /
    bool operator < (const pt &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
};

map<int,vector<pt> > mph,mpv ;
pt getpt(const pt &p,int dir) /// 1~4 : up , down , left , right
{
    if(dir<=2)
    {
        auto it=mpv.find(p.x) ;
        int id ;
        if(dir==1) id=upper_bound(it->S.begin(),
                    it->S.end(),p)-it->S.begin() ;
        else id=lower_bound(it->S.begin(),
                    it->S.end(),p)-it->S.begin()-1 ;
        if(id<it->S.size() && id>=0) return it->S[id] ;
        pt ret ;
        ret.type=-1 ; ret.x=p.x ;
        ret.y= dir==1 ? INF : -INF ;
        return ret ;
    }
    else
    {
        auto it=mph.find(p.y) ;
        int id ;
        if(dir==4) id=upper_bound(it->S.begin(),
                    it->S.end(),p)-it->S.begin() ;
        else id=lower_bound(it->S.begin(),
                    it->S.end(),p)-it->S.begin()-1 ;
        if(id<it->S.size() && id>=0) return it->S[id] ;
        pt ret ;
        ret.type=-1 ; ret.y=p.y ;
        ret.x= (dir==4 ? INF : -INF) ;
        return ret ;
    }
}

bool on_seg(const pt &p,const pt &a,const pt &b)
{
    if(a.x==b.x) return p.x==a.x &&
        (LL)(p.y-a.y)*(p.y-b.y)<0 ;
    else return p.y==a.y &&
        (LL)(p.x-a.x)*(p.x-b.x)<0 ;
}

int getpath(pt st,int dir,vector<seg> &pth)
{
    pt now=st ;
    while(1)
    {
        pt newp=getpt(now,dir) ;
        if(on_seg(st,now,newp))
        {
            pth.push_back((seg){now.x,now.y,st.x,st.y}) ;
            if(dir<=2) return 3-dir ;
            else return 7-dir ;
        }

        pth.push_back((seg){now.x,now.y,newp.x,newp.y}) ;
        if(newp.type>0)
        {
            if(newp.type==2) dir=5-dir ;
            else if(dir%2) dir=4-dir ;
            else dir=6-dir ;
            now=newp ;
        }
        else return -1 ;
    }
}

vector<seg> pst,ped ;
vector<seg> v1,v2,h1,h2 ;
LL solve(const pt &ed)
{
    getpath((pt){0,0,-1},1,pst) ;
    bool ok[5] ; memset(ok,0,sizeof(ok)) ;
    for(int i=1;i<5;i++) if(!ok[i])
    {
        int res=getpath(ed,i,ped) ;
        if(res!=-1) ok[res]=1 ;
    }

    for(auto i : pst)
    {
        if(i.x1==i.x2) v1.push_back(i) ;
        else h2.push_back(i) ;
    }
    for(auto i : ped)
    {
        if(i.x1==i.x2) v2.push_back(i) ;
        else h1.push_back(i) ;
    }
    return cal(v1,h1)+cal(v2,h2) ;
}

main()
{
    if(fopen("optics.in","r"))
    {
        freopen("optics.in","r",stdin) ;
        freopen("optics.out","w",stdout) ;
    }
    int n,ex,ey ; scanf("%d%d%d",&n,&ex,&ey) ;
    while(n--)
    {
        pt p ; char s[5] ;
        scanf("%d%d%s",&p.x,&p.y,s) ;
        if(s[0]=='\\') p.type=1 ;
        else p.type=2 ;
        mph[p.y].push_back(p) ;
        mpv[p.x].push_back(p) ;
    }
    mph[0].push_back((pt){0,0,-1}) ;
    mpv[0].push_back((pt){0,0,-1}) ;
    for(auto &i : mph) sort(i.S.begin(),i.S.end()) ;
    for(auto &i : mpv) sort(i.S.begin(),i.S.end()) ;

    printf("%lld\n",solve((pt){ex,ey,-1})) ;
}
