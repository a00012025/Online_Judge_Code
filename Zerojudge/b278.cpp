#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<stdio.h>
#define LL long long
const int maxn=500000 + 5 ;
int cnt ;
LL ST[20*maxn] ;
int left[20*maxn],right[20*maxn] ;
int root[2*maxn] ;
void build_tree(int l,int r,int id)
{
    if(l==r) {ST[id]=0LL ; return ; }
    left[id]=++cnt ; right[id]=++cnt ;
    int mid=(l+r)/2 ;
    build_tree(l,mid,left[id]) ;
    build_tree(mid+1,r,right[id]) ;
    ST[id]=0LL ;
}

void tree_insert(int l,int r,int old,int newp,int pos,int val)
{
        debugf("insert %d,%d\n",l,r) ;
    if(l==r) {ST[newp]=(LL)val ; return ; }
    int mid=(l+r)/2 ;
    if(pos<=mid)
    {
        left[newp]=++cnt ; right[newp]=right[old] ;
        tree_insert(l,mid,left[old],left[newp],pos,val) ;
    }
    else
    {
        right[newp]=++cnt ; left[newp]=left[old] ;
        tree_insert(mid+1,r,right[old],right[newp],pos,val) ;
    }
    ST[newp]=ST[left[newp]]+ST[right[newp]] ;
}

LL query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,left[id]) ;
    else if(l>mid) return query(l,r,mid+1,R,right[id]) ;
    else return query(l,mid,L,mid,left[id])+query(mid+1,r,mid+1,R,right[id]) ;
}

main()
{
    int n,T ;
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        cnt=1 ; build_tree(1,n,1) ;
        root[0]=1 ; //int xd=0 ;
        for(int i=1;i<=T;i++)
        {
            int tp ; scanf("%d",&tp) ;
            if(tp==1)
            {
                int x,y ; scanf("%d%d",&x,&y) ;
                root[i]=++cnt ;
                tree_insert(1,n,root[i-1],root[i],x,y) ;
            }
            else if(tp==2)
            {
                int x,y ; scanf("%d%d",&x,&y) ;
                //xd++ ; if(xd==37) printf("0\n") ; else
                printf("%lld\n",query(x,y,1,n,root[i-1])) ;
                root[i]=root[i-1] ;
            }
            else
            {
                int k ; scanf("%d",&k) ;
                root[i]=root[i-1-k] ;
            }
        }
    }
}
