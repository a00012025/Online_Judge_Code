#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
#define LL long long
#define MOD 1000000000
using namespace std;
const int maxn=100000+10 , dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;

bool cmp1(const pii &a,const pii &b){ return a.F==b.F ? a.S<b.S : a.F<b.F ; }
bool cmp2(const pii &a,const pii &b){ return a.S==b.S ? a.F<b.F : a.S<b.S ; }
map<pii,int> mp1,mp2 ;

vector<int> v1[maxn],v2[maxn] ;
int n,w1[maxn],w2[maxn] ;
int gp1[maxn],gp2[maxn],cnt1,cnt2 ;

pii a[maxn],b[maxn] ;

bool vis[maxn] ;
LL ans=0LL ;
int dfs1(int x)
{
    int ret=w1[x] ;
    vis[x]=1 ;
    for(int i=0;i<v1[x].size();i++) if(!vis[v1[x][i]])
    {
        int tmp=dfs1(v1[x][i]) ;
        ret+=tmp ;
        ans+=((LL)tmp)*((LL)n-tmp) ; ans%=MOD ;
    }
    return ret ;
}
int dfs2(int x)
{
    int ret=w2[x] ;
    vis[x]=1 ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
    {
        int tmp=dfs2(v2[x][i]) ;
        ret+=tmp ;
        ans+=((LL)tmp)*((LL)n-tmp) ; ans%=MOD ;
    }
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S) ;
        b[i]=a[i] ;
    }
    sort(a+1,a+n+1,cmp1) ;
    sort(b+1,b+n+1,cmp2) ;
    for(int i=1;i<=n;i++) mp1[a[i]]=i , mp2[b[i]]=i ;

    cnt1=0 ; cnt2=0 ;
    for(int i=1;i<=n;i++)
    {
        if(i==1 || a[i].F!=a[i-1].F || a[i].S!=a[i-1].S+1) cnt1++ ;
        gp1[i]=cnt1 ; w1[cnt1]++ ;
        if(i==1 || b[i].S!=b[i-1].S || b[i].F!=b[i-1].F+1) cnt2++ ;
        gp2[i]=cnt2 ; w2[cnt2]++ ;
    }
    for(int i=1;i<=n;i++) for(int z=0;z<4;z++)
    {
        int nx=a[i].F+dx[z] , ny=a[i].S+dy[z] ;
        if(mp1.count(mkp(nx,ny)))
            v1[gp1[i]].push_back(gp1[mp1[mkp(nx,ny)]]) ;

        nx=b[i].F+dx[z] , ny=b[i].S+dy[z] ;
        if(mp2.count(mkp(nx,ny)))
            v2[gp2[i]].push_back(gp2[mp2[mkp(nx,ny)]]) ;
    }

    dfs1(1) ;
    memset(vis,0,sizeof(vis)) ;
    dfs2(1) ;
    printf("%I64d\n",ans) ;
}
