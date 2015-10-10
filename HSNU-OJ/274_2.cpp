#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int ST[4*maxn],tag[4*maxn] ;
void build(int l,int r,int id)
{
    ST[id]=(r-l+1) ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

void push(int id)
{
    if(!tag[id]) return ;
    tag[2*id]=tag[2*id+1]=1 ;
    ST[2*id]=ST[2*id+1]=0 ;
    tag[id]=0 ;
}

void Set(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) { ST[id]=0 ; tag[id]=1 ; return ; }
    push(id) ;
    int mid=(L+R)/2 ;
    if(r<=mid) Set(l,r,L,mid,2*id) ;
    else if(l>mid) Set(l,r,mid+1,R,2*id+1) ;
    else Set(l,mid,L,mid,2*id) , Set(mid+1,r,mid+1,R,2*id+1) ;
    ST[id]=ST[2*id]+ST[2*id+1] ;
}

int kth(int L,int R,int id,int k)
{
    if(L==R) return L ;
    push(id) ;
    int mid=(L+R)/2 ;
    if(ST[2*id]>=k) return kth(L,mid,2*id,k) ;
    else return kth(mid+1,R,2*id+1,k-ST[2*id]) ;
}

int sum[maxn],cnt[maxn] ;
main()
{
    int n,m,R ; scanf("%d%d%d",&n,&m,&R) ;
    for(int i=0;i<n-1;i++)
    {
        int x ; scanf("%d",&x) ;
        sum[i]=(x>R ? 1 : 0) ;
        if(i) sum[i]+=sum[i-1] ;
    }

    build(0,n-1,1) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        int x1= (x==0 ? -1 : kth(0,n-1,1,x)) ;
        int y1=kth(0,n-1,1,y) ;
        int y2=kth(0,n-1,1,y+1) ;
        int val=(x1==-1 ? sum[y1] : sum[y1]-sum[x1]) ;
        if(val==0) cnt[x1+1]++ , cnt[y2+1]-- ;
        Set(x1+1,y1,0,n-1,1) ;
    }

    int ans=-1 , id ;
    for(int i=0,now=0;i<n;i++)
    {
        now+=cnt[i] ;
        if(now>ans) ans=now , id=i ;
    }
    if(ans==-1) ans=0 ;
    printf("%d\n",id) ;
}
