#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct {int id,w ;} P ;
vector<P> v[200] ;
queue<int> q ;
int ans[200] ;
bool inqueue[200] ;
main()
{
    int n,m,Q,tc=0,fir=1 ;
    while(scanf("%d%d%d",&n,&m,&Q)==3 && n+m+Q)
    {
        if(fir==1) fir=0 ;
        else printf("\n");
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=m;i++)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w);
            v[a].push_back((P){b,w}) ;
            v[b].push_back((P){a,w}) ;
        }
        printf("Case #%d\n",++tc) ;
        while(Q--)
        {
            int st,ed ;
            for(int i=1;i<=n;i++) ans[i]=2100000000 ;
            for(int i=1;i<=n;i++) inqueue[i]=0 ;
            scanf("%d%d",&st,&ed) ;
            while(!q.empty()) q.pop() ;
            q.push(st) ; ans[st]=0 ; inqueue[st]=1 ;
            while(!q.empty())
            {
                int x=q.front() ; q.pop() ; inqueue[x]=0 ;
                for(int i=0;i<v[x].size();i++)
                {
                    int y=v[x][i].w ;
                    if(max(ans[x],y) < ans[v[x][i].id])
                    {
                        ans[v[x][i].id]=max(ans[x],y) ;
                        if(!inqueue[v[x][i].id])
                            q.push(v[x][i].id) ;
                    }
                }
            }
            if(ans[ed]==2100000000)printf("no path\n") ;
            else printf("%d\n",ans[ed]) ;
        }
    }
}
