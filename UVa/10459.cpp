#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> v[5001] ;
int d[5001][5001],ans[5001] ;
bool vis[5001] ;

void dfs(int root,int n,int lev)
{
    d[root][n]=lev ;
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++) if(!vis[v[n][i]])
        dfs(root,v[n][i],lev+1) ;
}

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            v[i].clear() ;
            int m;
            scanf("%d",&m) ;
            while(m--)
            {
                int a;
                scanf("%d",&a) ;
                v[i].push_back(a) ;
            }
        }
        memset(ans,0,sizeof(ans)) ;
        int best,worst ;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis)) ;
            dfs(i,i,0) ;
            for(int j=1;j<=n;j++) ans[i]=max(ans[i],d[i][j]) ;
            best=min(best,ans[i]) ;
            worst=max(worst,ans[i]) ;
        }
        printf("Best Roots  :") ;
        for(int i=1;i<=n;i++) if(ans[i]==best) printf(" %d",i) ;
        printf("\nWorst Roots :") ;
        for(int i=1;i<=n;i++) if(ans[i]==worst) printf(" %d",i) ;
        printf("\n");
    }
}
