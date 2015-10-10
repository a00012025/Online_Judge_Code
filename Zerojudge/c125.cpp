#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[201] ;
int x[201],y[201] ;
bool vis[201] ;

int dis(int a,int b)
{
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]) ;
}

bool dfs(int n)
{
    if(n==2) return true ;
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]) continue ;
        if(dfs(v[n][i])) return true ;
    }
    return false ;
}

main()
{
    int tc=0,n ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        double l=0 , r=2000 ;
        while(r-l>0.000001)
        {
            for(int i=0;i<=n;i++) v[i].clear() ;
            memset(vis,0,sizeof(vis)) ;
            double mid=(r+l)/2 ;
            for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            {
                if(dis(i,j)<=mid*mid)
                {
                    v[i].push_back(j) ;
                    v[j].push_back(i) ;
                }
            }
            if(dfs(1)) r=mid ;
            else l=mid ;
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n",++tc,r) ;
    }
}
