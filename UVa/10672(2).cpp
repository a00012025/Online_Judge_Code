#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int val[10001],fa[10001],ans ;
vector<int> v[10001] ;

void dfs(int n)
{
    for(int i=0;i<v[n].size();i++)
    {
        dfs(v[n][i]) ;
        val[n]+= val[v[n][i]]-1 ;
        ans+= val[v[n][i]]>1 ? val[v[n][i]]-1 : 1-val[v[n][i]] ;
    }
}

main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        memset(fa,0,sizeof(fa)) ;
        for(int i=1;i<=n;i++)
        {
            int a,b,k ;
            scanf("%d%d%d",&a,&b,&k) ;
            val[a]=b ;
            while(k--)
            {
                int t;
                scanf("%d",&t) ;
                v[a].push_back(t) ;
                fa[t]=a ;
            }
        }
        int root ;
        for(root=1;fa[root];root++) ;
        ans=0 ;
        dfs(root) ;
        printf("%d\n",ans) ;
    }
}
