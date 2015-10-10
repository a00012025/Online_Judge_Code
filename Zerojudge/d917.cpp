#include<bits/stdc++.h>
using namespace std;
vector<int> v0[1000],v1[1000] ;
int d0[1000],d1[1000] ;

int dp0(int x)
{
    if(v0[x].size()==0) { d0[x]=1 ; return 1 ; }
    if(d0[x]!=-1) return d0[x] ;
    int &ans=d0[x] ; ans=0 ;
    for(int i=0;i<v0[x].size();i++) ans=max(ans,dp0(v0[x][i])+1) ;
    return ans ;
}

int dp1(int x)
{
    if(v1[x].size()==0) { d1[x]=1 ; return 1 ; }
    if(d1[x]!=-1) return d1[x] ;
    int &ans=d1[x] ; ans=0 ;
    for(int i=0;i<v1[x].size();i++) ans=max(ans,dp1(v1[x][i])+1) ;
    return ans ;
}

main()
{
    int n,w ;
    while(scanf("%d%d",&n,&w)!=EOF)
    {
        for(int i=1;i<=n;i++) v0[i].clear() , v1[i].clear() ;
        for(int i=1;i<=n*(n-1)/2;i++)
        {
            int x,y,t ; scanf("%d%d%d",&x,&y,&t) ;
            if(t==0) v0[x].push_back(y) ;
            else v1[x].push_back(y) ;
        }
        memset(d0,-1,sizeof(d0)) ;
        memset(d1,-1,sizeof(d1)) ;
        int ans1=0,ans2=0 ;
        for(int i=1;i<=n;i++) ans1=max(ans1,dp0(i)) , ans2=max(ans2,dp1(i)) ;
        printf("%d\n",w*w*ans1*ans2) ;
    }
}
