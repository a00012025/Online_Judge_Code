#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;
int ST[1200000],n,m,d ;

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { ST[id]+=val ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(l,mid,L,mid,2*id,val) ;
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
    }
}

int query(int L,int R,int id,int pos)
{
    if(L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return ST[id]+query(L,mid,2*id,pos) ;
    else return ST[id]+query(mid+1,R,2*id+1,pos) ;
}

struct P
{
    int x,y;
    bool operator < (const P &rhs) const
    {
        return y!=rhs.y ? y<rhs.y : x<rhs.x ;
    }
}a2[maxn];
struct event{int l,r,val;};
vector<event> v[150001] ;
LL solve2()
{
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        x=x+y ; y=x-2*y+m ; a2[i]=(P){x,y} ;
        v[max(y-d,1)].push_back((event){ max(1,x-d),min(2*m,x+d),1 }) ;
        v[min(y+d,2*m)+1].push_back((event){ max(1,x-d),min(2*m,x+d),-1 }) ;
    }
    sort(a2+1,a2+n+1) ;
    LL ret=0LL ; int nowy=0 ;
    for(int i=1;i<=n;i++)
    {
        while(nowy < a2[i].y)
        {
            nowy++ ;
            for(int j=0;j<v[nowy].size();j++)
            modify(v[nowy][j].l,v[nowy][j].r,1,2*m,1,v[nowy][j].val) ;
        }
        ret+=query(1,2*m,1,a2[i].x) ;
    }
    return (ret-n)/2 ;
}

int a[151][151][76],sum[151][151][76] ;
int Sum(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return sum[x2][y2][z2]-sum[x1-1][y2][z2]-sum[x2][y1-1][z2]-sum[x2][y2][z1-1]
            +sum[x2][y1-1][z1-1]+sum[x1-1][y2][z1-1]+sum[x1-1][y1-1][z2]
            -sum[x1-1][y1-1][z1-1] ;
}

struct Q{int x,y,z;}a3[maxn];
LL solve3()
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a3[i].x,&a3[i].y,&a3[i].z) ;
        a3[i].x+=a3[i].y ; a3[i].y=a3[i].x-2*a3[i].y+m ;
        a[a3[i].x][a3[i].y][a3[i].z]++ ;
    }
    for(int i=1;i<=2*m;i++) for(int j=1;j<=2*m;j++) for(int k=1;k<=m;k++)
        sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]
                    -sum[i][j-1][k-1]-sum[i-1][j][k-1]-sum[i-1][j-1][k]
                    +sum[i-1][j-1][k-1]+a[i][j][k] ;
    LL ret=0LL ;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(a3[i].z-d<=j && a3[i].z+d>=j)
    {
        int tmp=d-( j>=a3[i].z ? j-a3[i].z : a3[i].z-j ) ;
        int add=Sum(max(1,a3[i].x-tmp),max(1,a3[i].y-tmp),j,min(2*m,a3[i].x+tmp),min(2*m,a3[i].y+tmp),j) ;
        ret+=add ;
    }
    return (ret-n)/2 ;
}

int a1[maxn] ;
LL solve1()
{
    for(int i=1;i<=n;i++) scanf("%d",&a1[i]) ;
    sort(a1+1,a1+n+1) ;
    LL ret=0LL ;
    int j=0 ;
    for(int i=1;i<=n;i++)
    {
        int num=1 ;
        while(i<n && a1[i+1]==a1[i]) num++ , i++ ;
        while(j<n && a1[j+1]<=a1[i]+d) j++ ;
        ret+=((LL)num)*((LL)j-i) ;
        ret+=((LL)num)*((LL)num-1)/2 ;
    }
    return ret ;
}

main()
{
    int type ; scanf("%d%d%d%d",&type,&n,&d,&m) ;
    if(type==1) printf("%I64d\n",solve1()) ;
    if(type==2) printf("%I64d\n",solve2()) ;
    if(type==3) printf("%I64d\n",solve3()) ;
}
