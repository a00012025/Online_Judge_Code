#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int vis[maxn],st[maxn] ;
vector<LL> ans ;
main()
{
     int n ; scanf("%d",&n) ;
     while(n--)
     {
          int x ; scanf("%d",&x) ;
          vis[x]=1 ;
     }
     scanf("%d",&n) ;
     LL cnt=0 ;
     while(n--)
     {
          int x ; scanf("%d",&x) ;
          int i=st[x]+x ;
          for(int j=1;j<=x && i<maxn;i+=x)
          {
               if(vis[i]==2) continue ;
               if(vis[i]==1) ans.push_back(cnt+j) ;
               vis[i]=2 ; j++ ;
          }
          st[x]=i-x ;
          cnt+=x ;
     }
     printf("%d\n",ans.size()) ;
     for(int i=0;i<ans.size();i++) printf("%lld\n",ans[i]) ;
}
