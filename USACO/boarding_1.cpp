#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=200000+10 ;

int ST[8*maxn],tag1[8*maxn],tag2[8*maxn] ; /// 1 : add , 2 : set
void build(int l,int r,int id)
{
    tag1[id]=0 ; tag2[id]=INF ; ST[id]=-1 ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

void push(int id)
{
    if(tag1[id])
    {
        int val=tag1[id] ;
        if(tag2[2*id]==INF) tag1[2*id]+=val ;
        else tag2[2*id]+=val ;
        ST[2*id]+=val ;
        if(tag2[2*id+1]==INF) tag1[2*id+1]+=val ;
        else tag2[2*id+1]+=val ;
        ST[2*id+1]+=val ;
        tag1[id]=0 ;
    }
    else if(tag2[id]!=INF)
    {
        tag2[2*id]=ST[2*id]=tag2[id] ; tag1[2*id]=0 ;
        tag2[2*id+1]=ST[2*id+1]=tag2[id] ; tag1[2*id+1]=0 ;
        tag2[id]=INF ;
    }
}

void add(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R)
    {
        if(tag2[id]==INF) tag1[id]+=val ;
        else tag2[id]+=val ;
        ST[id]+=val ;
        return ;
    }
    push(id) ;
    int mid=(L+R)/2 ;
    if(r<=mid) add(l,r,L,mid,2*id,val) ;
    else if(l>mid) add(l,r,mid+1,R,2*id+1,val) ;
    else add(l,mid,L,mid,2*id,val) , add(mid+1,r,mid+1,R,2*id+1,val) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

void Set(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R)
    {
        tag1[id]=0 ; tag2[id]=ST[id]=val ;
        return ;
    }
    push(id) ;
    int mid=(L+R)/2 ;
    if(r<=mid) Set(l,r,L,mid,2*id,val) ;
    else if(l>mid) Set(l,r,mid+1,R,2*id+1,val) ;
    else Set(l,mid,L,mid,2*id,val) , Set(mid+1,r,mid+1,R,2*id+1,val) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

int query(int L,int R,int id,int pos)
{
    if(L==R) return ST[id] ;
    push(id) ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return query(L,mid,2*id,pos) ;
    else return query(mid+1,R,2*id+1,pos) ;
}

set<int> st ;
int n ;
int Insert(int x)
{
    st.insert(x) ; auto it=st.find(x) ;
    bool keep=1 ;
    int val=query(1,n+1,1,x) ;
    if(it!=st.begin())
    {
        it-- ;
        if(query(1,n+1,1,*it) >= val) keep=0 ;
        it++ ;
    }
    if(!keep) { st.erase(it) ; return 0 ; }

    while(1)
    {
        auto it2=it ; it2++ ;
        if(it2==st.end()) return n+1 ;
        else if(query(1,n+1,1,*it2) > val) return (*it2)-1 ;
        else st.erase(it2) ;
    }
}

int p[maxn],t[maxn] ;

main()
{
    freopen("boarding.in","r",stdin) ;
    freopen("boarding.out","w",stdout) ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&t[i]) ;
    build(1,n+1,1) ;
    int ans=0 ;
    st.insert(1) ;
    for(int i=n;i>=1;i--)
    {
        int val=query(1,n+1,1,p[i]+1) ;
        ans=max(ans,val+p[i]+1+t[i]) ;
        add(1,p[i]+1,1,n+1,1,1) ;
        add(p[i]+1,p[i]+1,1,n+1,1,t[i]) ;
        //int x=Insert(p[i]+1) ;
        int x=p[i]+1 ;
        while(x<=n+1 && query(1,n+1,1,x)<=val+t[i]+1) x++ ; x-- ;
        //assert(x) ;
        Set(p[i]+1,x,1,n+1,1,val+t[i]+1) ;

        for(int j=1;j<=n;j++)
            printf("%d%c",query(1,n+1,1,j),j==n?'\n':' ') ;
        //for(int j=1;j<=n;j++)
            //assert(query(1,n+1,1,j)<=query(1,n+1,1,j+1)) ;
    }
    printf("%d\n",ans) ;
}

