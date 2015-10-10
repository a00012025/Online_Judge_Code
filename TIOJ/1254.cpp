#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=1000+10 ;
struct pt{DB x,y;};

pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y}; }
DB length(const pt &a) { return sqrt(a.x*a.x+a.y*a.y) ; }

int n,m ;
int dx[]={1,1,0,-1,-1,-1,0,1} ;
int dy[]={0,1,1,1,0,-1,-1,-1} ;
pt a[maxn*maxn] ;

DB cal(const pt &p)
{
    DB ret=0.0 ;
    for(int i=1;i<=m;i++) ret=max(ret,length(p-a[i])) ;
    return ret ;
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        DB x0=0.0,y0=0.0 ;
        for(int i=1;i<=m;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y) ,
            x0+=a[i].x , y0+=a[i].y ;
        x0/=m , y0/=m ;
        DB val=cal((pt){x0,y0}) ;
        for(DB len=1.0;len>1e-1;len*=0.5)
        {
            DB x1,y1 ;
            while(1)
            {
                bool found=0 ;
                DB nx,ny ;
                for(int i=0;i<8;i++)
                {
                    nx=x0+len*dx[i] , ny=y0+len*dy[i] ;
                    DB tmp=cal((pt){nx,ny}) ;
                    if(tmp>=val) continue ;
                    found=1 ; x1=nx ; y1=ny ;
                    val=tmp ;
                }
                if(!found) break ;
                else x0=x1 , y0=y1 ;
            }
        }
        val+=1e-5 ;
        printf("%d\n",int(ceil(val)+1e-5)) ;
    }
}
