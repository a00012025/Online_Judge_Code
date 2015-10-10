#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct P{int s1,s2;}; /// s1 / s2
bool operator < (const P &p1,const P &p2)
{
    return (LL)p2.s2*p1.s1 < (LL)p1.s2*p2.s1 ;
}

int H ;
int x,y,z ;
bool check(LL s1,LL s2,bool fir)
{
    if(s1<0 || s1>=60*s2) return 0 ;
    if(fir && s1<z*s2) return 0 ;
    if(59*s1 == 60*y*s2) return 0 ;
    if(s2*x*3600+s2*60*y+s1 == s2*60*H*y+s1*H) return 0 ;
    if(s2*x*3600+s2*60*y+s1 == s1*60*H) return 0 ;
    return 1 ;
}

P solve(int type)
{
    int s1=60*(60*x+(H+1)*y) , s2=119*H-1 ;
    if(type==1) s1-=3600*H ;
    if(type==2) s1+=3600*H ;
    int g=__gcd(s1,s2) ;
    return (P){s1/g,s2/g} ;
}

P p[3] ;
main()
{
    while(scanf("%d%d%d%d",&H,&x,&y,&z)==4 && H+x+y+z)
    {
        bool fir=1,ok=0 ;
        while(!ok)
        {
            for(int i=0;i<3;i++) p[i]=solve(i) ;
            sort(p,p+3) ;
            for(int i=0;i<3;i++) if(check(p[i].s1,p[i].s2,fir))
            {
                printf("%d %d %d %d\n",x,y,p[i].s1,p[i].s2) ;
                ok=1 ; break ;
            }
            y++ ;
            if(y==60) y-=60 , x++ ;
            if(x==H) x=0 ;
            fir=0 ;
        }
    }
}
