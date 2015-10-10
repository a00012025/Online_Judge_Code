#include<stdio.h>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
vector<int> v[211001] ;
stack<int> s ;
int fish[211001],ans[211001],tem[211001] ;

int dfs(int n)
{
    if(v[n].size()==0 && n)
    {
        if(fish[n]==-1) return 0 ;
        s.push(fish[n]) ; return 1 ;
    }
    int num=0 ;
    for(int i=0;i<v[n].size();i++)
    {
        num+=dfs(v[n][i]) ;
    }
    if(fish[n]==-1) return num ;

    int cnt=0 ;
    for(int i=1;i<=num;i++)
    {
        int tp=s.top() ; s.pop() ;
        if(tp>fish[n]) ans[tp]=n ;
        else tem[++cnt]=tp ;
    }
    for(int i=cnt;i>=1;i--) s.push(tem[i]) ;
    s.push(fish[n]) ; return cnt+1 ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        memset(ans,0,sizeof(ans)) ;
        for(int i=0;i<=n+1;i++) {v[i].clear(); fish[i]=-1 ;}
        for(int i=1;i<n;i++)
        {
            int a;
            scanf("%d",&a) ;
            v[a].push_back(i) ;
        }
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a) ;
            fish[a]=i ;
        }
        while(!s.empty()) s.pop() ;
        dfs(0) ;
        int ANS=0 ;
        for(int i=1;i<=m;i++) ANS ^= (ans[i]+i) ;
        //for(int i=1;i<=m;i++) ANS ^= (ans[i]==0 ? 0 : ans[i]+i) ;
        printf("%d\n",ANS) ;
        //for(int i=1;i<=m;i++) printf("%d,",ans[i]) ;
        //printf("\n") ;
    }
}
