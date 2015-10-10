#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 , maxc=2000000+10 ;

int ST[maxc*4],tag[maxc*4] ;

void push(int id)
{
    if(!tag[id]) return ;
    ST[2*id]+=tag[id] ; tag[2*id]+=tag[id] ;
    ST[2*id+1]+=tag[id] ; tag[2*id+1]+=tag[id] ;
    tag[id]=0 ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { ST[id]+=val ; tag[id]+=val ; return ; }
    push(id) ;
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else modify(l,mid,L,mid,2*id,val) ,
            modify(mid+1,r,mid+1,R,2*id+1,val) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

struct P
{
    int x,l,r,val ;
    bool operator < (const P &rhs) const
    {
        return x<rhs.x ;
    }
}p[maxn];

main()
{
    if(fopen("lazy.in","r"))
    {
        freopen("lazy.in","r",stdin) ;
        freopen("lazy.out","w",stdout) ;
    }
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++)
    {
        int x,y,val ; scanf("%d%d%d",&val,&x,&y) ;
        p[i]=(P){x-y,max(x+y-2*k,0),x+y,val} ;
    }
    sort(p+1,p+n+1) ;
    int ans=0 ;
    for(int i=1,j=1;i<=n;i++)
    {
        modify(p[i].l,p[i].r,0,maxc,1,p[i].val) ;
        while(p[j].x+2*k < p[i].x)
            modify(p[j].l,p[j].r,0,maxc,1,-p[j].val) , j++ ;
        ans=max(ans,ST[1]) ;
    }
    printf("%d\n",ans) ;
}
