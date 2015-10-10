#include<bits/stdc++.h>
#define LL long long
using namespace std;
char G[510][510] ;
vector<int> v[510000] ;
bool vis[510000] ;
int type[510000] ;
int n,m ;
char ans[300000] ;

void dfs(int x,int tp)
{
    vis[x]=1 ; type[x]=tp ; //printf("%d\n",x) ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs(v[x][i],tp) ;
}

unsigned int get_hash(const char *S)
{
    unsigned int i, h = (LL)1315423911;
    for (i = 0; *S; S++, i++)
        h ^= ((h << 5) + (*S) + (h >> 2));
    h &= 0x7FFFFFFF;
    return h;
}

main()
{
    int T ;scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        for(int i=0;i<2*m*n+m+n;i++) v[i].clear() ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            int u=i*m+j , d=(i+1)*m+j , r=m*(n+1)+i+(i*m+j+1) , l=m*(n+1)+i+(i*m+j) ;
            if(G[i][j]=='A')
            {
                v[u].push_back(l) ;
                v[l].push_back(u) ;
                v[r].push_back(d) ;
                v[d].push_back(r) ;
            }
            else
            {
                v[u].push_back(r) ;
                v[r].push_back(u) ;
                v[l].push_back(d) ;
                v[d].push_back(l) ;
            }
        }
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<m;i++) if(!vis[i]) dfs(i,0) ;
        for(int i=m*(n+1);i<=2*m*n+n-1;i+=m+1) if(!vis[i]) dfs(i,0) ;
        for(int i=m*n+2*m;i<2*m*n+m+n;i+=m+1) if(!vis[i]) dfs(i,0) ;
        for(int i=n*m;i<m*(n+1);i++) if(!vis[i]) dfs(i,0) ;
        int cnt=0 ;
        for(int i=0;i<2*m*n+m+n;i++) if(!vis[i])
        {
            cnt++ ; dfs(i,cnt) ;
        }
        for(int i=0;i<m*n;i++) ans[i]='.' ;
        ans[m*n]='\0' ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            if(type[i*m+j+m] && !vis[type[i*m+j+m]] && G[i][j]=='B')
            {
                vis[type[i*m+j+m]]=1 ; ans[i*m+j]='*' ;
            }
        }
        printf("%d %d\n%d\n",m+n+1,cnt,get_hash(ans)) ;
        // maxn = 2*m*n+m+n !!!!!!!
    }
}
