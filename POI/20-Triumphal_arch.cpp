#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10 ;

vector<int> v[maxn] ;

int dfs(int x,int f,int num)
{
     if(x!=1 && v[x].size()==1) return 0 ;
     int val=0 ;
     for(int i=0;i<v[x].size();i++) if(v[x][i]!=f)
          val+=dfs(v[x][i],x,num)+1 ;
     return max(0,val-num) ;
}

main()
{
     int n ; scanf("%d",&n) ;
     for(int i=1;i<n;i++)
     {
          int x,y ; scanf("%d%d",&x,&y) ;
          v[x].push_back(y) ;
          v[y].push_back(x) ;
     }

     int l=-1 , r=n-1 ;
     while(r-l>1)
     {
          int mid=(r+l)/2 ;
          if(dfs(1,1,mid)==0LL) r=mid ;
          else l=mid ;
     }
     printf("%d\n",r) ;
}
