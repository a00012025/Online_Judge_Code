#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;
const int maxn=1000+10 ;
const LL X=12327LL ;

vector<int> v[maxn] ;
bool vis[maxn] ;
int d[maxn],n ;

void dfs0(int x,int dep)
{
    d[x]=dep ;
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
        dfs0(i,dep+1) ;
}

void get_cen(int &len,int &c1,int &c2)
{
    memset(vis,0,sizeof(vis)) ;
    d[1]=0 ; dfs0(1,0) ;
    int M=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>M) M=d[id=i] ;

    memset(vis,0,sizeof(vis)) ;
    d[id]=0 ; dfs0(id,0) ;
    len=-1 ;
    for(int i=1;i<=n;i++) if(d[i]>len) len=d[id=i] ;
    for(int i=id;;)
    {
        if(len%2==0 && d[i]==len/2) { c1=i ; c2=-1 ; break ; }
        else if(len%2 && 2*d[i]-1==len) c1=i ;
        else if(len%2 && 2*d[i]+1==len) { c2=i ; break ; }
        for(auto j : v[i]) if(d[j]==d[i]-1)
            { i=j ; break ; }
    }
}

LL dfs(int x)
{
    vis[x]=1 ;
    vector<LL> tmp ;
    for(auto i : v[x]) if(!vis[i])
        tmp.push_back(dfs(i)) ;
    if(tmp.empty()) return 177LL ;
    LL ret=4931LL ;
    sort(tmp.begin(),tmp.end()) ;
    for(auto i : tmp) ret= ((ret*X)^i)%MOD ;
    return ret ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        int len1,c1,c2 ;
        get_cen(len1,c1,c2) ;
        memset(vis,0,sizeof(vis)) ;
        LL val=dfs(c1) ;

        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        int len2 ;
        get_cen(len2,c1,c2) ;
        if(len2!=len1) { printf("Different\n") ; continue ; }

        bool ok=0 ;
        memset(vis,0,sizeof(vis)) ;
        if(dfs(c1)==val) ok=1 ;
        else
        {
            memset(vis,0,sizeof(vis)) ;
            if(c2!=-1 && dfs(c2)==val) ok=1 ;
        }
        printf("%s\n",ok?"Same":"Different") ;
    }
}
