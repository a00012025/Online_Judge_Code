#include<stdio.h>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
vector<int> v[211001] ;
stack<int> s ;
int fish[211001],ans[211001] ;
bool vis[211001] ;

int dfs(int n)
{
    vis[n]=1 ;
    if(v[n].size()==1 && n)
    {
        if(fish[n]==-1) return 0 ;
        s.push(fish[n]) ; return 1 ;
    }
    int num=0 ;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]) continue ;
        num+=dfs(v[n][i]) ;
    }
    if(fish[n]==-1) return num ;
    for(int i=1;i<=num;i++)
    {
        int tp=s.top() ; s.pop() ;
        ans[tp]=n ;
    }
    s.push(fish[n]) ; return s.size() ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        memset(vis,0,sizeof(vis)) ;
        memset(ans,0,sizeof(ans)) ;
        for(int i=0;i<=n+1;i++) {v[i].clear(); fish[i]=-1 ;}
        for(int i=1;i<n;i++)
        {
            int a;
            scanf("%d",&a) ;
            v[i].push_back(a) ; v[a].push_back(i) ;
        }
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a) ;
            fish[a]=i ;
        }
        while(!s.empty()) s.pop() ;
        int ddd=dfs(0) ;
        int ANS=0 ;
        for(int i=1;i<=m;i++) ANS ^= (ans[i]+i) ;
        //for(int i=1;i<=m;i++) ANS ^= (ans[i]==0 ? 0 : ans[i]+i) ;
        printf("%d\n",ANS) ;
        //for(int i=1;i<=m;i++) printf("%d,",ans[i]) ;
        //printf("\n") ;
    }
}
