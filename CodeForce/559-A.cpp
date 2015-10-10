#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-7 ;
const int maxn=100000+10 ;

int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt{DB x,y ;};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) { return (pt){d*a.x,d*a.y} ; }
bool operator == (const pt &a,const pt &b) { return !dcmp(a.x-b.x) && !dcmp(a.y-b.y) ; }
bool operator != (const pt &a,const pt &b) { return !(a==b) ; }

DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }
DB dis2(const pt &a,const pt &b) { return dot(a-b,a-b) ; }
DB length(const pt &a) { return sqrt(dot(a,a)) ; }

typedef vector<pt> poly ;
DB Area(const poly &p)
{
    DB ret=0 ;
    for(int i=1;i+1<p.size();i++)
        ret+=cross(p[0],p[i],p[i+1])/2 ;
    return fabs(ret) ;
}

poly q ;
main()
{
    int a,b,c,d,e,f ; scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f) ;
    pt p=(pt){0,0} ; q.push_back(p) ;
    p=p+(pt){-1.0/2,sqrt(3)/2}*a ; q.push_back(p) ;
    p=p+(pt){1.0/2,sqrt(3)/2}*b ; q.push_back(p) ;
    p=p+(pt){1,0}*c ;  q.push_back(p) ;
    p=p+(pt){1.0/2,-sqrt(3)/2}*d ;  q.push_back(p) ;
    p=p+(pt){-1.0/2,-sqrt(3)/2}*e ; q.push_back(p) ;
    DB A=Area(q) , A0=sqrt(3)/4 ;
    printf("%d\n",int(A/A0+0.5)) ;
}
