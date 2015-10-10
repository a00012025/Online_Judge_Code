#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10,maxm=200000+10 ;

int ST[4*maxn] ;
void build()
{
    memset(ST,-1,sizeof(ST)) ;
}

void modify(int L,int R,int id,int pos,int val)
{
    if(L==R) { ST[id]=val ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    ST[id]=min(ST[2*id],ST[2*id+1]) ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return min(query(l,mid,L,mid,2*id),
                    query(mid+1,r,mid+1,R,2*id+1)) ;
}

struct P
{
    int x1,y1,x2,y2,id ;
    void get(int _id)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
        id=_id ;
    }
    bool operator < (const P &rhs) const
    {
        return x2<rhs.x2 ;
    }
}q[maxm];

int ans[maxm] ;
pii a[maxm] ;
void solve(int n,int m,int k,int Q)
{
    build() ;
    for(int i=1,j=1;i<=Q;i++)
    {
        while(j<=k && a[j].F<=q[i].x2)
            modify(1,m,1,a[j].S,a[j].F) , j++ ;
        if(query(q[i].y1,q[i].y2,1,m,1)>=q[i].x1)
            ans[q[i].id]=1 ;
    }
}

main()
{
    int n,m,k,Q ;
    scanf("%d%d%d%d",&n,&m,&k,&Q) ;
    for(int i=1;i<=k;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
    for(int i=1;i<=Q;i++) q[i].get(i) ;
    sort(q+1,q+Q+1) ;
    sort(a+1,a+k+1) ;
    solve(n,m,k,Q) ;

    swap(n,m) ;
    for(int i=1;i<=k;i++) swap(a[i].F,a[i].S) ;
    for(int i=1;i<=Q;i++)
        swap(q[i].x1,q[i].y1) , swap(q[i].x2,q[i].y2) ;
    sort(q+1,q+Q+1) ;
    sort(a+1,a+k+1) ;
    solve(n,m,k,Q) ;
    for(int i=1;i<=Q;i++) printf("%s\n",ans[i]?"YES":"NO") ;
}
