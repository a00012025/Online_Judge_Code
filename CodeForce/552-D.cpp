#include<bits/stdc++.h>
#define DB double
#define LL long long
using namespace std;
const int maxn=2000+10 ;

struct pt
{
    int x,y;
    DB ang ;
    void scan(){scanf("%d%d",&x,&y) ;}
    void get(){ang=atan2(y,x);}
    bool operator < (const pt &rhs) const
    {
        return ang<rhs.ang ;
    }
};

pt operator - (const pt &a,const pt &b){return (pt){a.x-b.x,a.y-b.y,0} ;}
int cross(const pt &a,const pt &b){return a.x*b.y-a.y*b.x;}

pt p[maxn],q[maxn] ;
int n ;
LL cal(int x)
{
    for(int i=0,j=0;i<n;i++) if(i!=x)
    {
        q[j]=p[i]-p[x] ;
        if(q[j].x<0||(!q[j].x && q[j].y<0))
            q[j].x=-q[j].x , q[j].y=-q[j].y ;
        int g=__gcd(q[j].x,q[j].y) ;
        if(!g)
        {
            if(q[j].x) q[j].x=1 ;
            else q[j].y=1 ;
        }
        else
        {
            if(g<0) g=-g ;
            q[j].x/=g ; q[j].y/=g ;
        }
        q[j].get() ; j++ ;
    }
    sort(q,q+n-1) ;
    int ret=(n-1)*(n-2)/2 ;
    for(int i=0;i<n-1;)
    {
        int j=i ;
        while(j<n-1 && cross(q[i],q[j])==0) j++ ;
        ret-=(j-i)*(j-i-1)/2 ;
        i=j ;
    }
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) p[i].scan() ;
    LL ans=0LL ;
    for(int i=0;i<n;i++) ans+=cal(i) ;
    printf("%I64d\n",ans/3) ;
}
