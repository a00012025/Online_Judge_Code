#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int tag[8*maxn] ;

void modify(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) { tag[id]++ ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1) ;
    else modify(l,mid,L,mid,2*id) ,
        modify(mid+1,r,mid+1,R,2*id+1) ;
}

int query(int L,int R,int id,int x,int val)
{
    if(L==R) return (tag[id]+val)%2 ;
    int mid=(L+R)/2 ;
    if(x<=mid) return query(L,mid,2*id,x,val+tag[id]) ;
    else return query(mid+1,R,2*id+1,x,val+tag[id]) ;
}

vector<int> v[maxn] ;
int in[maxn],ri[maxn],cnt=0 ;

void dfs(int x)
{
    in[x]=++cnt ;
    for(auto i : v[x]) dfs(i) ;
    ri[x]=cnt ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        int t ; scanf("%d",&t) ;
        while(t--)
        {
            int x ; scanf("%d",&x) ;
            v[i].push_back(x) ;
        }
    }
    dfs(1) ;
    while(m--)
    {
        int tp,x ; scanf("%d%d",&tp,&x) ;
        if(tp==0) modify(in[x],ri[x],1,n,1) ;
        else printf("%d\n",query(1,n,1,in[x],0)) ;
    }
}
