#include<bits/stdc++.h>
using namespace std;
const int maxn=3000+10 ;

vector<int> v[maxn] ;
bool vis[maxn] ;
void BFS(int st,int *d)
{
    queue<int> q ;
    memset(vis,0,sizeof(vis)) ;
    q.push(st) ; vis[st]=1 ;
    d[st]=0 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        for(auto i : v[u]) if(!vis[i])
            d[i]=d[u]+1 , vis[i]=1 , q.push(i) ;
    }
}

int n,d[maxn][maxn],t1,t2 ;
int solve(int s1,int e1,int s2,int e2)
{
    if(s1==s2 && e1==e2) return d[s1][e1] ;
    int ans=d[s1][e1]+d[s2][e2] ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(d[s1][i]+d[i][j]+d[j][e1]<=t1 &&
           d[s2][i]+d[i][j]+d[j][e2]<=t2)
           ans=min(ans,d[s1][i]+d[i][j]+d[j][e1]+d[s2][i]+d[j][e2]) ;
    return ans ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    for(int i=1;i<=n;i++) BFS(i,d[i]) ;
    int s1,e1 , s2,e2 ;
    scanf("%d%d%d%d%d%d",&s1,&e1,&t1,&s2,&e2,&t2) ;
    if(d[s1][e1]>t1 || d[s2][e2]>t2) {printf("-1\n") ; return 0;}
    printf("%d\n",m-min(solve(s1,e1,s2,e2),solve(s1,e1,e2,s2))) ;
}
