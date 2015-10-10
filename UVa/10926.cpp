#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[200] ;
int num,ans[200] ;
bool vis[200] ;

void dfs(int n)
{
    vis[n]=1 ;
    num++ ;
    for(int i=0;i<v[n].size();i++) if(!vis[v[n][i]]) dfs(v[n][i]) ;
}

main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int T;
            scanf("%d",&T);
            while(T--)
            {
                int a;
                scanf("%d",&a);
                v[i].push_back(a) ;
            }
        }
        for(int i=1;i<=n;i++)
        {
            num=0 ; memset(vis,0,sizeof(vis)) ;
            dfs(i) ;
            ans[i]=num ;
        }
        int ANS=0 , id ;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]>ANS) {ANS=ans[i] ; id=i ;}
        }
        printf("%d\n",id) ;
    }
}
