#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000] ;
double x[101],y[101],r[101] ;
int num ;
bool vis[101] ;

int db_comp(double a,double b)
{
    double e=0.000000001 ;
    if(a-b>e) return 1;
    else if(b-a>e) return -1 ;
    else return 0 ;
}

void dfs(int n)
{
    vis[n]=1 ; num++ ;
    for(int i=0;i<v[n].size();i++)
        if(!vis[v[n][i]]) dfs(v[n][i]) ;
}

main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n<0) break ;
        for(int i=1;i<=n;i++) scanf("%lf %lf %lf",&x[i],&y[i],&r[i]) ;
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            double dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) ;
            double d1=(r[i]+r[j])*(r[i]+r[j]) ;
            double d2=(r[i]-r[j])*(r[i]-r[j]) ;
            if(db_comp(d1,dis)==1 && db_comp(d2,dis)==-1)
            {
                v[i].push_back(j) ;
                v[j].push_back(i) ;
                //printf("%d,%d\n",i,j) ;
            }
        }
        memset(vis,0,sizeof(vis)) ;
        int ans=0 ;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue ;
            num=0 ;
            dfs(i) ;
            if(num>ans) ans=num ;
        }
        if(ans==1)printf("The largest component contains 1 ring.\n") ;
        else printf("The largest component contains %d rings.\n",ans) ;
    }
}
