#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
set<int> s[1001] ;
int comp,vis[1001] ;
void dfs(int n)
{
        //printf("%d,%d\n",n,comp) ;
    set<int>::iterator it ;
    vis[n]=comp ;
    for(it=s[n].begin();it!=s[n].end();it++)
    {
        if(vis[*it]) continue ;
        dfs(*it) ;
    }
}

main()
{
    int n,m,k ;
    scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++) s[i].clear() ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        if(j==i) continue ;
        s[i].insert(j) ;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        s[a].erase(b) ;
        s[b].erase(a) ;
    }
    comp=0 ;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue ;
        comp++ ;
        dfs(i) ;
    }
    if(comp>k) {printf("-1\n") ; return 0 ;}
    bool no=0 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        if(i==j) continue ;
        if(vis[i]==vis[j] && s[i].count(j)==0) no=1 ;
    }
    if(no==1) {printf("-1\n") ; return 0 ;}
    for(int i=1;i<=n;i++)
    {
        if(i-1) printf(" ") ;
        printf("%d",vis[i]);
    }
    printf("\n") ;
}
