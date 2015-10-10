#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=1000000+10 ;

void gcd(LL a,LL b,LL &x,LL &y,LL d)
{
    if(!b){x=d/a ; y=0 ; return ;}
    gcd(b,a%b,y,x,d) ; y-=(a/b)*x ;
}

LL solve(LL a,LL b,LL c,LL d)
{/// ax+b=cy+d , min pos. value of ax+b when x>=0 , y>=0
    LL g=__gcd(a,c) ;
    if((b-d)%g) return INF ;
    LL x,y ; gcd(a,-c,x,y,d-b) ;
    LL dx=c/g , dy=a/g ;
    while(x>=0||y>=0) x-=dx , y-=dy ;
    while(x<0||y<0) x+=dx , y+=dy ;
    return a*x+b ;
}

int n,vis[maxn] ;
struct P{int x,y;};
P getp(LL h,LL a,LL x,LL y)
{
    memset(vis,0,sizeof(vis)) ;
    int p1=-1 , p2=-1 ;
    for(int cnt=0;;cnt++,h=(x*h+y)%n)
    {
        if(++vis[h]==3) break ;
        if(h==a && vis[h]==1) p1=cnt ;
        else if(h==a && vis[h]==2) p2=cnt-p1 ;
    }
    if(p1!=-1 && p2==-1) p2=0 ;
    return (P){p1,p2} ;
}

main()
{
    int h1,a1,x1,y1,h2,a2,x2,y2 ;
    scanf("%d%d%d%d%d%d%d%d%d",&n,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2) ;
    P p1=getp(h1,a1,x1,y1) , p2=getp(h2,a2,x2,y2) ;
    if(p1.x==-1 || p2.x==-1) printf("-1\n") ;
    else if(p1.y==0 && p2.y==0) printf("%d\n",p1.x==p2.x?p1.x:-1) ;
    else if(p1.y==0)
        printf("%d\n",(p1.x<p2.x || ((p1.x-p2.x)%p2.y) ? -1 : p1.x)) ;
    else if(p2.y==0)
        printf("%d\n",(p2.x<p1.x || ((p2.x-p1.x)%p1.y) ? -1 : p2.x)) ;
    else
    {
        LL ans=solve(p1.y,p1.x,p2.y,p2.x) ;
        printf("%I64d\n",ans==INF ? -1 : ans) ;
    }
}
