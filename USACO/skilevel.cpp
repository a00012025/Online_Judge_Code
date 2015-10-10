#include<bits/stdc++.h>
#define ABS(x) ((x)>0 ? (x) : (-(x)))
#define LL long long
using namespace std;
const int maxn=500+10 ;

int dx[]={1,0},dy[]={0,1} ;

int G[maxn][maxn] ;
struct P
{
    int x,y,val ;
    bool operator < (const P &rhs) const
    {
        return val==rhs.val ? (x==rhs.x ? y<rhs.y : x<rhs.x) : val<rhs.val ;
    }
}p[2*maxn*maxn];

int q[maxn*maxn] ;
int fa[maxn*maxn],size[maxn*maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

main()
{
    freopen("skilevel.in","r",stdin) ;
    freopen("skilevel.out","w",stdout) ;
    int n,m,T ; scanf("%d%d%d",&n,&m,&T) ;
    if(T==1) { printf("0\n") ; return 0 ; }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        scanf("%d",&G[i][j]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int x ; scanf("%d",&x) ;
        size[i*m+j]=1 ; fa[i*m+j]=i*m+j ;
        if(x==1) q[i*m+j]++ ;
    }

    int cnt=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int x=m*i+j ;
        for(int z=0;z<2;z++)
        {
            int ni=i+dx[z] , nj=j+dy[z] ;
            if(ni<0||ni>=n||nj<0||nj>=m) continue ;
            int y=m*ni+nj ;
            p[cnt++]=(P){x,y,ABS(G[i][j]-G[ni][nj])} ;
        }
    }

    sort(p,p+cnt) ;
    LL ans=0LL ;
    for(int i=0;i<cnt;i++)
    {
        int x=getfa(p[i].x) , y=getfa(p[i].y) ;
        if(x==y) continue ;
        size[y]+=size[x] ; fa[x]=y ; q[y]+=q[x] ;
        if(size[y]>=T) ans+=(LL)q[y]*p[i].val, q[y]=0 ;
    }
    printf("%lld\n",ans) ;
}
