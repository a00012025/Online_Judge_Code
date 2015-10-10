#include<bits/stdc++.h>
#define DB double
#define INF 1000000
using namespace std;

struct pt{DB x,y ;};

pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB length(const pt &a) { return sqrt(dot(a,a)) ; }

int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1} ;
pt p[5] ;

inline DB cal(pt a,pt b)
{
    DB ret=INF,len=length(a-b) ;
    DB dis0=0.0 ; for(int i=0;i<4;i++) dis0+=length(p[i]-b) ;
    for(int i=0;i<4;i++) for(int j=i+1;j<4;j++)
    {
        DB val=len ;
        val+=length(p[i]-a)+length(p[j]-a) ;
        val+=dis0-length(p[i]-b)-length(p[j]-b) ;
        ret=min(ret,val) ;
    }
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        pt p1=(pt){0.0,0.0},p2=(pt){0.0,0.0} ;
        for(int i=0;i<4;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y) ,
            p1.x+=p[i].x , p1.y+=p[i].y ;

        p2.x=p1.x=(p1.x/4.0) ; p2.y=p1.y=(p1.y/4.0) ;
        DB len=1e1 , nowval=cal(p1,p2) ;

        while(len>1e-6)
        {
            while(1)
            {
                pt np1,np2 ; bool found=0 ;
                for(int i=0;i<8;i++) for(int j=0;j<8;j++)
                {
                    pt newp1=(pt) { p1.x+dx[i]*len , p1.y+dy[i]*len } ;
                    pt newp2=(pt) { p2.x+dx[j]*len , p2.y+dy[j]*len } ;
                    DB tmp=cal(newp1,newp2) ;
                    if(tmp<nowval)
                        nowval=tmp , found=1 , np1=newp1 , np2=newp2 ;
                }
                if(found) p1=np1 , p2=np2 ;
                else { len*=0.9 ; break ; }
            }
        }
        printf("%.10f\n",2*nowval) ;
    }
}
