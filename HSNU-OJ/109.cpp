#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n,m ;
vector<int> v[20] ;
int nowx[20],nowy[20],ans ;

bool inside(int x)
{
    if(1<=x && x<=m) return 0 ;
    if((x%m==1) || (x%m==0)) return 0 ;
    if(((x-1)/m)+1 == n) return 0 ;
    return 1 ;
}

void dfs(int num,int edge,int cost)
{
    if(num==m*n+1) { ans=min(ans,cost) ; return ; }
    if(cost+edge>=ans) return ;
    int nowi=((num-1)/m)+1 , nowj=((num-1)%m)+1 ;
    for(int i=m*n;i>=1;i--) if(nowx[i]==-1)
    {
        if(v[i].size()==1 && inside(num)) continue ;
        nowx[i]=nowi , nowy[i]=nowj ;
        int add=0,adde=0 ;
        for(int j=0;j<v[i].size();j++) if(nowx[v[i][j]]!=-1)
            adde++ ,
            add+=(nowx[i]-nowx[v[i][j]])*(nowx[i]-nowx[v[i][j]]) +
                    (nowy[i]-nowy[v[i][j]])*(nowy[i]-nowy[v[i][j]]) ;
        dfs(num+1,edge-adde,cost+add) ;
        nowx[i]=nowy[i]=-1 ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=1;i<=m*n;i++) v[i].clear() ;
        for(int i=1;i<m*n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ; v[y].push_back(x) ;
        }
        for(int i=1;i<=m*n;i++) nowx[i]=nowy[i]=-1 ;
        ans=INF ;
        dfs(1,n*m-1,0) ;
        printf("%d\n",ans) ;
    }
}
