#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define DB double
using namespace std;
struct P {DB l,r;};
double ans,sum[500],r ;
bool vis[500] ;
vector<P> tree[500] ;

int bit_cnt(int n)
{
    if(!n) return 0 ;
    return n%2 ? 1+bit_cnt(n/2) : bit_cnt(n/2) ;
}

void dfs(int x)
{
    if(vis[x]) return ;
    tree[x].clear() ;
    if(bit_cnt(x)==1) {tree[x].push_back((P){0.0,0.0}) ; return ;}
    for(int i=(x-1)&x;i;i=(i-1)&x)
    {
        DB l1=sum[x-i]/sum[x] ;
        DB l2=sum[i]/sum[x];
        dfs(i) ; dfs(x-i) ;
        for(int j=0;j<tree[i].size();j++) for(int k=0;k<tree[x-i].size();k++)
        {
            P p;
            p.l=max(tree[i][j].l+l1,tree[x-i][k].l-l2) ;
            p.r=max(tree[x-i][k].r+l2,tree[i][j].r-l1) ;
            if(p.l+p.r <= r) tree[x].push_back(p) ;
        }
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int a[10],n ;
        scanf("%lf %d",&r,&n) ;
        for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
        for(int i=0;i<(1<<n);i++)
        {
            sum[i]=0.0 ;
            for(int j=0;j<n;j++) if(i&(1<<j)) sum[i]+=a[j] ;
        }

        memset(vis,0,sizeof(vis)) ;
        int root=(1<<n)-1 ;
        dfs((1<<n)-1) ;

        DB ans=-1 ;
        for(int i=0;i<tree[root].size();i++)
                ans=max(ans,tree[root][i].r+tree[root][i].l);
        if(ans==-1.0) printf("-1\n") ;
        else printf("%.16lf\n",ans) ;
    }
}
