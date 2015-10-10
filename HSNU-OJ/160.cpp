#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100+10 ;
const DB PI=2*acos(0),eps=1e-7 ;
int dcmp(const DB &x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt{DB x,y;};
pt operator + (const pt &a,const pt &b){return (pt){a.x+b.x,a.y+b.y} ;}
pt operator - (const pt &a,const pt &b){return (pt){a.x-b.x,a.y-b.y} ;}
pt operator * (const pt &a,const DB &d){return (pt){d*a.x,d*a.y} ;}
DB length(const pt &a){return sqrt(a.x*a.x+a.y*a.y) ;}
DB angle(const pt &a){return atan2(a.y,a.x) ;}

struct cir{pt p ; DB R;};
inline bool in_cir(const pt &p,const cir &C)
{
    return dcmp(length(C.p-p)-C.R)<=0 ;
}

bool get_inter_ang(const cir &c1,const cir &c2,DB &ang1,DB &ang2)
{
    DB d=length(c1.p-c2.p) , R1=c1.R , R2=c2.R ;
    if(dcmp(d-R1-R2)>0 || dcmp(R1-d-R2)>0 || dcmp(R2-d-R1)>0) return 0 ;
    if(!dcmp(d) && !dcmp(R1-R2)) return 0 ;
    ang1=acos((d*d+R1*R1-R2*R2)/(2*d*R1)) ;
    ang2=acos((d*d+R2*R2-R1*R1)/(2*d*R2)) ;
    return 1 ;
}

int n ;
cir c[maxn] ;
vector<DB> v[maxn] ;
DB process(int id)
{
    DB ret=0 ;
    for(int i=0;i+1<v[id].size();i++)
    {
        DB ang1=v[id][i] , ang2=v[id][i+1] ;
        if(!dcmp(ang1-ang2)) continue ;
        DB ang=(ang1+ang2)/2 , add=c[id].R*(ang2-ang1) ;
        pt np=c[id].p+(pt){cos(ang),sin(ang)}*c[id].R ;
        bool ok=1 ;
        for(int j=0;j<n;j++) if(j!=id && in_cir(np,c[j]))
            {ok=0 ; break ;}
        if(ok) ret+=add ;
    }
    return ret ;
}

void solve()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        v[i].clear() ;
        scanf("%lf%lf%lf",&c[i].p.x,&c[i].p.y,&c[i].R) ;
        v[i].push_back(PI/2) ;
        v[i].push_back(-PI/2) ;
    }
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        if(!dcmp(length(c[i].p-c[j].p)) && !dcmp(c[i].R-c[j].R))
    {
        swap(c[i],c[n-1]) ;
        i-- ; n-- ;
        break ;
    }
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    {
        DB ang1,ang2 ;
        if(!get_inter_ang(c[i],c[j],ang1,ang2)) continue ;
        v[i].push_back(angle(c[j].p-c[i].p)+ang1) ;
        v[i].push_back(angle(c[j].p-c[i].p)-ang1) ;
        v[j].push_back(angle(c[i].p-c[j].p)+ang2) ;
        v[j].push_back(angle(c[i].p-c[j].p)-ang2) ;
    }
    DB ans=0 ;
    for(int i=0;i<n;i++)
    {
        for(auto &j : v[i])
        {
            if(dcmp(j-PI)>=0) j-=2*PI ;
            else if(dcmp(j+PI)<=0) j+=2*PI ;
        }
        sort(v[i].begin(),v[i].end()) ;
        v[i].push_back(v[i][0]+2*PI) ;
        ans+=process(i) ;
    }
    int ansb=0 ;
    while(ans<1) ans*=10 , ansb-- ;
    while(ans>=10) ans/=10 , ansb++ ;
    printf("%.2f %d\n",ans,ansb) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
