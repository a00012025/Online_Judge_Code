#include<bits/stdc++.h>
using namespace std;
struct P
{
    int x,y;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
    bool operator == (const P &rhs) const
    {
        return x==rhs.x && y==rhs.y ;
    }
};

P a[1001] ;
main()
{
    int n,x0,y0 ; scanf("%d%d%d",&n,&x0,&y0) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y) ;
        a[i].x-=x0 , a[i].y-=y0 ;
    }
    for(int i=0;i<n;i++)
    {
        int g=__gcd(a[i].x,a[i].y) ;
        a[i].x/=g ; a[i].y/=g ;
        if(a[i].x<0) a[i].x=-a[i].x , a[i].y=-a[i].y ;
    }
    sort(a,a+n) ;
    printf("%d\n",unique(a,a+n)-a) ;
}
