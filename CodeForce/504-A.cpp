#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<17 ;
int deg[maxn],val[maxn] ;
queue<int> q ;
struct P{int x,y ;};
vector<P> ans ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&deg[i],&val[i]) ;
        if(deg[i]==1) q.push(i) ;
    }

    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        if(deg[u]==0) continue ;
        ans.push_back((P){u,val[u]}) ;
        val[val[u]] ^= u ;
        if((--deg[val[u]])==1) q.push(val[u]) ;
    }

    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].x,ans[i].y) ;
}
