#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct P{LL x,y ;}st[maxn] ;

inline bool concave(const P &a,const P &b,const P &c)
{
    return (b.x-a.x)*(c.y-b.y)<=(b.y-a.y)*(c.x-b.x) ;
}

char s[maxn] ;
P a[maxn] ;

LL ansl,ansr,ansnum ;
bool better(LL l,LL r)
{
    if(ansl==-1) return 1 ;

    LL x1=ansr-ansl , y1=a[ansr].y-a[ansl].y ;
    LL x2=r-l , y2=a[r].y-a[l].y ;
    if(x1*y2!=x2*y1) return x1*y2>x2*y1 ;
    if(x1!=x2) return x2<x1 ;
    return l<ansl ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,L ; scanf("%d%d%s",&n,&L,s+1) ;
        for(int i=1;i<=n;i++)
            a[i].y= (s[i]=='1' ? (a[i-1].y+1) : a[i-1].y) ,
            a[i].x= i ;

        ansl=ansr=-1 ;
        int sz=0,now=0 ;
        for(int i=L;i<=n;i++)
        {
            while(sz>=2 && concave(st[sz-2],st[sz-1],a[i-L]))
                sz-- ;
            if(now>=sz) now=sz-1 ;

            st[sz++]=a[i-L] ;
            if(now<0) now=0 ;
            while( now<sz-1 && ((a[i].x-st[now].x)*(a[i].y-st[now+1].y)
                  >= (a[i].y-st[now].y)*(a[i].x-st[now+1].x)) ) now++ ;

            if(better(st[now].x,i))
                ansl=st[now].x , ansr=i ;
        }
        printf("%lld %lld\n",ansl+1,ansr) ;
    }
}
