#include<stdio.h>
#include<algorithm>
using namespace std;
struct P {int st,ed,w ;};
bool cmp(P x,P y)
{
    return x.w < y.w ;
}
P edge[25001] ;
int fa[1001] ;
int getfa(int n)
{
    return n==fa[n] ? n : fa[n]=getfa(fa[n]) ;
}
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=0;i<=n;i++) fa[i]=i ;
        for(int i=0;i<m;i++)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w) ;
            edge[i]=(P){a,b,w} ;
        }
        sort(edge,edge+m,cmp) ;
        int ans[250001] , cnt=0 ;
        for(int i=0;i<m;i++)
        {
            P u=edge[i] ;
            if(getfa(u.st)==getfa(u.ed)) ans[++cnt]=i ;
            else fa[getfa(u.st)]=getfa(u.ed) ;
        }
        if(cnt==0) printf("forest\n") ;
        else for(int i=1;i<=cnt;i++)
            printf("%d%c",edge[ans[i]].w,i==cnt?'\n':' ');
    }
}
