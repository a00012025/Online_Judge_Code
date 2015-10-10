#include<bits/stdc++.h>
#define ABS(x) ((x)>0 ? (x) : (-(x)))
using namespace std;
const int maxn=100000+10 ;
struct P{int sum,ma;} ST[4*maxn];

int x[maxn],y[maxn] ;
int dis(int i,int j)
{
    return ABS(x[i]-x[j])+ABS(y[i]-y[j]) ;
}

void pull(int mid,int id)
{
    ST[id].sum=ST[2*id].sum+ST[2*id+1].sum ;
    ST[id].ma=max(ST[2*id].ma,ST[2*id+1].ma) ;
    ST[id].ma=max(ST[id].ma,
        dis(mid-1,mid)+dis(mid,mid+1)-dis(mid-1,mid+1)) ;
}

void build(int l,int r,int id)
{
    if(r-l==1) { ST[id]=(P){dis(l,r),-1} ; return ; }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid,r,2*id+1) ;
    pull(mid,id) ;
}

void modify(int L,int R,int id,int pos)
{
    if(R-L==1) { ST[id]=(P){dis(L,R),-1} ; return ; }
    int mid=(L+R)/2 ;
    if(pos<mid) modify(L,mid,2*id,pos) ;
    else modify(mid,R,2*id+1,pos) ;
    pull(mid,id) ;
}

P cal(int mid,const P &p,const P &q)
{
    P ret ;
    ret.sum=p.sum+q.sum ;
    ret.ma=max(p.ma,q.ma) ;
    ret.ma=max(ret.ma,
        dis(mid-1,mid)+dis(mid,mid+1)-dis(mid-1,mid+1)) ;
    return ret ;
}

P query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>=mid) return query(l,r,mid,R,2*id+1) ;
    else return cal(mid,query(l,mid,L,mid,2*id),
                    query(mid,r,mid,R,2*id+1)) ;
}

main()
{
    if(fopen("marathon.in","r"))
    {
        freopen("marathon.in","r",stdin) ;
        freopen("marathon.out","w",stdout) ;
    }
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]) ;
    build(1,n,1) ;
    while(Q--)
    {
        char s[5] ; scanf("%s",s) ;
        if(s[0]=='U')
        {
            int pos,nx,ny ; scanf("%d%d%d",&pos,&nx,&ny) ;
            x[pos]=nx ; y[pos]=ny ;
            if(pos>1) modify(1,n,1,pos-1) ;
            if(pos<n) modify(1,n,1,pos) ;
        }
        else
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            if(l==r) printf("0\n") ;
            else if(l+1==r) printf("%d\n",dis(l,r)) ;
            else
            {
                P ans=query(l,r,1,n,1) ;
                printf("%d\n",ans.sum-ans.ma) ;
            }
        }
    }
}
