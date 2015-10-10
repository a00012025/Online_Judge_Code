#include<stdio.h>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;
vector<int> v[100001] ;
int vis[100001],yes ;

void dfs(int n)
{
     if(v[n].size()==0) return ;
     if(yes==0) return ;
     for(int i=0;i<v[n].size();i++)
     {
        if(yes==0) return ;
        if(vis[v[n][i]]==vis[n]) {yes=0 ; break ;}
        if(vis[v[n][i]]==0)
            {
                if(vis[n]==1) vis[v[n][i]]=2 ;
                if(vis[n]==2) vis[v[n][i]]=1 ;
                dfs(v[n][i]) ;
            }
     }
}
main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && n && m)
    {
        for(int i=0;i<n;i++) v[i].clear() ;
        memset(vis,0,sizeof(vis)) ;
        yes=1 ;
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        for(int j=0;j<n;j++)
        {
            if(vis[j]>0) continue ;
            vis[j]=1 ;
            dfs(j) ;
        }
        if(yes==1) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n") ;
     }
}

