#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;
typedef struct {int id ; LL h ; } P ;

bool comp(P x,P y)
{
    return x.h<y.h ;
}

LL a[100001],ST[1600008],val[100101] ;
int tree_id[100101],data[1600008],len[100102] ;
int anc[100101],n ;
P p[100101] ;

void build_tree(int l,int r,int id)
{
    ST[id]=0 ; data[id]=l ;
    if(l==r) {len[l]=0 ; return ; }
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id) ;
    build_tree(mid+1,r,2*id+1) ;
}

void modify(int L,int R,int x,int y,int id)
{
    if(L==R) {ST[id]=y ; len[L]=max(y,len[L]) ; return ;}
    int mid=(L+R)/2 ;
    if(x>mid) modify(mid+1,R,x,y,2*id+1) ;
    else modify(L,mid,x,y,2*id) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
    if(len[data[2*id]]>len[data[id]]) data[id]=data[2*id] ;
    if(len[data[2*id+1]]>len[data[id]]) data[id]=data[2*id+1] ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l>r) return 0 ;
    if(L==l && R==r) return ST[id] ;
    int mid=(L+R)/2 ;
    if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else if(r<=mid) return query(l,r,L,mid,2*id) ;
    else
    return max(query(mid+1,r,mid+1,R,2*id+1),query(l,mid,L,mid,2*id)) ;
}

int query_id(int l,int r,int L,int R,int id)
{
    if(l>r) return (n+1) ;
    if(l==L && r==R) return data[id] ;
    int mid=(L+R)/2 ;
    if(l>mid) return query_id(l,r,mid+1,R,2*id+1) ;
    else if(r<=mid) return query_id(l,r,L,mid,2*id) ;
    else
    {
        int a=query_id(l,mid,L,mid,2*id) ;
        int b=query_id(mid+1,r,mid+1,R,2*id+1) ;
        return (len[a]>len[b] ? a : b) ;
    }
}

main()
{
    int d ;
    scanf("%d %d",&n,&d) ;
    for(int i=1;i<=n;i++) {scanf("%I64d",&a[i]) ; p[i]=(P){i,a[i]} ;}
    build_tree(1,n,1) ; len[n+1]=0 ;
    sort(p+1,p+n+1,comp) ;
    for(int i=1;i<=n;i++)
    {
        tree_id[p[i].id]=i ;
        val[i]=p[i].h ;
    }
    for(int i=n;i>=1;i--)
    {
        int id1=upper_bound(val+1,val+n+1,a[i]-d)-val ;
        int id2=lower_bound(val+1,val+n+1,a[i]+d)-val ;
        int newval=max(query(1,id1-1,1,n,1),query(id2,n,1,n,1))+1 ;
        int x=query_id(1,id1-1,1,n,1) ;
        int y=query_id(id2,n,1,n,1) ;
        if(len[x]==0 && len[y]==0) anc[i]=i ;
        else anc[i]=(len[x]>len[y] ? p[x].id : p[y].id) ;
            //printf("%d,%d,%d\n",x,y,anc[i]) ;
        modify(1,n,tree_id[i],newval,1) ;
            //printf("modify %d as %d\n",tree_id[i],newval) ;
    }
    int ans=query(1,n,1,n,1) ;
    printf("%d\n",ans) ;
    int now=p[query_id(1,n,1,n,1)].id ;
    for(;anc[now]!=now;now=anc[now]) printf("%d ",now) ;
    printf("%d\n",now) ;
}
