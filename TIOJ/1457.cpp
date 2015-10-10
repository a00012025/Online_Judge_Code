#include<bits/stdc++.h>
#define DB double
using namespace std;
vector<int> v[2000] ;
int G[505][505] ;
int tc,n,m,vis[2000] ;

int getint()
{
    char c=getchar() ; int ret=0 ;
    while(c<'0'||c>'9') c=getchar() ;
    while(1)
    {
        ret=ret*10+c-'0' ;
        c=getchar() ;
        if(c<'0'||c>'9') return ret ;
    }
}

bool solve()
{
    while(m--)
    {
        int a=getint() ;
        int b=getint() ;
        if(G[a][b]!=tc+1) v[b].push_back(a+n) ;
        G[a][b]=tc+1 ;
    }

    for(int i=n;i<=2*n;i++) vis[i]=-1 ;
    for(int i=0;i<n;i++) if(!v[i].empty())
    {
        if(vis[v[i][0]]==-1)
            for(int j=0;j<v[i].size();j++)
            {
                if(vis[v[i][j]]!=-1) return 0;
                vis[v[i][j]]=i ;
            }
        else
        {
            int gp=vis[v[i][0]] ;
            if(v[gp].size()!=v[i].size()) return 0;
            for(int j=0;j<v[i].size();j++)
                if(vis[v[i][j]]!=gp) return 0;
        }
    }
    return 1;
}

main()
{
    int T=getint() ; tc=0;
    while(T--)
    {
        n=getint() ; m=getint() ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        if(solve()) printf("Case #%d: Yes",++tc) ;
        else printf("Case #%d: No",++tc) ;
        printf("\n");
    }
}
