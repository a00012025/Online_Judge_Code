#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

void gcd(LL a,LL b,LL &x,LL &y,LL d)
{
    if(b==0) { x=d/a ; y=0 ; return ; }
    gcd(b,a%b,y,x,d) ;
    y-=(a/b)*x ;
}

LL solve(LL a,LL b,LL c,LL d) /// ax+b = cy+d , return ax+b or -1
{
    LL x,y , g=__gcd(a,c) ;
    if((d-b)%g) return -1 ;
    gcd(a,-c,x,y,d-b) ;
    while(x>=0 || y>=0) x-=c/g , y-=a/g ;
    while(x<0 || y<0) x+=c/g , y+=a/g ;
    return a*x+b ;
}

int x[maxn],y[maxn] ;
int visx[maxn],visy[maxn] ;
int pth1[maxn],pth2[maxn],cnt1=0,cnt2=0 ;
int a1,b1,a2,b2 ; /// sx use a1 steps to cycle, cycle size = b1.
main()
{
    int n,m,sx,sy,Q ; scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&Q) ;
    for(int i=0;i<n;i++)
    {
        int t ; scanf("%d",&t) ;
        x[i]=((LL)i*t)%n ;
    }
    for(int i=0;i<m;i++)
    {
        int t ; scanf("%d",&t) ;
        y[i]=((LL)i*t)%m ;
    }

    memset(visx,-1,sizeof(visx)) ;
    memset(visy,-1,sizeof(visy)) ;
    for(int i=sx;;i=x[i])
    {
        if(visx[i]!=-1) { a1=visx[i] , b1=cnt1-visx[i] ; break ; }
        visx[i]=cnt1 ; pth1[cnt1]=i ; cnt1++ ;
    }
    for(int i=sy;;i=y[i])
    {
        if(visy[i]!=-1) { a2=visy[i] , b2=cnt2-visy[i] ; break ; }
        visy[i]=cnt2 ; pth2[cnt2]=i ; cnt2++ ;
    }

    while(Q--)
    {
        int ex,ey ; scanf("%d%d",&ex,&ey) ;
        if(visx[ex]==-1 || visy[ey]==-1) { printf("-1\n") ; continue ; }
        if(visx[ex]<a1)
        {
            int tmp=visx[ex] ;
            int id= (tmp<a2 ? tmp : ((tmp-a2)%b2+a2)) ;
            printf("%d\n",pth2[id]==ey ? tmp : -1) ;
        }
        else if(visy[ey]<a2)
        {
            int tmp=visy[ey] ;
            int id= (tmp<a1 ? tmp : ((tmp-a1)%b1+a1)) ;
            printf("%d\n",pth1[id]==ex ? tmp : -1) ;
        }
        else printf("%lld\n",solve(b1,visx[ex],b2,visy[ey])) ;
    }
}
