#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define DB double
using namespace std;
const DB eps=1e-10 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}
struct pt
{
    double x,y ;
    bool operator < (const pt &rhs) const
    {
        if(dcmp(x-rhs.x)) return x<rhs.x ;
        return y<rhs.y ;
    }
    bool operator != (const pt &rhs) const
    {
        return dcmp(x-rhs.x)!=0 || dcmp(y-rhs.y)!=0 ;
    }
};

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x,a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) {return (pt){d*a.x,d*a.y} ; }
DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB length(const pt &a) {return sqrt(dot(a,a)) ;}

int n,m ;
vector<pt> b[200],s[200] ;

void init()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        b[i].clear() ;
        int num ; scanf("%d",&num) ;
        while(num--)
        {
            DB u,v ; scanf("%lf%lf",&u,&v) ;
            b[i].push_back((pt){u,v}) ;
        }
    }
    scanf("%d",&m) ;
    for(int i=0;i<m;i++)
    {
        s[i].clear() ;
        int num ; scanf("%d",&num) ;
        while(num--)
        {
            DB u,v ; scanf("%lf%lf",&u,&v) ;
            s[i].push_back((pt){u,v}) ;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<b[i].size();j++) b[i][j] = b[i][j]-b[i][0] ;
        b[i][0]=(pt){0.0,0.0} ;
        pt vec=b[i][1] ;
        DB len=length(vec) ;
        DB Cos=(vec.x)/len , Sin=(vec.y)/len ;
        for(int j=0;j<b[i].size();j++)
        {
            DB x=b[i][j].x , y=b[i][j].y ;
            b[i][j]=(pt){(x*Cos+y*Sin)/len , (-x*Sin+y*Cos)/len} ;
        }
        sort(b[i].begin(),b[i].end()) ;
    }
}

bool check(int x)
{
    for(int i=0;i<m;i++)
    {
        if(b[x].size()!=s[i].size()) continue ;
        for(int j=0;j<s[i].size();j++) for(int k=0;k<s[i].size();k++) if(j!=k)
        {
            vector<pt> tmp ; tmp.clear() ;
            pt vec=s[i][k]-s[i][j] ;
            DB len=length(vec) ;
            DB cos_val=(vec.x)/len , sin_val=(vec.y)/len ;
            for(int z=0;z<s[i].size();z++)
            {
                pt p2=s[i][z]-s[i][j] ;
                tmp.push_back((pt){(p2.x*cos_val+p2.y*sin_val)/len , (-p2.x*sin_val+p2.y*cos_val)/len}) ;
            }
            sort(tmp.begin(),tmp.end()) ;
            bool ok=1 ;
            for(int z=0;z<b[x].size();z++) if(b[x][z]!=tmp[z]) {ok=0 ; break ;}
            if(ok) return 1 ;
        }
    }
    return 0 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        init() ;
        bool fir=1 ;
        for(int i=0;i<n;i++) if(check(i))
        {
            if(fir) fir=0 ;
            else printf(" ") ;
            printf("%d",i+1) ;
        }
        if(fir) printf("so sad\n") ;
        else printf("\n") ;
    }
}
