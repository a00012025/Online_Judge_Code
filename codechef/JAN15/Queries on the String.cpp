#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
#define lowbit(x) (x&(-x))
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif // _WIN32
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
int n,a[maxn],sum[maxn] ;
int ST[8*maxn][3],tag[8*maxn] ;

void build(int l,int r,int id)
{
    if(l==r){ ST[id][sum[l]]=1 ; return ; }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    for(int i=0;i<3;i++) ST[id][i]=ST[2*id][i]+ST[2*id+1][i] ;
}

void push(int id)
{
    int tmp[3],val=tag[id] ;
    for(int i=0;i<3;i++) tmp[i]=ST[2*id][i] ;
    for(int i=0;i<3;i++) ST[2*id][(i+val)%3]=tmp[i] ;
    for(int i=0;i<3;i++) tmp[i]=ST[2*id+1][i] ;
    for(int i=0;i<3;i++) ST[2*id+1][(i+val)%3]=tmp[i] ;
    tag[2*id]+=tag[id] ; tag[2*id]%=3 ;
    tag[2*id+1]+=tag[id] ; tag[2*id+1]%=3 ;
    tag[id]=0 ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R)
    {
        int tmp[3] ;
        for(int i=0;i<3;i++) tmp[i]=ST[id][i] ;
        for(int i=0;i<3;i++) ST[id][(i+val)%3]=tmp[i] ;
        tag[id]=(tag[id]+val)%3 ;
        return ;
    }
    if(tag[id]) push(id) ;

    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(l,mid,L,mid,2*id,val) ;
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
    }
    for(int i=0;i<3;i++) ST[id][i]=ST[2*id][i]+ST[2*id+1][i] ;
}

int query(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) return ST[id][val] ;
    if(tag[id]) push(id) ;

    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id,val) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1,val) ;
    else return
        query(l,mid,L,mid,2*id,val)+query(mid+1,r,mid+1,R,2*id+1,val) ;
}

int bit[maxn] ;

int query(int x)
{
    int ret=0 ;
    while(x) ret+=bit[x] , x-=lowbit(x) ;
    return ret ;
}

void modify2(int x,int val)
{
    while(x<=n) bit[x]+=val , x+=lowbit(x) ;
}

main()
{
    int Q ; scanf("%d%d%s",&n,&Q,s+1) ;
    memset(tag,0,sizeof(tag)) ;
    sum[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        a[i]=(s[i]-'0')%3 ;
        sum[i]=(sum[i-1]+a[i])%3 ;
        bit[i]=sum[i]-sum[i-lowbit(i)] ;
    }
    build(0,n,1) ;
    while(Q--)
    {
        int type,x,y ; scanf("%d%d%d",&type,&x,&y) ;
        if(type==1)
        {
            int val1=query(x) , val2=query(x-1)+y ;
            modify2(x,y-a[x]) ; a[x]=y ;
            modify(x,n,0,n,1,(((val2-val1)%3)+3)%3) ;
        }
        else
        {
            LL ans=0LL ;
            for(int i=0;i<3;i++)
            {
                LL val=query(x-1,y,0,n,1,i) ;
                ans+=val*(val-1)/2 ;
            }
            printf(LLD"\n",ans) ;
        }
    }
}
