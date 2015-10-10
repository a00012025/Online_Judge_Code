#include<bits/stdc++.h>
#define INF 2100000000
#define LL long long
using namespace std;
const int maxn=40000+10 ;

int ST[4*maxn][4] ;
int a[maxn] ;

void cal(int x[4],int y[4],int z[4])
{
    for(int i=0;i<4;i++) z[i]=-INF ;
    for(int i=0;i<4;i++) if(x[i]>=0)
        for(int j=0;j<4;j++) if(y[j]>=0)
        if(!(i&1) || !(j&2))
    {
        int t=((i>>1)<<1)+(j&1) ;
        z[t]=max(z[t],x[i]+y[j]) ;
    }
}

void build(int l,int r,int id)
{
    if(l==r)
    {
        ST[id][0]=0 ;
        ST[id][3]=a[l] ;
        ST[id][1]=ST[id][2]=-INF ;
        return ;
    }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    cal(ST[2*id],ST[2*id+1],ST[id]) ;
}

void modify(int L,int R,int id,int pos,int val)
{
    if(L==R) { ST[id][3]=val ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    cal(ST[2*id],ST[2*id+1],ST[id]) ;
}

int get(int id)
{
    return max(max(ST[id][0],ST[id][1]),max(ST[id][2],ST[id][3])) ;
}

main()
{
    freopen("optmilk.in","r",stdin) ;
    freopen("optmilk.out","w",stdout) ;
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    build(1,n,1) ;
    LL ans=0LL ;
    while(Q--)
    {
        int x,val ; scanf("%d%d",&x,&val) ;
        modify(1,n,1,x,val) ;
        ans+=get(1) ;
    }
    printf("%lld\n",ans) ;
}
