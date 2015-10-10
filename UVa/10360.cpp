#include<bits/stdc++.h>
using namespace std;
struct P{int id,val,tag;}ST[10000] ;
struct Q{int l,r,val ;};
vector<Q> v[2000] ;

void build_tree(int l,int r,int id)
{
    if(l==r) {ST[id]=(P){l,0,0} ; return ; }
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id) ; build_tree(mid+1,r,2*id+1) ;
    if(ST[2*id+1].val>ST[2*id].val)
        ST[id]=(P){ST[2*id+1].id , ST[2*id+1].val , 0} ;
    else
        ST[id]=(P){ST[2*id].id , ST[2*id].val , 0} ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R)
    {
        ST[id].tag+=val ; ST[id].val+=val ; return ;
    }
    if(ST[id].tag!=0)
    {
        ST[2*id].tag+=ST[id].tag ; ST[2*id].val += ST[id].tag ;
        ST[2*id+1].tag+=ST[id].tag ; ST[2*id+1].val += ST[id].tag ;
        ST[id].tag=0 ;
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
        ST[id]=(P){ST[2*id+1].id , ST[2*id+1].val , 0} ;
    else
        ST[id]=(P){ST[2*id].id , ST[2*id].val , 0} ;
}

main()
{
    int T ;scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<=1024;i++) v[i].clear() ;
        int d,m ; scanf("%d%d",&d,&m) ;
        while(m--)
        {
            int x,y,num ; scanf("%d%d%d",&x,&y,&num) ;
            v[max(0,x-d)].push_back((Q){max(0,y-d),min(1024,y+d),num}) ;
            v[min(1025,x+d+1)].push_back((Q){max(0,y-d),min(1024,y+d),-num}) ;
        }
        build_tree(0,1024,1) ;
        int ans=0 ; int ansx,ansy ;
        for(int i=0;i<=1024;i++)
        {
            for(int j=0;j<v[i].size();j++)
                modify(v[i][j].l,v[i][j].r,0,1024,1,v[i][j].val) ;
            if(ST[1].val > ans) ans=ST[1].val , ansx=i , ansy=ST[1].id ;
        }
        printf("%d %d %d\n",ansx,ansy,ans) ;
    }
}
