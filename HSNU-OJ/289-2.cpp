#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=5000+10,maxc=100+2 , KK=15 ;

int n,m,ST[1500][maxc][maxc] ;

int dis[maxc] ;
void sweep_hor(int a[maxc],int h[maxc])
{
     for(int i=1;i<m;i++) dis[i]=dis[i-1]+h[i-1] ;
     int mi=INF ;
     for(int i=0;i<m;i++)
     {
          a[i]=min(a[i],mi+dis[i]) ;
          mi=min(mi,a[i]-dis[i]) ;
     }
     mi=INF ;
     for(int i=m-1;i>=0;i--)
     {
          a[i]=min(a[i],mi-dis[i]) ;
          mi=min(mi,a[i]+dis[i]) ;
     }
}

int H[maxn][maxc],V[maxn][maxc] ;
void cal(int l,int r,int a[maxc][maxc])
{
     for(int i=0;i<m;i++) for(int j=l;j<=r;j++)
     {
          for(int k=0;k<m;k++)
               a[i][k]= (j==l ? (k==i?0:INF) : a[i][k]+V[j-1][k]) ;
          sweep_hor(a[i],H[j]) ;
     }
}

int K[maxc][maxc] ;
void merge(int a[maxc][maxc],int b[maxc][maxc],int c[maxc][maxc])
{
     for(int i=0;i<m;i++) for(int j=0;j<m;j++)
          c[i][j]=INF ;
     for(int i=0;i<m;i++) for(int j=0;j<m;j++)
          if(a[i][j]+b[j][i]<c[i][i])
               c[i][i]=a[i][j]+b[j][i] , K[i][i]=j ;
     for(int i=m-1;i>=0;i--) for(int j=i+1;j<m;j++)
          for(int k=K[i][j-1];k<=K[i+1][j];k++)
          if(a[i][k]+b[k][j]<c[i][j])
               c[i][j]=a[i][k]+b[k][j] , K[i][j]=k ;
     for(int i=0;i<m;i++) for(int j=i-1;j>=0;j--)
          for(int k=K[i-1][j];k<=K[i][j+1];k++)
          if(a[i][k]+b[k][j]<c[i][j])
               c[i][j]=a[i][k]+b[k][j] , K[i][j]=k ;
}

void build(int l,int r,int id)
{
     if(r-l<KK)
     {
          cal(l,r,ST[id]) ;
          return ;
     }
     int mid=(r+l)/2 ;
     build(l,mid,2*id) ;
     build(mid,r,2*id+1) ;
     merge(ST[2*id],ST[2*id+1],ST[id]) ;
}

void modify(int L,int R,int id,int pos)
{
     if(R-L<KK) { cal(L,R,ST[id]) ; return ; }
     int mid=(L+R)/2 ;
     if(pos<=mid) modify(L,mid,2*id,pos) ;
     else modify(mid,R,2*id+1,pos) ;
     merge(ST[2*id],ST[2*id+1],ST[id]) ;
}

void modify_hor(int x,int y,int val)
{
     H[x][y]=val ;
     if(x) modify(0,n-1,1,x) ;
     if(x<n-1) modify(0,n-1,1,x+1) ;
}

void modify_ver(int x,int y,int val)
{
     V[x][y]=val ;
     modify(0,n-1,1,x+1) ;
}

main()
{
     scanf("%d%d",&n,&m) ;
     for(int i=0;i<n;i++) for(int j=0;j<m-1;j++) scanf("%d",&H[i][j]) ;
     for(int i=0;i<n-1;i++) for(int j=0;j<m;j++) scanf("%d",&V[i][j]) ;
     build(0,n-1,1) ;
     int Q ; scanf("%d",&Q) ;
     while(Q--)
     {
          int op ; scanf("%d",&op) ;
          if(op==1)
          {
               int x,y,val ; scanf("%d%d%d",&x,&y,&val) ;
               modify_hor(x,y,val) ;
          }
          else if(op==2)
          {
               int x,y,val ; scanf("%d%d%d",&x,&y,&val) ;
               modify_ver(x,y,val) ;
          }
          else
          {
               int x,y ; scanf("%d%d",&x,&y) ;
               printf("%d\n",ST[1][x][y]) ;
          }
     }
}
