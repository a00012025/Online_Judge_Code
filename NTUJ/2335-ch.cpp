#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=200 ;

struct pt{DB x,y;};
pt operator - (const pt &a,const pt &b){return (pt){a.x-b.x,a.y-b.y};}
DB cross(const pt &a,const pt &b){return a.x*b.y-a.y*b.x;}
DB cross(const pt &a,const pt &b,const pt &c){return cross(b-a,c-a);}
DB area(const pt &a,const pt &b,const pt &c)
{
    return fabs(cross(a,b,c)/2) ;
}

pt p[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        DB ans=0 ;
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y) ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++) ans+=area(p[i],p[j],p[k]) ;
        printf("%.10f\n",ans/n/(n-1)/(n-2)*6) ;
    }
}
