#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int a[10000],b[10000],len[10000]={0},n,ans=0 ;
int light[10000] ;
bool vis[10000]={0} ;
vector<int> v[10000] ;

void dfs(int x,int sum,int l)
{
    ans=max(ans,l) ;
    if(l>len[x]) {len[x]=l ; light[x]=sum ;}
    else if(l==len[x]) light[x]=min(light[x],sum) ;
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]] && sum+a[v[x][i]]<=b[v[x][i]])
        {
            //if(len[v[x][i]]>=l+1) continue ;
            vis[v[x][i]]=1 ;
            dfs(v[x][i],sum+a[v[x][i]],l+1) ;
            vis[v[x][i]]=0 ;
        }
}

main()
{
    n=1 ;
    while(scanf("%d %d",&a[n],&b[n])!=EOF) {if(a[n]<=b[n]) n++ ;}
    n-- ;
    //for(int i=1;i<=n;i++) light=a[i] ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(i!=j && a[i]+a[j]<=b[j]) v[i].push_back(j) ;
    for(int i=1;i<=n;i++)
    {
        vis[i]=1 ;
        dfs(i,a[i],1) ;
        vis[i]=0 ;
    }
    printf("%d\n",ans) ;
}
