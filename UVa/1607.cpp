#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[200001] ;
int n,m,in[200001],fa1[200001],fa2[200001];
int topo[200001],t ;
bool res[200001],vis[200001] ;
char ans[200001] ;

int val(int x)
{
    if(x<0) return in[-x] ;
    else return res[x] ;
}

void dfs(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs(v[x][i]) ;
    topo[--t]=x ;
}

void find_topo()
{
    memset(vis,0,sizeof(vis)) ;
    t=m+1 ;
    for(int i=1;i<=m;i++) if(!vis[i]) dfs(i) ;
}

bool out()
{
    int i ;
    for(i=1;i<=m;i++)
        res[topo[i]]=!(val(fa1[topo[i]]) && val(fa2[topo[i]])) ;
    return res[topo[m]] ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=1;i<=m;i++) v[i].clear() ;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&fa1[i],&fa2[i]) ;
            if(fa1[i]>0) v[fa1[i]].push_back(i) ;
            if(fa2[i]>0) v[fa2[i]].push_back(i) ;
        }
        find_topo() ;
        for(int i=1;i<=n;i++) in[i]=0 ;
        bool r1=out() ;
        for(int i=1;i<=n;i++) in[i]=1 ;
        bool r2=out() ;
        if(r1==r2) for(int i=1;i<=n;i++) ans[i]='0' ;
        else
        {
            int l=0 , r=n ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                for(int i=1;i<=n;i++) in[i]= i<=mid ? 1 : 0 ;
                if(out()==r1) l=mid ;
                else r=mid ;
            }
            for(int i=1;i<=l;i++) ans[i]='1' ;
            ans[l+1]='x' ;
            for(int i=l+2;i<=n;i++) ans[i]='0' ;
        }
        for(int i=1;i<=n;i++) printf("%c",ans[i]) ;
        printf("\n") ;
    }
}
