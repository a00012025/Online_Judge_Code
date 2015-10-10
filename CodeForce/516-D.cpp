#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=100000+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;
LL d1[maxn],d2[maxn],val[maxn] ;
int n ;

void dfs(int x,int f,LL *d)
{
    for(auto i : v[x]) if(i.to!=f)
        d[i.to]=d[x]+i.dis , dfs(i.to,x,d) ;
}

void getdia(int &a,int &b)
{
    d1[1]=0 ; dfs(1,-1,d1) ;
    LL M=-1 ;
    for(int i=1;i<=n;i++) if(d1[i]>M) M=d1[a=i] ;
    d1[a]=0 ; dfs(a,-1,d1) ;
    M=-1 ;
    for(int i=1;i<=n;i++) if(d1[i]>M) M=d1[b=i] ;
}

void getval()
{
    int a,b ; getdia(a,b) ;
    d1[a]=0 ; dfs(a,-1,d1) ;
    d2[b]=0 ; dfs(b,-1,d2) ;
    for(int i=1;i<=n;i++) val[i]=max(d1[i],d2[i]) ;
}

int pos[maxn],ri[maxn],t ;
int anc[18][maxn] ;
void dfs2(int x,int f)
{
    pos[x]=++t ;
    anc[0][x]=f ;
    for(int i=1;i<18;i++) anc[i][x]=anc[i-1][anc[i-1][x]] ;
    for(auto i : v[x]) if(i.to!=f)
       dfs2(i.to,x) ;
    ri[x]=t ;
}

int getinterval()
{
    LL mi=INF ;
    int root ;
    for(int i=1;i<=n;i++) if(val[i]<mi) mi=val[root=i] ;
    dfs2(root,root) ;
    return root ;
}

int sum[maxn] ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }

    getval() ;
    int root=getinterval() ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        LL L ; scanf("%I64d",&L) ;
        memset(sum,0,sizeof(sum)) ;
        for(int i=1;i<=n;i++)
        {
            if(val[i]-val[root]<=L) { sum[pos[i]]++ ; continue ; }
            int j=i ;
            for(int k=17;k>=0;k--) if(val[i]-val[anc[k][j]]<=L)
                j=anc[k][j] ;
            j=anc[0][j] ;
            sum[pos[i]]++ ; sum[pos[j]]-- ;
        }

        for(int i=1;i<=n;i++) sum[i]+=sum[i-1] ;
        int ans=0 ;
        for(int i=1;i<=n;i++) ans=max(ans,sum[ri[i]]-sum[pos[i]-1]) ;
        printf("%d\n",ans) ;
    }
}
