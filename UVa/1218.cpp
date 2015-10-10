#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int d[10001][3],fa[10001] ;
vector<int> v[10001] ;

void dfs(int n)
{
    d[n][0]=1 ; d[n][1]=0 ;
    for(int i=0;i<v[n].size();i++) if(v[n][i]!=fa[n])
        { fa[v[n][i]]=n ; dfs(v[n][i]) ; }
    int M=-200000 ;
    for(int i=0;i<v[n].size();i++) if(v[n][i]!=fa[n])
    {
        int t=v[n][i] ;
        d[n][0]+=min(d[t][0],d[t][1]) ;
        d[n][1]+=d[t][2] ;
        M=max(M,d[t][2]-d[t][0]) ;
    }
    d[n][2]=d[n][1]-M ;
    //printf("%d : %d , %d , %d\n",n,d[n][0],d[n][1],d[n][2]) ;
}

main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<n;i++)
        {
            int a,b ; scanf("%d%d",&a,&b) ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        fa[1]=1 ; dfs(1) ;
        printf("%d\n",min(d[1][0],d[1][2])) ;
        int k ; scanf("%d",&k) ;
        if(k==-1) break ;
    }
}
