#include<bits/stdc++.h>
#define LL long long
#define SQR(x) (((LL)(x))*((LL)(x)))
#define CUB(x) (((LL)(x))*((LL)(x))*((LL)(x)))
using namespace std;
const int maxn=5000+10 ;

vector<int> v[maxn] ;
short d[maxn][maxn] ;

int n,root ;
int dfs(int x,int l,int f)
{
    d[root][l]++ ;
    int ret=l ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=f)
        ret=max(ret,dfs(v[x][i],l+1,x)) ;
    return ret ;
}

int getd(int x,int f)
{
    fill(d[x],d[x]+n,0) ;
    root=x ;
    return dfs(x,0,f) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    LL ans=0LL ;
    for(int i=1;i<=n;i++)
    {
        int maxd=0 ;
        for(int j=0;j<v[i].size();j++) maxd=max(maxd,getd(v[i][j],i)) ;
        for(int dep=0;dep<=maxd;dep++)
        {
            LL sum=0LL , sqr=0LL , cub=0LL ;
            for(int j=0;j<v[i].size();j++)
                sum+=d[v[i][j]][dep] ,
                sqr+=SQR(d[v[i][j]][dep]) ,
                cub+=CUB(d[v[i][j]][dep]) ;
            ans+=(CUB(sum)+2*cub-3*sqr*sum)/6 ;
        }
    }
    printf("%lld\n",ans) ;
}
