#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define DB double
#define pb(x) push_back(x)
using namespace std;
const int maxm=3000 ;
struct pt{DB x,y;};
struct cir{DB x,y,r;};

const DB eps=1e-7 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    else return x>0 ? 1 : -1 ;
}

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x , a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x , a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) {return (pt){d*a.x,d*a.y} ; }
DB dot(const pt &a,const pt &b){return a.x*b.x + a.y*b.y ;}
DB cross(const pt &a,const pt &b) {return a.x*b.y - a.y*b.x ;}
DB length(const pt &a) {return sqrt(dot(a,a)) ;}

bool on_segment(const pt &a,const pt &b,const pt &p)
{
    return dcmp(cross(a-p,b-p))==0 && dcmp(dot(a-p,b-p))<=0 ;
}

void normalize(pt &p)
{
    DB len=length(p) ;
    p = p * (1/len) ;
}

DB pt_to_seg(pt p,pt a,pt b)
{
    return fabs(cross(p-a,b-a))/length(a-b) ;
}

pt pt_foot(pt p,pt a,pt b)
{
    return a + (b-a) * ( (dot(b-a,p-a))/((length(a-b))*(length(a-b))) ) ;
}

bool seg_inter_circle(const pt &a,const pt &b,const cir &C1)
{
    pt cent=(pt){C1.x,C1.y} ;
    if( dcmp(pt_to_seg(cent,a,b)-C1.r)>=0 ) return 0 ;
    if(dcmp(length(cent-a)-C1.r)<=0) return 1 ;
    if(dcmp(length(cent-b)-C1.r)<=0) return 1 ;
    pt foot=pt_foot(cent,a,b) ;
    return dcmp(dot(a-foot,b-foot))>0 ? 0 : 1 ;
}

void get_tang_pt(const pt &p,const cir &C1,pt &a,pt &b)
{
    pt cent=(pt){C1.x,C1.y} ;
    DB dis=length(cent-p) , tglen=sqrt(dis*dis-C1.r*C1.r) ;
    pt foot= cent + (p-cent) * ( (C1.r/dis)*(C1.r/dis) ) ;
    pt N=(pt){ (cent-p).y , (p-cent).x } ; normalize(N) ;
    N = N * (tglen * (C1.r/dis)) ;
    a=foot+N ; b=foot-N ;
}

void get_ext_tang_pt(const cir &C1,const cir &C2,pt &a,pt &b,pt &c,pt &d)
{
    /// ab , cd are external common tangent line of C1 and C2
    /// a,c are on C1 , b,d are on C2
    pt cent1=(pt){C1.x,C1.y} , cent2=(pt){C2.x,C2.y} ;
    if(dcmp(C1.r-C2.r)==0)
    {
        pt N=(pt){ C1.y-C2.y , C2.x-C1.x } ; normalize(N) ;
        N = N * C1.r ;
        a = cent1+N , b = cent2+N ;
        c = cent1-N , d = cent2-N ;
        return ;
    }
    pt add , p ;
    if(dcmp(C1.r-C2.r) < 0)
    {
        DB dis=length(cent1-cent2) * ( (C2.r)/(C2.r-C1.r) ) ;
        add=cent1-cent2 ; normalize(add) ;
        add = add * dis ;
        p=cent2+add ;
    }
    else
    {
        DB dis=length(cent2-cent1) * ( (C1.r)/(C1.r-C2.r) ) ;
        add=cent2-cent1 ; normalize(add) ;
        add = add * dis ;
        p=cent1+add ;
    }
    get_tang_pt(p,C1,a,c) ; get_tang_pt(p,C2,b,d) ;
    if(!on_segment(p,a,b) && !on_segment(p,b,a)) swap(a,c) ;
}

void get_int_tang_pt(const cir &C1,const cir &C2,pt &a,pt &b,pt &c,pt &d)
{
    /// ab , cd are internal common tangent line of C1 and C2
    /// a,c are on C1 , b,d are on C2
    pt cent1=(pt){C1.x,C1.y} , cent2=(pt){C2.x,C2.y} ;
    DB dis=length(cent1-cent2) ;
    pt add = (cent1-cent2) ; normalize(add) ;
    add = add * ( dis * ( C2.r/(C1.r+C2.r) ) ) ;
    pt p=cent2+add ;
    get_tang_pt(p,C1,a,c) ; get_tang_pt(p,C2,b,d) ;
    if(!on_segment(a,b,p)) swap(a,c) ;
}

cir C[200] ;
int n,cnt ;
DB dis[maxm][maxm] ;
vector<int> poc[200],v[maxm] ;
pt P[maxm] ;

void new_pt(int a,const pt &p,int id)
{
    P[cnt]=p ; v[a].pb(cnt) ; v[cnt].pb(a) ;
    dis[a][cnt]=dis[cnt][a]=length(P[cnt]-P[a]) ;
    poc[id].push_back(cnt) ;
    cnt++ ;
}

void new_pt(int id1,int id2,const pt &p,const pt &q)
{
    P[cnt++]=p ; P[cnt++]=q ;
    v[cnt-1].pb(cnt-2) ; dis[cnt-1][cnt-2]=length(p-q) ;
    v[cnt-2].pb(cnt-1) ; dis[cnt-2][cnt-1]=length(p-q) ;
    poc[id1].pb(cnt-2) ;
    poc[id2].pb(cnt-1) ;
}

void get_new_pt()
{
    for(int i=1;i<=n;i++)
    {
        pt p,q,r,s ;
        get_tang_pt((pt){0,0},C[i],p,q) ; get_tang_pt((pt){1000,1000},C[i],r,s) ;
        bool keep1=1,keep2=1,keep3=1,keep4=1 ;
        for(int j=1;j<=n;j++) if(j!=i)
        {
            if(seg_inter_circle((pt){0,0},p,C[j])) keep1=0 ;
            if(seg_inter_circle((pt){0,0},q,C[j])) keep2=0 ;
            if(seg_inter_circle((pt){1000,1000},r,C[j])) keep3=0 ;
            if(seg_inter_circle((pt){1000,1000},s,C[j])) keep4=0 ;
        }
        if(keep1) new_pt(0,p,i) ;
        if(keep2) new_pt(0,q,i) ;
        if(keep3) new_pt(1,r,i) ;
        if(keep4) new_pt(1,s,i) ;
    }
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
    {
        pt p,q,r,s ;
        get_ext_tang_pt(C[i],C[j],p,q,r,s) ;
        bool keep1=1,keep2=1 ;
        for(int k=1;k<=n;k++) if(k!=i && k!=j)
        {
            if(seg_inter_circle(p,q,C[k])) keep1=0 ;
            if(seg_inter_circle(r,s,C[k])) keep2=0 ;
        }
        if(keep1) new_pt(i,j,p,q) ;
        if(keep2) new_pt(i,j,r,s) ;
        get_int_tang_pt(C[i],C[j],p,q,r,s) ;
        keep1=1,keep2=1 ;
        for(int k=1;k<=n;k++) if(k!=i && k!=j)
        {
            if(seg_inter_circle(p,q,C[k])) keep1=0 ;
            if(seg_inter_circle(r,s,C[k])) keep2=0 ;
        }
        if(keep1) new_pt(i,j,p,q) ;
        if(keep2) new_pt(i,j,r,s) ;
    }
}

DB dis_on_cir(const pt &p,const pt &q,const cir &C1)
{
    pt cent1=(pt){C1.x,C1.y} ;
    return C1.r * acos( (dot(p-cent1,q-cent1))/(C1.r*C1.r) ) ;
}

void get_new_seg()
{
    for(int i=1;i<=n;i++)
    for(int j=0;j<poc[i].size();j++) for(int k=j+1;k<poc[i].size();k++)
    {
        dis[poc[i][j]][poc[i][k]]=dis[poc[i][k]][poc[i][j]]
            =dis_on_cir(P[poc[i][j]],P[poc[i][k]],C[i]) ;
        v[poc[i][j]].pb(poc[i][k]) ;
        v[poc[i][k]].pb(poc[i][j]) ;
    }
}

struct Q
{
    int id ; DB val ;
    bool operator < (const Q &rhs) const
    {
        if(dcmp(val-rhs.val)) return val>rhs.val ;
        else return id<rhs.id ;
    }
};

DB d[maxm] ;
const DB INF=10000000.0 ;
bool done[maxm] ;
DB dijkstra()
{
    priority_queue<Q> pq ;
    for(int i=0;i<cnt;i++) d[i]=INF ;
    memset(done,0,sizeof(done)) ;
    d[0]=0.0 ; pq.push((Q){0,0.0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            if(d[u.id]+dis[u.id][v[u.id][i]] < d[v[u.id][i]] )
            {
                d[v[u.id][i]] = d[u.id]+dis[u.id][v[u.id][i]] ;
                pq.push((Q){v[u.id][i] , d[v[u.id][i]]}) ;
            }
        }
    }
    return d[1];
}

main()
{
        //freopen("pg.txt","r",stdin) ;
    int T; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<=n;i++) poc[i].clear() ;
        for(int i=0;i<8*n*n;i++) v[i].clear() ;
        for(int i=0;i<8*n*n;i++) for(int j=i;j<8*n*n;j++) dis[i][j]=dis[j][i]= i==j?0:INF ;
        P[0]=(pt){0,0} , P[1]=(pt){1000,1000} ;
        cnt=2 ;
        for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&C[i].x,&C[i].y,&C[i].r) ;
        bool ok=1 ;
        for(int i=1;i<=n;i++) if(seg_inter_circle(P[0],P[1],C[i])) {ok=0 ; break ;}
        if(ok) {printf("%.2f\n",length(P[1])) ; continue ;}
        get_new_pt() ;
        get_new_seg() ;
        for(int i=0;i<cnt;i++) debugf("P[%d] : (%lf,%lf)\n",i,P[i].x,P[i].y) ;
        for(int i=0;i<cnt;i++)
        {
            debugf("v[%d] : ",i) ;
            for(int j=0;j<v[i].size();j++) debugf("%d ",v[i][j]) ;
            debugf("\n") ;
        }
        for(int i=1;i<=n;i++)
        {
            debugf("poc[%d] : ",i) ;
            for(int j=0;j<poc[i].size();j++) debugf("%d ",poc[i][j]) ;
            debugf("\n") ;
        }
        printf("%.2f\n",dijkstra()) ;
        for(int i=0;i<cnt;i++) debugf("d[%d] = %lf\n",i,d[i]) ;
    }
}
