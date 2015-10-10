#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct P {int st,ed,w,id ;} edge[10000];
struct Q {int ed,id ;} ;
vector<Q> v[1001] ;
int fa[1001],w[10000],d[101],add ;
bool used[10000],vis[10001] ;

bool cmp(P x,P y)
{
    return x.w < y.w ;
}

int getfa(int n)
{
    return n==fa[n] ? n : fa[n]=getfa(fa[n]) ;
}

void dfs(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++) if(!vis[v[n][i].ed])
    {
        d[v[n][i].ed]=max( w[v[n][i].id] , d[n]) ;
        dfs(v[n][i].ed) ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++) {fa[i]=i ; v[i].clear() ;}
        memset(used,0,sizeof(used)) ;
        for(int i=0;i<m;i++)
        {
            int a,b,W ;
            scanf("%d%d%d",&a,&b,&W) ;
            edge[i]=(P){a,b,W,i} ;
            w[i]=W ;
        }
        sort(edge,edge+m,cmp) ;
        int cnt=0 , ans=0 , ans2=0 , fir=1 ;
        for(int i=0;i<m;i++)
        {
            P u=edge[i];
            if(getfa(u.st)!=getfa(u.ed))
            {
                fa[getfa(u.st)]=getfa(u.ed) ;
                ans+=u.w ;
                used[u.id]=1 ;
                v[u.st].push_back((Q){u.ed,u.id}) ;
                v[u.ed].push_back((Q){u.st,u.id}) ;
            }
        }
        add=100000000 ;
        for(int j=0;j<m;j++)
        {
            P u=edge[j] ;
            if(used[u.id]) continue ;
            memset(vis,0,sizeof(vis)) ;
            d[u.st]=0 ;
            dfs(u.st) ;
            add=min(add,u.w-d[u.ed]) ;
        }
        printf("%d %d\n",ans,ans+add) ;
    }
}
