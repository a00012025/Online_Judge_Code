#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct P{int x,y;};

int fa[maxn] ;
int getfa(int x)
{
     return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

vector<P> v,ans ;
main()
{
     int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
     for(int i=1;i<=n;i++) fa[i]=i ;
     while(m--)
     {
          int x,y ; scanf("%d%d",&x,&y) ;
          if(x>k && y>k) fa[getfa(x)]=getfa(y) ;
          else v.push_back((P){x,y}) ;
     }
     for(int i=0;i<v.size();i++)
     {
          int x=getfa(v[i].x) , y=getfa(v[i].y) ;
          if(x==y) ans.push_back(v[i]) ;
          else fa[x]=y ;
     }
     printf("%d\n",ans.size()) ;
     for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].x,ans[i].y) ;
}
