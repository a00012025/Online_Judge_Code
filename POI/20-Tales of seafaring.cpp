#include<bits/stdc++.h>
#define INF 30000
using namespace std;
const int maxn=5000+5 ;

short d[maxn][2*maxn] ;
vector<int> v[maxn] ;
int n,que[2*maxn] ;
void BFS(int i,short *dis)
{
     int head=0 , tail=0 ;
     for(int i=1;i<=2*n;i++) dis[i]=INF ;
     que[0]=i ; dis[i]=0 ;
     while(tail<=head)
     {
          int u=que[tail++] , tp=(u>n ? 0 : 1) , u2=(u>n ? u-n : u) ;
          for(int i=0;i<v[u2].size();i++)
          {
               int to= v[u2][i]+tp*n ;
               if(dis[to]==INF) dis[to]=dis[u]+1 , que[++head]=to ;
          }
     }
}

main()
{
     int m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
     while(m--)
     {
          int x,y ; scanf("%d%d",&x,&y) ;
          v[x].push_back(y) ;
          v[y].push_back(x) ;
     }
     for(int i=1;i<=n;i++) BFS(i,d[i]) ;
     while(Q--)
     {
          int x,y,k ; scanf("%d%d%d",&x,&y,&k) ;
          int d1=(int)d[x][y] , d2=(int)d[x][y+n] ;
          if(v[x].empty()) printf("NIE\n") ;
          else if(d1!=INF && ((k-d1)%2==0) && k>=d1) printf("TAK\n") ;
          else if(d2!=INF && ((k-d2)%2==0) && k>=d2) printf("TAK\n") ;
          else printf("NIE\n") ;
     }
}
