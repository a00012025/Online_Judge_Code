#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
queue<int> q;
int ans[2000],wei[2000] ;
bool vis[2000] ;
main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=0;i<(1<<n);i++) scanf("%d",&wei[i]) ;
        while(!q.empty()) q.pop() ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<(1<<n);i++) ans[i]=0 ;
        q.push(0) ; vis[0]=1 ; ans[0]=wei[0] ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            for(int i=0;i<n;i++) if(x & (1<<i))
                ans[x]=max(ans[x],ans[x-(1<<i)]+wei[x]) ;
            for(int i=0;i<n;i++)
                if((x & (1<<i))==0 && vis[x+(1<<i)]==0)
                {
                    q.push(x+(1<<i)) ;
                    vis[x+(1<<i)]=1 ;
                }
        }
        printf("%d\n",ans[(1<<n)-1]) ;
    }
}
