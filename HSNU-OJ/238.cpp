#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;
const DB PI=2*acos(0.0) ;

struct pt{int x,y ; DB ang ;}p[1501],q[1501] ;
pt operator - (const pt &a,const pt &b){ return (pt){a.x-b.x,a.y-b.y,0.0} ; }
bool cmp(const pt &a,const pt &b){ return a.ang<b.ang ; }

DB rot(DB x,DB y)
{
    if(x<=y) return y-x ;
    else return 2*PI-x+y ;
}

int n ;
LL cal(int x)
{
    for(int i=1;i<n;i++)
    {
        q[i]= (i>=x ? p[i+1]-p[x] : p[i]-p[x]) ;
        q[i].ang = atan2(q[i].y,q[i].x) ;
    }
    sort(q+1,q+n,cmp) ;
    for(int i=1;i<n;i++)
        if( rot(q[i].ang,q[(i%(n-1))+1].ang) > PI) return 0LL ;

    LL ret=((LL)n-1)*((LL)n-2)*((LL)n-3)/6LL ;
    int j=1 ;
    for(int i=1;i<n;i++)
    {
        while(rot(q[i].ang,q[j].ang) < PI) j=(j%(n-1))+1 ;
        int d=j-i-1 ; if(d<0) d+=n-1 ;
        ret -= ((LL)d)*((LL)d-1)/2 ;
    }
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y) ;
    LL ans=0LL ;
    for(int i=1;i<=n;i++) ans+=cal(i) ;
    printf("%f\n", (n+3)/2.0 - ((DB)6*ans)/( (DB)((LL)n)*((LL)n-1)*((LL)n-2) ) ) ;
}
