#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define DB double
using namespace std;

const DB eps=1e-7 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt
{
    DB x,y;
    bool operator == (const pt &rhs) const
    {
        return dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0 ;
    }
    bool operator < (const pt &rhs) const
    {
        if(dcmp(x-rhs.x)==0) return y<rhs.y ;
        else return x<rhs.x ;
    }
};

pt operator + (const pt &a,const pt &b){ return (pt){a.x+b.x , a.y+b.y} ; }
pt operator - (const pt &a,const pt &b){ return (pt){a.x-b.x , a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) { return (pt){d*a.x , d*a.y} ; }

DB dot(const pt &a,const pt &b){ return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b){ return a.x*b.y - a.y*b.x ; }
DB length(const pt &a) {return sqrt(dot(a,a)) ; }

bool pt_on_seg(pt a,pt b,pt p)
{
    return dcmp(cross(a-p,b-p))==0 && dcmp(dot(a-p,b-p))<=0 ;
}

pt get_inter(pt P,pt v,pt Q,pt w)
{
    pt u=P-Q ;
    DB t=cross(w,u)/cross(v,w) ;
    return P + v*t ;
}

pt get_seg_inter(pt a,pt b,pt c,pt d) /// intersection of ab and cd
{
    return get_inter(a,b-a,c,d-c) ;
}

bool seg_proper_inter(pt a,pt b,pt c,pt d)
{
    DB c1=cross(b-a,d-a) , c2=cross(b-a,c-a) ;
    DB c3=cross(d-c,a-c) , c4=cross(d-c,b-c) ;
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0 ;
}

int pt_in_poly(const pt &p,const vector<pt> &poly)
{
    int n=poly.size() ;
    int wn=0 ;
    for(int i=0;i<n;i++)
    {
        if(pt_on_seg(poly[i],poly[(i+1)%n],p)) return -1 ;
        int d1=dcmp(p.y-poly[i].y) ;
        int d2=dcmp(p.y-poly[(i+1)%n].y) ;
        int k=dcmp(cross(poly[(i+1)%n]-poly[i],p-poly[i])) ;
        if(k>0 && d1>=0 && d2<0) wn++ ;
        if(k<0 && d2>=0 && d1<0) wn-- ;
    }
    if(wn!=0) return 1 ;
    else return 0 ;
}

DB area(const vector<pt> &poly)
{
    int n=poly.size() ;
    DB ret=0.0 ;
    for(int i=0;i<n;i++) ret += cross(poly[i],poly[(i+1)%n]) ;
    return ret/2 ;
}

int type(pt p1,pt p2,pt p3)
{
    if(pt_on_seg(p1,p3,p2)) return 0 ;
    if( dcmp(cross(p2-p1,p3-p1))<0 ) return -1 ;
    else return 1 ;
}

void convex_hull(vector<pt> &poly)
{
    vector<pt> v ;
    for(int i=0;i<poly.size();i++) v.push_back(poly[i]) ;
    sort(v.begin(),v.end()) ;
    poly.clear() ;
    pt st1[3000],st2[3000] ; int num1=0,num2=0,n=v.size() ;
    for(int i=0;i<n;i++)
    {
        while(num1>=2 && type(st1[num1-2],st1[num1-1],v[i])<=0) num1-- ;
        st1[num1++]=v[i] ;
    }
    for(int i=0;i<n;i++)
    {
        while(num2>=2 && type(st2[num2-2],st2[num2-1],v[i])>=0) num2-- ;
        st2[num2++]=v[i] ;
    }
    for(int i=0;i<num1;i++) poly.push_back(st1[i]) ;
    for(int i=num2-1;i>=0;i--)
    {
        if(st2[i]==st1[num1-1] || st2[i]==st1[0]) continue ;
        poly.push_back(st2[i]) ;
    }
}

vector<pt> poly1,poly2,newpoly ;
main()
{
    int n,m ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        DB x,y ; scanf("%lf%lf",&x,&y) ;
        poly1.push_back((pt){x,y}) ;
    }
    scanf("%d",&m) ;
    for(int i=0;i<m;i++)
    {
        DB x,y ; scanf("%lf%lf",&x,&y) ;
        poly2.push_back((pt){x,y}) ;
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        pt p1=poly1[i] , p2=poly1[(i+1)%n] ;
        pt p3=poly2[j] , p4=poly2[(j+1)%m] ;
        if(pt_on_seg(p1,p2,p3))
            newpoly.push_back(p3) ;
        if(pt_on_seg(p3,p4,p1))
            newpoly.push_back(p1) ;
        if(seg_proper_inter(p1,p2,p3,p4))
            newpoly.push_back(get_seg_inter(p1,p2,p3,p4)) ;
    }
    for(int i=0;i<n;i++) if(pt_in_poly(poly1[i],poly2)==1)
        newpoly.push_back(poly1[i]) ;
    for(int i=0;i<m;i++) if(pt_in_poly(poly2[i],poly1)==1)
        newpoly.push_back(poly2[i]) ;
    convex_hull(newpoly) ;
    printf("%.2f\n",area(newpoly)) ;
}
