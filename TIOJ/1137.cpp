#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

vector<int> v[maxn] ;

bool ans[maxn] ;
int lev[maxn],low[maxn],cnt ;

void dfs(int x,int l,int fa)
{
    int son=0 ;
    lev[x]=low[x]=l ;
    bool found=0 ;
    for(auto i : v[x]) if(i!=fa)
    {
        if(lev[i]>=0) low[x]=min(low[x],lev[i]) ;
        else
        {
            son++ ; dfs(i,l+1,x) ;
            low[x]=min(low[x],low[i]) ;
            if(low[i]>=lev[x]) found=1 ;
        }
    }
    if((fa<0 && son>1) || (fa>=0 && found)) ans[x]=1 , cnt++ ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        memset(ans,0,sizeof(ans)) ;
        memset(lev,-1,sizeof(lev)) ;
        cnt=0 ;
        dfs(1,0,-1) ;

        printf("%d\n",cnt) ;
        if(!cnt) printf("0") ;
        else
        {
            bool fir=1 ;
            for(int i=1;i<=n;i++) if(ans[i])
            {
                if(fir) fir=0 ;
                else printf(" ") ;
                printf("%d",i) ;
            }
        }
        printf("\n") ;
    }
}
