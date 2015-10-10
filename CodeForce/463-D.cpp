#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int d[maxn] ;
vector<int> v[maxn] ;
int dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    int &ans=d[x] ; ans=1 ;
    for(auto i : v[x]) ans=max(ans,dp(i)+1) ;
    return ans ;
}

int a[maxn],gr[maxn][maxn] ;

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int z=1;z<=k;z++)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            gr[a[i]][a[j]]++ ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(gr[i][j]==k) v[i].push_back(j) ;
    memset(d,-1,sizeof(d)) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) ans=max(ans,dp(i)) ;
    printf("%d\n",ans) ;
}
