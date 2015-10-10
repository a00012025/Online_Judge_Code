#include<stdio.h>
#include<vector>
#include<queue>
#define INF 2000000000
using namespace std;
typedef struct {int id,w ;} P ;
vector<P> v[20010] ;
queue<int> q ;
int ans[20010];
bool inqueue[20010] ;
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,st,ed ;
        scanf("%d%d%d%d",&n,&m,&st,&ed);
        for(int i=0;i<=n;i++) v[i].clear() ;
        while(!q.empty()) q.pop() ;
        for(int i=1;i<=m;i++)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w);
            v[a].push_back((P){b,w}) ;
            v[b].push_back((P){a,w}) ;
        }
        for(int i=0;i<=n;i++) ans[i]=INF ;
        q.push(st) ; ans[st]=0 ;

        while(!q.empty())
        {
            int a=q.front() ; q.pop() ;
            for(int i=0;i<v[a].size();i++)
            {
                if(ans[a]+v[a][i].w < ans[v[a][i].id])
                {
                    ans[v[a][i].id]=ans[a]+v[a][i].w ;
                    if(!inqueue[v[a][i].id])
                        q.push(v[a][i].id) ;
                    inqueue[v[a][i].id]=true ;
                }
            }
        }
        if(ans[ed]==INF) printf("Case #%d: unreachable\n",++tc) ;
        else printf("Case #%d: %d\n",++tc,ans[ed]) ;
    }
}
