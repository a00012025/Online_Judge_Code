#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int getint()
{
     char c=getchar() ;
     while(c<'0' || c>'9') c=getchar() ;
     int x=0 ;
     while(1)
     {
          x=x*10+(c-'0') ;
          c=getchar() ;
          if(c<'0' || c>'9') return x ;
     }
}

vector<int> v[maxn] ;

int a[maxn] ;
int p[maxn],q[maxn] ;
int le[maxn],ri[maxn] ;

int num1[maxn],num2[maxn],R[maxn] ;
vector<int> ans ;

main()
{
     int n=getint(),k=getint() ;
     for(int i=1;i<=n;i++)
     {
          a[i]=getint() ;
          v[a[i]].push_back(i) ;
          ri[i]=n+1 ;
     }
     ri[n+1]=n+1 ;

     int m=getint(),l=getint() ;
     for(int i=1;i<=m;i++) p[i]=getint() ;
     for(int i=1;i<=l;i++) q[i]=getint() ;
     for(int i=1;i<m;i++) for(int j=0;j<v[p[i+1]].size();j++)
     {
          int x=v[p[i+1]][j] ;
          int id=lower_bound(v[p[i]].begin(),v[p[i]].end(),x)-v[p[i]].begin()-1 ;
          if(id>=0) le[x]=v[p[i]][id] ;
          if(i!=1) le[x]=le[le[x]] ;
     }

     for(int i=1;i<l;i++) for(int j=0;j<v[q[i+1]].size();j++)
     {
          int x=v[q[i+1]][j] ;
          int id=lower_bound(v[q[i]].begin(),v[q[i]].end(),x)-v[q[i]].begin() ;
          if(id<v[q[i]].size()) ri[x]=v[q[i]][id] ;
          if(i!=1) ri[x]=ri[ri[x]] ;
     }

     for(int i=1;i<=n;i++) num2[a[i]]++ ;
     for(int i=1 , j=1 , now=0;i<=n;i++)
     {
          num1[a[i]]++ ;
          if(num1[a[i]]==1 && num2[a[i]]) now++ ;
          while(j<=n)
          {
               num2[a[j]]-- ;
               if(!num2[a[j]] && num1[a[j]]) now-- ;
               if(!now) { num2[a[j]]++ ; now++ ; break ; }
               j++ ;
          }
          R[i]=j ;
     }
     for(int i=1;i<=n;i++) if(a[i]==p[m])
     {
          int x= (m==1 ? i : le[i]) ;
          int y= (l==1 ? i : ri[i]) ;
          if(x>1 && y<n && R[x-1]>=y+1)
               ans.push_back(i) ;
     }
     printf("%d\n",ans.size()) ;
     for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
     if(ans.empty()) printf("\n") ;
}
