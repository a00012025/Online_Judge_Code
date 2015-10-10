#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000101] ;
bool vis[1000101] ;
main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=n;i++)
        {
            int a ;
            scanf("%d",&a) ;
            if(!vis[a]) {vis[a]=1 ; v[a].clear() ;}
            v[a].push_back(i) ;
        }
        while(k--)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            if(!vis[b]) printf("0\n") ;
            else if(a>v[b].size()) printf("0\n") ;
            else printf("%d\n",v[b][a-1]) ;
        }
    }
}
