#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
int n,a[maxn],G[17][maxn] ;

void build_RMQ()
{
    for(int i=0;(1<<i)<=n-1;i++) for(int j=0;j+(1<<i)-1<n-1;j++)
        G[i][j]= i==0 ? a[j] : max(G[i-1][j],G[i-1][j+(1<<(i-1))]) ;
}

int RMQ(int l,int r)
{
    int len=r-l+1 ;
    int i=(int)log2(len+0.5) ;
    return max(G[i][l],G[i][r-(1<<i)+1]) ;
}

int ST[8*maxn] ;
bool tag[8*maxn] ;
void build(int L,int R,int id)
{
    ST[id]=R-L+1 ;
    if(L==R) return ;
    int mid=(L+R)/2 ;
    build(L,mid,2*id) ;
    build(mid+1,R,2*id+1) ;
}

void pushdown(int id)
{
    if(!tag[id]) return ;
    ST[2*id]=0 ; ST[2*id+1]=0 ;
    tag[id]=0 ; tag[2*id]=tag[2*id+1]=1 ;
}

void modify(int l,int r,int L,int R,int id) /// set to zero
{
    if(l==L && r==R) { ST[id]=0 ; tag[id]=1 ; return ; }
    pushdown(id) ;
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1) ;
    else
    {
        modify(l,mid,L,mid,2*id) ;
        modify(mid+1,r,mid+1,R,2*id+1) ;
    }
    ST[id]=ST[2*id]+ST[2*id+1] ;
}

int query(int L,int R,int id,int rk)
{
    if(L==R) return L ;
    int mid=(L+R)/2 ;
    if(rk<=ST[2*id]) return query(L,mid,2*id,rk) ;
    else return query(mid+1,R,2*id+1,rk-ST[2*id]) ;
}

int cnt[maxn] ;
main()
{
    int m,r ; scanf("%d%d%d",&n,&m,&r) ;
    for(int i=0;i<n-1;i++) scanf("%d",&a[i]) ;
    build_RMQ() ;
    build(0,n-1,1) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        int x1= x==0 ? -1 : query(0,n-1,1,x) ;
        int y1=query(0,n-1,1,y) ; /// rmq : x1+1 ~ y1
        int y2=query(0,n-1,1,y+1) ; /// segment : x1+1 ~ y2
        int val=RMQ(x1+1,y1) ;
        modify(x1+1,y2-1,0,n-1,1) ;
        if(val<=r)
            cnt[x1+1]++ , cnt[y2+1]-- ;
    }

    int ans=-1 , ansnum=-1 , now=0 ;
    for(int i=0;i<n;i++)
    {
        now+=cnt[i] ;
        if(now>ansnum) ansnum=now , ans=i ;
    }
    if(ans==-1) ans=0 ;
    printf("%d\n",ans) ;
}
