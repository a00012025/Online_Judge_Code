#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int t,topo[100001],c[100001] ;
vector<int> v[100001] ;
bool dfs(int n)
{
    c[n]=-1 ;
    for(int i=0;i<v[n].size();i++)
        if(c[v[n][i]]==-1) return false ;
        else if(!c[v[n][i]] && !dfs(v[n][i])) return false ;
    topo[--t]=n ; c[n]=1 ;
    return true ;
}

main()
{
    int T;
    int m,n ;
    while(scanf("%d %d",&n,&m))
    {
        if(!m && !n) break ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            v[a].push_back(b) ;
        }
        memset(c,0,sizeof(c)) ;
        bool no=0 ; t=n+1 ;
        for(int i=n;i>0;i--) if(!c[i])
            if(!dfs(i)) {no=1 ; break ;}
        if(!no)
        {
            printf("%d",topo[1]) ;
            for(int i=2;i<=n;i++) printf(" %d",topo[i]) ;
        }
        printf("\n");
    }
}
