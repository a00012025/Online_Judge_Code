#include<bits/stdc++.h>
#define LL long long
using namespace std;

int cost[2001],w[2001],pos[2001] ;
queue<int> q ;
bool now[2001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&w[i]) ;
    int num=0 ; LL ans=0LL ;
    for(int z=1;z<=2*m;z++)
    {
        int x ; scanf("%d",&x) ;
        if(x>0)
        {
            if(num==n) {q.push(x) ; continue ;}
            int id ; for(id=1;now[id];id++) ;
            now[id]=1 ; num++ ;
            pos[x]=id ;
            ans+=((LL)w[x])*((LL)cost[id]) ;
        }
        else
        {
            x=-x ;
            now[pos[x]]=0 ; num-- ;
            if(!q.empty())
            {
                now[pos[x]]=1 ; num++ ;
                ans+=((LL)w[q.front()])*((LL)cost[pos[x]]) ;
                pos[q.front()]=pos[x] ;
                q.pop() ;
            }
        }
    }
    printf("%I64d\n",ans) ;
}
