#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001],tmp ;
int a[1011],d[1011] ;

int dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    int &ans=d[x] ; ans=0 ;
    if(v[x].empty()) return 0 ;
    for(int i=0;i<v[x].size();i++)
        ans=max(ans,dp(v[x][i])+1) ;
    return ans ;
}

bool G[1001][1001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int k ; scanf("%d",&k) ;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]) ;
        tmp.clear() ;
        for(int i=1;i<k;i++) for(int j=a[i]+1;j<a[i+1];j++) tmp.push_back(j) ;
        for(int i=1;i<=k;i++) for(int j=0;j<tmp.size();j++)
            if(!G[a[i]][tmp[j]])
            G[a[i]][tmp[j]]=1 , v[a[i]].push_back(tmp[j]) ;
    }

    memset(d,-1,sizeof(d)) ;
    for(int i=1;i<=n;i++) if(d[i]==-1) dp(i) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) ans=max(ans,d[i]) ;
    printf("%d\n",ans+1) ;
}
