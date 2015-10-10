#include<stdio.h>
#include<algorithm>
using namespace std;
struct P{int st,ed,w ;};
bool cmp(P x,P y)
{
    return x.w < y.w ;
}
P edge[210001] ;
int fa[210001] ;
int getfa(int n)
{
    return fa[n]==n ? n : fa[n]=getfa(fa[n]) ;
}
main()
{
    int n,m,sum ;
    while(scanf("%d %d",&n,&m)==2 && m+n)
    {
        sum=0 ;
        for(int i=0;i<n;i++) fa[i]=i ;
        for(int i=0;i<m;i++)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w) ;
            edge[i]=(P){a,b,w} ;
            sum+=w ;
        }
        sort(edge,edge+m,cmp) ;
        int ans=0 , cnt=0 ;
        for(int i=0;i<m;i++)
        {
            P u=edge[i] ;
            if(getfa(u.st)!=getfa(u.ed))
                {ans+=u.w ; fa[getfa(u.st)]=getfa(u.ed) ;}
            if(cnt==n-1) break ;
        }
        //printf("%d\n",ans) ;
        printf("%d\n",sum-ans) ;
    }
}
