#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 , maxm=1000000+10 ;

int vis[maxm] ;
int la[maxm],MA=0 ;
void prime()
{
     for(int i=2;i*i<=MA;i++) if(!vis[i])
          for(int j=i*i;j<=MA;j+=i) vis[j]=1 , la[j]=i ;
}

int d[maxm] ;
void getd()
{
     d[1]=0 ;
     for(int i=2;i<=MA;i++) d[i]= vis[i] ? d[i/la[i]]+1 : 1 ;
}

int getdis(int x,int y)
{
     int g=__gcd(x,y) ;
     return d[x]+d[y]-2*d[g] ;
}

struct P
{
     int id,val ;
     bool operator < (const P &rhs) const
     {
          return d[val]==d[rhs.val] ? id<rhs.id : d[val]<d[rhs.val] ;
     }
};

P v[maxm][3] ;
int sz[maxm] ;
void PB(int vid,const P &p)
{
     v[vid][sz[vid]++]=p ;
     if(sz[vid]==3)
     {
          for(int i=0;i<2;i++) for(int j=2;j>i;j--)
               if(v[vid][j]<v[vid][j-1]) swap(v[vid][j],v[vid][j-1]) ;
          sz[vid]-- ;
     }
}

int a[maxn] ;
main()
{
     int n ; scanf("%d",&n) ;
     for(int i=1;i<=n;i++) scanf("%d",&a[i]) , MA=max(MA,a[i]) ;

     prime() ;
     getd() ;
     for(int i=1;i<=n;i++)
          for(int j=1;j*j<=a[i];j++) if(a[i]%j==0)
     {
          PB(j,(P){i,a[i]}) ;
          if(a[i]!=j*j) PB(a[i]/j,(P){i,a[i]}) ;
     }

     for(int i=1;i<=n;i++)
     {
          int ans=maxm , id=n+1 ;

          for(int j=1;j*j<=a[i];j++) if(a[i]%j==0)
               for(int t=0;t<2;t++)
          {
               int x= (t==0 ? j : a[i]/j) ;
               if(v[x][0].id==i && sz[x]==1) continue ;

               P tmp= (v[x][0].id==i ? v[x][1] : v[x][0]) ;
               int val=getdis(tmp.val,a[i]) ;
               if(val<ans || (val==ans && tmp.id<id))
                    ans=val , id=tmp.id ;
          }
          printf("%d\n",id) ;
     }
}
