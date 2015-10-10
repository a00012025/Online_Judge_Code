#include<bits/stdc++.h>
#define INF 2000000000
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int mul(int x,int y)
{
     if(INF/y < x) return INF ;
     return x*y ;
}

vector<int> v[maxn] ;
int g[maxn] ;

int dp1[maxn],dp2[maxn] ;

void dfs(int x,int f)
{
     if(v[x].size()==1)
     {
          dp1[x]=dp1[f] ;
          dp2[x]=dp2[f] ;
          return ;
     }
     int d=v[x].size() ;
     dp1[x]=mul(d-1,dp1[f]) ;
     dp2[x]=mul(d-1,dp2[f]+1)-1 ;
     for(int i=0;i<v[x].size();i++) if(v[x][i]!=f)
          dfs(v[x][i],x) ;
}

int m ;
int cal(int x,int y)
{
     int id1=lower_bound(g+1,g+m+1,x)-g ;
     int id2=upper_bound(g+1,g+m+1,y)-g ;
     return id2-id1 ;
}

main()
{
     int n,k ; scanf("%d%d%d",&n,&m,&k) ;
     for(int i=1;i<=m;i++) scanf("%d",&g[i]) ;
     sort(g+1,g+m+1) ;

     int st1,st2 ;
     for(int i=1;i<n;i++)
     {
          int x,y ; scanf("%d%d",&x,&y) ;
          if(i==1) st1=x , st2=y ;
          else v[x].push_back(y) , v[y].push_back(x) ;
     }

     if(v[st1].empty()) dp1[st1]=dp2[st1]=k ;
     else dp1[st1]=mul(k,v[st1].size()) ,
          dp2[st1]=mul(k+1,v[st1].size())-1 ;
     if(v[st2].empty()) dp1[st2]=dp2[st2]=k ;
     else dp1[st2]=mul(k,v[st2].size()) ,
          dp2[st2]=mul(k+1,v[st2].size())-1 ;

     for(int i=0;i<v[st1].size();i++) dfs(v[st1][i],st1) ;
     for(int i=0;i<v[st2].size();i++) dfs(v[st2][i],st2) ;

     LL ans=0LL ;
     v[st1].push_back(st2) ; v[st2].push_back(st1) ;
     for(int i=1;i<=n;i++) if(v[i].size()==1)
          ans+=cal(dp1[i],dp2[i]) ;
     printf("%lld\n",ans*k) ;
}
