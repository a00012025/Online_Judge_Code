#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct P{int id ; LL val,tag;}ST[1000000] ;
struct Q{int l,r ; LL val ;};
vector<Q> v[40000] ;
LL R[40000],C[40000] ;

void build_tree(int l,int r,int id)
{
    if(l==r) {ST[id]=(P){l,C[l],0LL} ; return ; }
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id) ; build_tree(mid+1,r,2*id+1) ;
    if(ST[2*id+1].val>ST[2*id].val)
        ST[id]=(P){ST[2*id+1].id , ST[2*id+1].val , 0LL} ;
    else
        ST[id]=(P){ST[2*id].id , ST[2*id].val , 0LL} ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R)
    {
        ST[id].tag+=val ; ST[id].val+=val ; return ;
    }
    if(ST[id].tag!=0LL)
    {
        ST[2*id].tag+=ST[id].tag ; ST[2*id].val += ST[id].tag ;
        ST[2*id+1].tag+=ST[id].tag ; ST[2*id+1].val += ST[id].tag ;
        ST[id].tag=0LL ;
    }
    int mid=(L+R)/2 ;
    if(mid>=r) modify(l,r,L,mid,2*id,val) ;
    else if(mid<l) modify(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(l,mid,L,mid,2*id,val) ;
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
    }
    if(ST[2*id+1].val > ST[2*id].val)
        ST[id]=(P){ST[2*id+1].id , ST[2*id+1].val , 0LL} ;
    else
        ST[id]=(P){ST[2*id].id , ST[2*id].val , 0LL} ;
}

main()
{
    int T ;scanf("%d",&T) ;
    while(T--)
    {
        int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++) scanf("%lld",&R[i]) ; R[0]=0LL ;
        for(int i=1;i<=m;i++) scanf("%lld",&C[i]) ;
        for(int i=1;i<=n;i++)
            v[i].push_back((Q){1,m,R[i]-R[i-1]}) ;
        while(k--)
        {
            int x,y,d ; LL pow ;
            scanf("%d%d%d%lld",&x,&y,&d,&pow) ;
            v[max(1,x-d)].push_back((Q){max(1,y-d),min(m,y+d),-pow}) ;
            v[min(n,x+d)+1].push_back((Q){max(1,y-d),min(m,y+d),pow}) ;
        }
        build_tree(1,m,1) ;
        LL ans=0LL ; int ansx=1,ansy=1 ;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
                modify(v[i][j].l,v[i][j].r,1,m,1,v[i][j].val) ;
            if(ST[1].val > ans) {ans=ST[1].val ; ansx=i ; ansy=ST[1].id ;}
        }
        printf("%d %d %lld\n",ansx,ansy,ans) ;
    }
}
