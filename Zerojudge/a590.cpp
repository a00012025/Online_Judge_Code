#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define DB double
using namespace std;
const DB eps=1e-3 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}
struct pt
{
    DB x,y;
    bool operator < (const pt &rhs) const
    {
        if(dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0) return 0 ;
        if(x!=rhs.x) return x<rhs.x ;
        return y<rhs.y ;
    }
};

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x,a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) {return (pt){d*a.x,d*a.y} ;}
DB dot(const pt &a,const pt &b) {return (a.x*b.x + a.y*b.y) ;}
DB cross(const pt &a,const pt &b) {return (a.x*b.y - a.y*b.x) ;}
DB length(const pt &a) {return sqrt(dot(a,a)) ;}

pt rotate_pt(pt p,DB cos_val,bool type)
{
    DB sin_val=sqrt(1-cos_val*cos_val) ;
    if(type==1)
        return (pt){ p.x*cos_val-p.y*sin_val , p.x*sin_val+p.y*cos_val } ;
    else
        return (pt){ p.x*cos_val+p.y*sin_val , -p.x*sin_val+p.y*cos_val } ;
}

pt find_similar(pt p1,pt p2,pt p3,pt a,pt b)
{
    DB cos_val=dot(p3-p1,p2-p1)/(length(p3-p1)*length(p2-p1)) ;
    DB len=length(p3-p1)/length(p1-p2)*length(a-b) ;
    pt ret=a+(rotate_pt(b-a,cos_val,0) * (len/length(b-a))) ;
    if(dcmp(cross(b-a,ret-a)) && dcmp(cross(p2-p1,p3-p1))!=dcmp(cross(b-a,ret-a)))
        ret=a+(rotate_pt(b-a,cos_val,1) * (len/length(b-a))) ;
    return ret;
}

int n,m ;
set<pt> s1[100],s2[100] ;

bool check(int x)
{
    set<pt>::iterator it0,it1 ;
    for(int i=0;i<n;i++)
    {
        if(s1[i].size() != s2[x].size()) continue ;
        it0=s1[i].begin() ;
        it1=s1[i].begin() ; it1++ ;
        pt a=(*it0) , b=(*it1) ;
        for(set<pt>::iterator it2=s2[x].begin() ; it2!=s2[x].end() ; it2++)
            for(set<pt>::iterator it3=s2[x].begin() ; it3!=s2[x].end() ; it3++)
        {
            if(it2==it3) continue ;
            pt p1=(*it2) , p2=(*it3) ;
            bool ok=1 ;
            for(set<pt>::iterator it4=s2[x].begin() ; it4!=s2[x].end() ; it4++)
                if(it4!=it2 && it4!=it3)
            {
                pt p3=(*it4) ;
                pt newp=find_similar(p1,p2,p3,a,b) ;
                if(!s1[i].count((pt){newp.x,newp.y})){ ok=0 ; break ; }
            }
            if(ok) return 1;
        }
    }
    return 0 ;
}

main()
{
        //freopen("pc.txt","r",stdin) ;
        //freopen("pc2.txt","w",stdout) ;
    int T ; scanf("%d",&T) ;
    pt tmp[100][50] ;
    while(T--)
    {
        scanf("%d",&m) ;
        for(int i=0;i<m;i++)
        {
            s2[i].clear() ;
            int num ; scanf("%d",&num) ;
            DB M=0.0 ;
            for(int j=1;j<=num;j++)
            {
                scanf("%lf%lf",&tmp[i][j].x,&tmp[i][j].y) ;
                M=max(M,length(tmp[i][j])) ;
            }
            M=1.0 ;
            for(int j=1;j<=num;j++)
                s2[i].insert((pt){tmp[i][j].x/M,tmp[i][j].y/M}) ;
        }

        scanf("%d",&n) ;
        for(int i=0;i<n;i++)
        {
            s1[i].clear() ;
            int num ; scanf("%d",&num) ;
            DB M=0.0 ;
            for(int j=1;j<=num;j++)
            {
                scanf("%lf%lf",&tmp[i][j].x,&tmp[i][j].y) ;
                M=max(M,length(tmp[i][j])) ;
            }
            M=1.0 ;
            for(int j=1;j<=num;j++)
                s1[i].insert((pt){tmp[i][j].x/M,tmp[i][j].y/M}) ;
        }
        bool fir=1 ;
        for(int i=0;i<m;i++) if(check(i))
        {
            if(fir) fir=0 ;
            else printf(" ") ;
            printf("%d",i+1) ;
        }
        if(fir) printf("so sad\n") ;
        else printf("\n") ;
    }
}
