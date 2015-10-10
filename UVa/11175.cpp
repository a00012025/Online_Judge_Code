#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000] ;
bool G[611][611] ;
int n,m ;

bool solve()
{
    for(int i=0;i<n;i++)
    for(int j=0;j<v[i].size();j++)
    for(int k=0;k<v[i].size();k++) if(j!=k)
    {
        int nv=v[i][k] ;
        for(int l=0;l<v[nv].size();l++) if(!G[v[nv][l]][v[i][j]]) return 0;
    }
    return 1;
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<=2*n;i++) v[i].clear() ;
        memset(G,0,sizeof(G)) ;
        while(m--)
        {
            int a,b ; scanf("%d%d",&a,&b) ;
            if(!G[a+n][b])
            {
                v[a+n].push_back(b) ;
                v[b].push_back(a+n) ;
            }
            G[a+n][b]=G[b][a+n]=1 ;
        }
        if(solve()) printf("Case #%d: Yes",++tc) ;
        else printf("Case #%d: No",++tc) ;
        printf("\n");
    }
}
