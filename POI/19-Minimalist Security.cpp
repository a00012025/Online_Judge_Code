#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=500000+10 ;

struct P{int to,d;};

vector<P> v[maxn] ;
int num[maxn],vis[maxn],col[maxn] ;
LL val[maxn] ;

int tmp[maxn],cnt ;
void dfs0(int x)
{
    vis[x]=1 ; tmp[cnt++]=x ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i].to])
        dfs0(v[x][i].to) ;
}

int fa[maxn],fa_d[maxn] ;
int dfs1(int x,int c)
{
    col[x]=c ;
    for(int i=0;i<v[x].size();i++) if(v[x][i].to!=fa[x])
    {
        if(col[v[x][i].to]==-1)
        {
            val[v[x][i].to]=v[x][i].d-val[x] ;
            fa[v[x][i].to]=x ; fa_d[v[x][i].to]=v[x][i].d ;

            int res=dfs1(v[x][i].to,c^1) ;
            if(res!=0) return res ;
        }
        else if(col[v[x][i].to]!=c)
        {
            if(val[v[x][i].to]+val[x]!=v[x][i].d) return -1 ;
        }
        else
        {
            LL sum=v[x][i].d + fa_d[x] ;
            for(int j=fa[x],k=-1;j!=v[x][i].to;j=fa[j])
                sum+= k*fa_d[j] , k=-k ;
            if(sum%2) return -1 ;
            val[x]=sum/2 ; return x ;
        }
    }
    return 0 ;
}

int dfs2_cnt ;
bool dfs2(int x,LL &sum)
{
    if(val[x]<0 || val[x]>num[x]) return 0 ;
    else sum+=num[x]-val[x] ;
    vis[x]=dfs2_cnt ;
    for(int i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i].to]==dfs2_cnt)
        {
            if(val[v[x][i].to]+val[x]!=v[x][i].d) return 0 ;
        }
        else
        {
            val[v[x][i].to]=v[x][i].d-val[x] ;
            if(!dfs2(v[x][i].to,sum)) return 0 ;
        }
    }
    return 1 ;
}

bool solve(int x,LL &mi,LL &ma)
{
    cnt=0 ; dfs0(x) ;

    val[x]=0 ; fa[x]=x ;
    int res=dfs1(x,0) ;
    if(res==-1) return 0 ;
    else if(res>0)
    {
        mi=ma=0LL ; dfs2_cnt=2 ;
        if(!dfs2(res,mi)) return 0 ;
        ma=mi ; return 1 ;
    }

    LL tmi=-INF , tma=INF ;
    for(int i=0;i<cnt;i++)
    {
        if(col[tmp[i]]==0)
            tmi=max(tmi,-val[tmp[i]]) ,
            tma=min(tma,-val[tmp[i]]+num[tmp[i]]) ;
        else
            tmi=max(tmi,val[tmp[i]]-num[tmp[i]]) ,
            tma=min(tma,val[tmp[i]]) ;
    }
    if(tmi > tma) return 0 ;
    val[tmp[0]]+= ( col[tmp[0]]==0 ? tmi : -tmi ) ;
    dfs2_cnt=2 ; mi=0LL ; dfs2(tmp[0],mi) ;
    val[tmp[0]]-= ( col[tmp[0]]==0 ? tmi : -tmi ) ;
    val[tmp[0]]+= ( col[tmp[0]]==0 ? tma : -tma ) ;
    dfs2_cnt=3 ; ma=0LL ; dfs2(tmp[0],ma) ;
    if(mi>ma) swap(mi,ma) ;
    return 1 ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&num[i]) ;
    while(m--)
    {
        int x,y,d ; scanf("%d%d%d",&x,&y,&d) ;
        v[x].push_back((P){y,d}) ;
        v[y].push_back((P){x,d}) ;
    }

    memset(col,-1,sizeof(col)) ;
    LL ans1=0LL , ans2=0LL ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        LL mi,ma ;
        if(!solve(i,mi,ma)) { printf("NIE\n") ; return 0 ; }
        ans1+=mi ; ans2+=ma ;
    }
    printf("%lld %lld\n",ans1,ans2) ;
}
