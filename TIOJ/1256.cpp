#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn] ;
bool ans[maxn] ;

int lev[maxn] ;
int dfs(int x,int f,int dep)
{
    int low,son=0 ;
    low=lev[x]=dep ;
    for(auto i : v[x]) if(i!=f)
    {
        if(lev[i]!=-1) { low=min(low,lev[i]) ; continue ; }
        son++ ;
        int tmp=dfs(i,x,dep+1) ;
        low=min(low,tmp) ;
        if(tmp>=lev[x] && x!=1) ans[x]=1 ;
    }
    if(x==1 && son>1) ans[x]=1 ;
    return low ;
}

main()
{
    int n,m,tc=0 ;
    while(scanf("%d%d",&n,&m)==2&&n+m)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        memset(ans,0,sizeof(ans)) ;
        memset(lev,-1,sizeof(lev)) ;
        dfs(1,1,0) ;

        int Ans=count(ans+1,ans+n+1,true) ;
        printf("Case #%d:%d",++tc,Ans) ;
        for(int i=1;i<=n;i++) if(ans[i]) printf(" %d",i) ;
        if(!Ans) printf(" 0") ;
        printf("\n") ;
    }
}
