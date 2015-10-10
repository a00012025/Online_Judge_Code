#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#include"interactive/122.h"
using namespace std;

int n ;
void get_pos(int x0,int y0,int len,int &X1,int &X2,int &Y1,int &Y2)
{
    int l,r ;

    l=y0 ; if(n+1-len<=y0) r=n+1 ; else r=y0+len ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(!examine(x0,mid)) r=mid ;
        else l=mid ;
    }
    Y2=l ;

    l=max(0,y0-len) , r=y0 ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(examine(x0,mid)) r=mid ;
        else l=mid ;
    }
    Y1=r ;

    l=max(0,x0-len) , r=x0 ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(examine(mid,y0)) r=mid ;
        else l=mid ;
    }
    X1=r ;

    l=x0 ; if(n+1-len<=x0) r=n+1 ; else r=x0+len ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(!examine(mid,y0)) r=mid ;
        else l=mid ;
    }
    X2=l ;
}

main()
{
    int x0,y0 ;
    init(n,x0,y0) ;

    int y1 , y2 ;
    if(!examine(x0,n))
    {
        int l=y0 , r=n ;
        while(r-l>1)
        {
            int mid=l+(r-l)/2 ;
            if(!examine(x0,mid)) r=mid ;
            else l=mid ;
        }
        y2=l ;
    }
    else y2=n ;

    if(!examine(x0,1))
    {
        int l=1 , r=y0 ;
        while(r-l>1)
        {
            int mid=l+(r-l)/2 ;
            if(examine(x0,mid)) r=mid ;
            else l=mid ;
        }
        y1=r ;
    }
    else y1=1 ;

    int dy=y2-y1+1 , len ;
    if(dy%5==0 && !examine(x0,y1+(dy/5))) len=dy/5 ;
    else if(dy%3==0 && !examine(x0,y1+(dy/3))) len=dy/3 ;
    else len=dy ;

    int X1,X2,Y1,Y2 ;
    get_pos(x0,y0,len,X1,X2,Y1,Y2) ; debugf("len=%d , X1=%d , Y1=%d , X2=%d , Y2=%d\n",len,X1,Y1,X2,Y2) ;
    x0=X1+(X2-X1)/2 , y0=Y1+(Y2-Y1)/2 ;

    bool u1=0,u2=0,d1=0,d2=0,l1=0,l2=0,r1=0,r2=0 ;
    if(y0>=1-2*len && y0<=n-2*len && examine(x0,y0+2*len)) u1=1 ;
    if(y0>=1-4*len && y0<=n-4*len && examine(x0,y0+4*len)) u2=1 ;
    if(y0-2*len>=1 && examine(x0,y0-2*len)) d1=1 ;
    if(y0-4*len>=1 && examine(x0,y0-4*len)) d2=1 ;
    if(x0-2*len>=1 && examine(x0-2*len,y0)) l1=1 ;
    if(x0-4*len>=1 && examine(x0-4*len,y0)) l2=1 ;
    if(x0>=1-2*len && x0<=n-2*len && examine(x0+2*len,y0)) r1=1 ;
    if(x0>=1-4*len && x0<=n-4*len && examine(x0+4*len,y0)) r2=1 ;

    int ansx,ansy ;
    if(u1&&d1&&l1&&r1) ansx=x0 , ansy=y0 ;
    else if(!d1 && u2)
    {
        ansy=y0+2*len ;
        if(!l1) ansx=x0+2*len ;
        else if(!r1) ansx=x0-2*len ;
        else ansx=x0 ;
    }
    else if(!u1 && d2)
    {
        ansy=y0-2*len ;
        if(!l1) ansx=x0+2*len ;
        else if(!r1) ansx=x0-2*len ;
        else ansx=x0 ;
    }
    else if(!r1 && l2) ansx=x0-2*len , ansy=y0 ;
    else if(!l1 && r2) ansx=x0+2*len , ansy=y0 ;
    else if(u1 && r1) ansx=x0+len , ansy=y0+len ;
    else if(u1 && l1) ansx=x0-len , ansy=y0+len ;
    else if(d1 && r1) ansx=x0+len , ansy=y0-len ;
    else if(d1 && l1) ansx=x0-len , ansy=y0-len ;

    solution(ansx,ansy) ;
}
