#include<bits/stdc++.h>
#define CASE_T int __T ; scanf("%d",&__T) ; while(__T--)
#define DB long double
using namespace std;
const int maxn=100000+10 ;
struct pt{DB x,y ;};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB length(const pt &a) { return sqrtl(dot(a,a)) ; }
DB angle(const pt &a,const pt &b) { return acos(dot(a,b)/length(a)/length(b)) ; }

pt a[maxn] ;
main()
{
    DB pi=2*acos((DB)0.0) ;
    CASE_T
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        for(int i=1;i<=k;i++)
        {
            double x,y ; scanf("%lf%lf",&x,&y) ;
            a[i]=(pt){x,y} ;
        }
        if(k<3 && n>=4) { printf("-1\n") ; continue ; }
        else if(n==3 && k<2) { printf("-1\n") ; continue ; }
        else if(n==3)
        {
            DB ans= dot(a[2]-a[1],a[2]-a[1])*sqrtl(3.0)/4.0 ;
            double ans2=ans ;
            printf("%.10f\n",ans2) ; continue ;
        }
        DB R= length(a[2]-a[3])/sin(angle(a[2]-a[1],a[3]-a[1])) ; if(R<0) R=-R ;
        R/=2.0 ;

        DB ans= R*R*0.5*sin(2*pi/n) ; ans*=n ;
        double ans2=ans ;
        printf("%.10f\n",ans2) ;
    }
}
