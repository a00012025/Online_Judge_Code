#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;
int n,a[1101],b[1101] ;
bool vis[1100] ;
vector<int> v[1101] ;


double dis(int x,int y)
{
    long long f=(long long)(a[x]-a[y])*(a[x]-a[y]) ;
    f+=(long long)(b[x]-b[y])*(b[x]-b[y]) ;
    return (double)sqrt(f) ;
}

void dfs(int a)
{
    for(int i=0;i<v[a].size();i++)
    {
        if(vis[v[a][i]]==1) continue ;
        vis[v[a][i]]=1 ;
        dfs(v[a][i]) ;
    }
}

bool check(long long R)
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=0;i<=n;i++) v[i].clear() ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(dis(i,j)<=(long long)2*R){
                v[i].push_back(j) ; v[j].push_back(i) ;}
    vis[1]=1 ;
    dfs(1) ; int i;
    for(i=1;vis[i]==1 && i<=n ; i++) ;
    if(i!=(n+1)) return 0;
    else return 1;
}

main()
{
    int N;
    scanf("%d",&N) ;
    while(N--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]) ;
        long long l=0,r=1414213564 ;
        while(r-l>1)
        {
            long long mid=((long long)r+l)/2 ;
            if(check(mid)==1) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
