#include<bits/stdc++.h>
#define pii pair<int,int>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=200000+10,maxk=52 ;
inline void add(LL &a,LL b){a=(a+b)%MOD ;}
LL fac[maxn] ;

struct P{int to,w;};
vector<P> v[maxn],v2[maxn] ; /// v2 : tree edge
bool vis[maxn] ;
int n,fa[maxn],in[maxn],out[maxn],tick ;
int sz[maxn] ;
int id[maxn],cnt1,cnt2,pt1[maxk],pt2[maxk] ;
void dfs(int x,int f)
{
    vis[x]=1 ; fa[x]=f ; sz[x]=1 ;
    in[x]=tick++ ;
    if(x<=n) pt1[cnt1]=x , id[x]=cnt1++ ;
    else pt2[cnt2]=x , id[x]=cnt2++ ;

    v2[x].clear() ;
    for(auto i : v[x]) if(!vis[i.to])
        v2[x].push_back(i) , dfs(i.to,x) , sz[x]+=sz[i.to] ;
    out[x]=tick++ ;
}
inline bool isfa(int x,int y) /// x is fa of y
{
    return in[x]<=in[y] && out[x]>=out[y] ;
}

LL dp0[2][1<<17] ;
LL *solve0(int t)
{
    memset(dp0,0,sizeof(dp0)) ;
    dp0[1][0]=1 ;
    int *pt=(!t ? pt1 : pt2) ;
    int cnt=(!t ? cnt1 : cnt2) , ma=cnt1+cnt2-cnt ;
    for(int i=0;i<cnt;i++)
    {
        fill(dp0[i%2],dp0[i%2]+(1<<17),0) ;
        for(int j=0;j<(1<<ma);j++)
        {
            add(dp0[i%2][j],dp0[(i+1)%2][j]) ;
            for(auto k : v[pt[i]]) if(j&(1<<id[k.to]))
                add(dp0[i%2][j],dp0[(i+1)%2][j^(1<<id[k.to])]*k.w) ;
        }
    }

    static LL ret[maxk] ;
    memset(ret,0,sizeof(ret)) ;
    for(int j=0;j<(1<<ma);j++)
        add(ret[__builtin_popcount(j)],dp0[(cnt-1)%2][j]) ;
    return ret ;
}

bool mark[maxn] ;
LL dp[maxn][maxk][2],tmp[maxk][2] ;
void DP(int x)
{
    if(v2[x].empty()){dp[x][0][0]=1 ; dp[x][0][1]=0 ; return ;}
    for(auto i : v2[x]) DP(i.to) ;

    fill(dp[x][0],dp[x][sz[x]/2]+2,0) ;
    dp[x][0][0]=1 ;
    for(int i=0,sum=1;i<(int)v2[x].size();i++)
    {
        int xi=v2[x][i].to , w=v2[x][i].w , sz2=sz[xi] ;
        for(int j=0;2*j<=sum;j++) for(int k=0;k<2;k++)
            tmp[j][k]=dp[x][j][k] ;
        fill(dp[x][0],dp[x][(sum+sz2)/2]+2,0) ;
        for(int j=0;2*j<=sum;j++) for(int j2=0;2*j2<=sz2;j2++)
        {
            add(dp[x][j+j2][0],tmp[j][0]*(dp[xi][j2][0]+dp[xi][j2][1])) ;
            add(dp[x][j+j2][1],tmp[j][1]*(dp[xi][j2][0]+dp[xi][j2][1])) ;
            if(mark[x]||mark[xi]) continue ;
            add(dp[x][j+j2+1][1],(tmp[j][0]*dp[xi][j2][0]%MOD)*w) ;
        }
        sum+=sz2 ;
    }
}

struct E{int x,y,w;};
vector<E> edge ; /// not tree edge
LL *solve1()
{
    edge.clear() ;
    for(int i=0;i<cnt1;i++) for(auto j : v[pt1[i]])
        if(j.to!=fa[pt1[i]] && fa[j.to]!=pt1[i]
           && isfa(j.to,pt1[i]))
        edge.push_back((E){pt1[i],j.to,j.w}) ;
    for(int i=0;i<cnt2;i++) for(auto j : v[pt2[i]])
        if(j.to!=fa[pt2[i]] && fa[j.to]!=pt2[i]
           && isfa(j.to,pt2[i]))
        edge.push_back((E){pt2[i],j.to,j.w}) ;

    static LL ret[maxk] ;
    memset(ret,0,sizeof(ret)) ;
    int size=edge.size() ;
    for(int i=0;i<(1<<size);i++)
    {
        for(int j=0;j<cnt1;j++) mark[pt1[j]]=0 ;
        for(int j=0;j<cnt2;j++) mark[pt2[j]]=0 ;
        bool ok=1 ;
        LL mul=1LL ; int num=0 ;
        for(int j=0;j<size;j++) if(i&(1<<j))
        {
            num++ ;
            if(mark[edge[j].x]||mark[edge[j].y]){ok=0 ; break ;}
            mark[edge[j].x]=mark[edge[j].y]=1 ;
            mul=mul*edge[j].w%MOD ;
        }
        if(!ok) continue ;
        int root=pt1[0] ; for(;root!=fa[root];root=fa[root]) ;
        DP(root) ;
        for(int j=0;2*j<=sz[root];j++)
            add(ret[num+j],(dp[root][j][0]+dp[root][j][1])*mul) ;
    }
    return ret ;
}

LL ans[maxk],tmp2[maxk] ;
main()
{
    int k ; scanf("%d%d",&n,&k) ;
    fac[0]=1 ;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD ;

    while(k--)
    {
        int x,y,w ; scanf("%d%d%d",&x,&y,&w) ;
        v[x].push_back((P){n+y,w-1}) ;
        v[n+y].push_back((P){x,w-1}) ;
    }

    ans[0]=1 ;
    for(int i=1;i<=n;i++) if(!vis[i] && !v[i].empty())
    {
        cnt1=cnt2=0 ;
        dfs(i,i) ;
        LL *ret ;
        if(cnt2<=17) ret=solve0(0) ;
        else if(cnt1<=17) ret=solve0(1) ;
        else ret=solve1() ;

        for(int j=0;j<maxk;j++) tmp2[j]=ans[j] , ans[j]=0 ;
        for(int j=0;j<maxk;j++) for(int j2=0;j+j2<maxk;j2++)
            add(ans[j+j2],tmp2[j]*ret[j2]) ;
    }
    LL ANS=0LL ;
    for(int i=0;i<maxk;i++) add(ANS,fac[n-i]*ans[i]) ;
    printf("%I64d\n",ANS) ;
}
