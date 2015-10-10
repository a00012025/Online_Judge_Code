#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000
using namespace std;

struct P
{
    LL x,y ;
    bool operator < (const P &rhs) const
    {
        return x*rhs.y > y*rhs.x ;
    }
}p[16000001];

main()
{
    int cnt=0 ;
    for(int i=1;i<=4000;i++) for(int j=1;j<=4000;j++)
    {
        if(__gcd(i,j)==1)
        {
            p[cnt++]=(P){i,j} ;
            if(cnt>250010) break ;
        }
    }
    sort(p,p+cnt) ;

    printf("1000000\n") ;
    int x=0,y=-INF ;
    for(int i=0;i<250000;i++)
    {
        x+=p[i].x , y+=p[i].y ;
        printf("%d %d\n",x,y) ;
    }
    for(int i=0;i<250000;i++)
    {
        x-=p[i].y , y+=p[i].x ;
        printf("%d %d\n",x,y) ;
    }
    for(int i=0;i<250000;i++)
    {
        x-=p[i].x , y-=p[i].y ;
        printf("%d %d\n",x,y) ;
    }
    for(int i=0;i<250000;i++)
    {
        x+=p[i].y , y-=p[i].x ;
        printf("%d %d\n",x,y) ;
    }
}
