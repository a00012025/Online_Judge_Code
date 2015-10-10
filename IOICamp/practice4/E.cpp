#include<bits/stdc++.h>
#define DB long double
#define INF 1e8
using namespace std;
const int maxn=1000+10 ;
const DB eps=1e-8 ;

struct pt
{
    DB x,y ;
    pt(const DB &xx,const DB &yy){ x=xx , y=yy ; }
    pt(){} ;
};
pt operator + (const pt &a,const pt &b) { return pt(a.x+b.x,a.y+b.y) ; }
pt operator - (const pt &a,const pt &b) { return pt(a.x-b.x,a.y-b.y) ; }
DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB length(const pt &a) { return sqrtl(dot(a,a)) ; }

pt a[maxn] ;
int n ;
DB cal(const pt &p)
{
    DB ret=0.0 ;
    for(int i=1;i<=n;i++) ret+=length(p-a[i]) ;
    return ret ;
}

int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1} ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        DB nowx=0.0 , nowy=0.0 ;
        for(int i=1;i<=n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            a[i].x=x , a[i].y=y ;
            nowx+=a[i].x , nowy+=a[i].y ;
        }
        nowx/=n , nowy/=n ;
        DB ans=cal((pt){nowx,nowy}) , len=1e3 ;
        while(len>eps)
        {
            while(1)
            {
                bool found=0 ;
                DB newx,newy ;
                for(int i=0;i<8;i++)
                {
                    DB tmp=cal((pt){nowx+dx[i]*len,nowy+dy[i]*len}) ;
                    if(tmp<ans)
                        ans=tmp , found=1 ,
                        newx=nowx+dx[i]*len , newy=nowy+dy[i]*len ;
                }
                if(!found) break ;
                nowx=newx , nowy=newy ;
            }
            len*=0.5 ;
        }
        double ans2=2*ans ;
        printf("%.10f\n",ans2) ;
    }
}
