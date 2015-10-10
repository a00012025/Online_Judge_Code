#include<stdio.h>
#include<algorithm>
#include<math.h>
#define DB double
using namespace std;
struct P {int st,ed ; double w ;};
bool cmp(P x,P y)
{
    return x.w < y.w ;
}
P edge[250001] ;
int fa[501],x[501],y[501] ;
int getfa(int n)
{
    return n==fa[n] ? n : fa[n]=getfa(fa[n]) ;
}
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int s,n,cnt=0 ;
        scanf("%d%d",&s,&n) ;
        for(int i=0;i<n;i++) fa[i]=i ;
        for(int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]) ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        {
            double dis=((DB)x[i]-x[j])*((DB)x[i]-x[j])+((DB)y[i]-y[j])*((DB)y[i]-y[j]) ;
            dis=sqrt(dis) ;
            edge[cnt++]=(P){i,j,dis} ;
        }
        sort(edge,edge+cnt,cmp) ;
        int num=0 ; double ans ;
        for(int i=0;i<cnt;i++)
        {
            P u=edge[i] ;
            if(getfa(u.st)!=getfa(u.ed))
            {
                fa[getfa(u.st)]=getfa(u.ed) ;
                if(++num==n-s) {ans=u.w ; break ;}
            }
        }
        printf("%.2lf\n",ans) ;
    }
}
