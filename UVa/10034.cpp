#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
double x[200],y[200],ans,key[200] ;
int n;
bool vis[200] ;

double dis(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])) ;
}

double prim()
{
    for(int i=1;i<=n;i++) key[i]=1000000000 ;
    int last=1 ; vis[1]=1 ;
    int id ; double val ;
    for(int i=2;i<=n;i++)
    {
        val=1000000000 ;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]) continue ;
            key[j]=min(key[j],dis(j,last)) ;
            if(key[j]<val) {val=key[j] ; id=j ;}
        }
        last=id ; ans+=val ;
        vis[id]=1 ;
    }
    return ans ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lf %lf",&x[i],&y[i]);
        memset(vis,0,sizeof(vis)); ans=0 ;
        printf("%.2lf\n",prim()) ;
        if(T)printf("\n");
    }
}
