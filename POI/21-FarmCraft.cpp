#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

struct P
{
     int id,val ;
     bool operator < (const P &rhs) const
     {
          return val>rhs.val ;
     }
} tmp[maxn] ;

vector<int> v[maxn] ;
int t[maxn],sz[maxn],dp[maxn] ;

void dfs(int x,int f)
{
     sz[x]=1 ;
     if(v[x].size()==1 && x!=1) { dp[x]=t[x] ; return ; }
     for(int i=0;i<v[x].size();i++) if(v[x][i]!=f)
          dfs(v[x][i],x) , sz[x]+=sz[v[x][i]] ;
     int cnt=0 ;
     for(int i=0;i<v[x].size();i++) if(v[x][i]!=f)
          tmp[cnt++]=(P){v[x][i],dp[v[x][i]]-2*sz[v[x][i]]} ;
     sort(tmp,tmp+cnt) ;

     int ret= (x==1 ? 2*(sz[x]-1)+t[x] : t[x]) ;
     for(int i=0 , sum=0;i<cnt;i++)
     {
          ret=max(ret,sum+1+dp[tmp[i].id]) ;
          sum+=2*sz[tmp[i].id] ;
     }
     dp[x]=ret ;
}

main()
{
     int n ; scanf("%d",&n) ;
     for(int i=1;i<=n;i++) scanf("%d",&t[i]) ;
     for(int i=1;i<n;i++)
     {
          int x,y ; scanf("%d%d",&x,&y) ;
          v[x].push_back(y) ;
          v[y].push_back(x) ;
     }
     dfs(1,1) ;
     printf("%d\n",dp[1]) ;
}
