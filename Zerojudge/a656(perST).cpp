#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=10000+10,maxm=2000000 ;
int left[maxm],right[maxm],root[100010] ;
int cnt,size[maxm] ;
LL sum[maxm] ;

void build_ST(int l,int r,int id)
{
    if(l==r) {size[id]=0 ; sum[id]=0LL ; return ; }
    left[id]=++cnt ; right[id]=++cnt ;
    int mid=(l+r)/2 ;
    build_ST(l,mid,left[id]) ;
    build_ST(mid+1,r,right[id]) ;
    size[id]=0 ; sum[id]=0LL ;
}

void tree_insert(int l,int r,int old,int newp,int pos)
{
    if(l==r) {size[newp]=size[old]+1 ; sum[newp]=sum[old]+(LL)pos ; return ; }
    int mid=(l+r)/2 ;
    if(pos<=mid)
    {
        left[newp]=++cnt ; right[newp]=right[old] ;
        tree_insert(l,mid,left[old],left[newp],pos) ;
    }
    else
    {
        right[newp]=++cnt ; left[newp]=left[old] ;
        tree_insert(mid+1,r,right[old],right[newp],pos) ;
    }
    size[newp]=size[left[newp]]+size[right[newp]] ;
    sum[newp]=sum[left[newp]]+sum[right[newp]] ;
}

int query(int l,int r,int id1,int id2,LL cost)
{
    if(l==r) return l==0 ? (size[id2]-size[id1]) : min((LL)size[id2]-size[id1],cost/l) ;
    int mid=(l+r)/2 ;
    LL lsum=sum[left[id2]]-sum[left[id1]] ;
    if(cost<lsum) return query(l,mid,left[id1],left[id2],cost) ;
    else return size[left[id2]]-size[left[id1]]+query(mid+1,r,right[id1],right[id2],cost-lsum) ;
}

int a[100010] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,q ; scanf("%d%d",&n,&q) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        cnt=0 ;
        root[0]=++cnt ; build_ST(0,maxn,root[0]) ;
        for(int i=1;i<=n;i++)
        {
            root[i]=++cnt ;
            tree_insert(0,maxn,root[i-1],root[i],a[i]) ;
        }
        LL ANS=0LL ;
        for(int i=1;i<=q;i++)
        {
            int L,R ; LL cost ;
            scanf("%d%d%lld",&L,&R,&cost) ;
            int ans=query(0,maxn,root[L-1],root[R],cost) ;
            //printf("%d\n",ans) ;
            ANS ^= (ans+i) ;
        }
        printf("%lld\n",ANS) ;
    }
}
