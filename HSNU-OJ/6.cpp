#include<stdio.h>
#include<algorithm>
#define INF 1000000000.0
using namespace std;
struct edge{int st,ed ; double w ;}a[100001];
bool cmp(edge x,edge y)
{
    return x.w>y.w ;
}

int n,m,fa[100001] ;
int getfa(int n)
{
    return n==fa[n] ? fa[n] : fa[n]=getfa(fa[n]) ;
}

double kruskal()
{
    sort(a,a+m,cmp) ;
    for(int i=0;i<n;i++) fa[i]=i ;
    double ret=INF ;
    for(int i=0;i<m;i++)
    {
        int x=getfa(a[i].st) , y=getfa(a[i].ed) ;
        if(x!=y)
        {
            fa[x]=y ;
            ret=min(ret,a[i].w) ;
        }
    }
    for(int i=0;i<n;i++) if(getfa(0)!=getfa(i)) return -1 ;
    return ret ;
}

main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;i++) scanf("%d%d%lf",&a[i].st,&a[i].ed,&a[i].w) ;
        double ans=kruskal() ;
        if(ans==-1) printf("The empire of Arcturus is ending.\n") ;
        else if(ans==INF) printf("No way.\n") ;
        else printf("%.4lf\n",ans) ;
    }
}

