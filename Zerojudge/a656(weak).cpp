#include<stdio.h>
#include<algorithm>
using namespace std;
int tree[20][500100],sum[20][500100] ;
int a[100001],times,maxnum ;

void build_tree(int l,int r,int id,int deep)
{
    if(l==r) {tree[deep][l]=a[l] ; sum[deep][l]=a[l] ; return ;}
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id,deep+1) ;
    build_tree(mid+1,r,2*id+1,deep+1) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(i==mid+1 || ((j!=r+1)&&(tree[deep+1][j]<tree[deep+1][i])))
            tree[deep][cnt++]=tree[deep+1][j++] ;
        else tree[deep][cnt++]=tree[deep+1][i++] ;
        if(cnt==l+1) sum[deep][l]=tree[deep][l] ;
        else sum[deep][cnt-1]=sum[deep][cnt-2]+tree[deep][cnt-1] ;
    }
}

int query2(int l,int r,int num,int deep)
{
    if(tree[deep][r]<=num) {times+=r-l+1 ; return sum[deep][r] ;}
    if(tree[deep][l]>num) return 0 ;
    int L=l , R=r ;
    while(R-L>1)
    {
        int mid=(L+R)/2 ;
        if(tree[deep][mid]>num) R=mid ;
        else L=mid ;
    }
    times+=L-l+1 ; return sum[deep][L] ;
}

int query(int x,int y,int l,int r,int id,int num,int deep)
{
    if(x==l && y==r) return query2(l,r,num,deep) ;
    int mid=(l+r)/2 ;
    if(y<=mid) return query(x,y,l,mid,2*id,num,deep+1) ;
    else if(x>=mid+1) return query(x,y,mid+1,r,2*id+1,num,deep+1);
    else return query(x,mid,l,mid,2*id,num,deep+1)+
                query(mid+1,y,mid+1,r,2*id+1,num,deep+1) ;
}

int query_num2(int l,int r,int num,int deep)
{
    int lbd , ubd ;
    lbd=lower_bound(tree[deep]+l,tree[deep]+r+1,num)-tree[deep] ;
    ubd=upper_bound(tree[deep]+l,tree[deep]+r+1,num)-tree[deep] ;
    return ubd-lbd ;
}

int query_num(int x,int y,int l,int r,int id,int num,int deep)
{
    if(x==l && y==r) return query_num2(l,r,num,deep) ;
    int mid=(l+r)/2 ;
    if(y<=mid) return query_num(x,y,l,mid,2*id,num,deep+1) ;
    else if(x>=mid+1) return query_num(x,y,mid+1,r,2*id+1,num,deep+1);
    else return query_num(x,mid,l,mid,2*id,num,deep+1)+
                query_num(mid+1,y,mid+1,r,2*id+1,num,deep+1) ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,ANS=0 ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        build_tree(1,n,1,1) ;
        for(int i=1;i<=m;i++)
        {
            int x,y,S ;
            scanf("%d%d%d",&x,&y,&S) ;
            int l=0 , r=n+1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ; times=0 ;
                int val=query(x,y,1,n,1,tree[1][mid],1) ;
                if(val>S) r=mid ;
                else l=mid ;
            }
            times=0 ; int val=0 , cnt=1 ;
            if(r!=1) val=query(x,y,1,n,1,tree[1][r-1],1) ;
            if(r!=n+1)
            {
                int maxnum=query_num(x,y,1,n,1,tree[1][r],1) ;
                while(val<=S && cnt<=maxnum)
                    {val+=tree[1][r] ; times++ ;}
                if(maxnum) times-- ;
            }
            ANS ^= (times+i) ;
                //printf("%d\n",times) ;
                //printf("query = %d\n",query_num(x,y,1,n,1,5,1)) ;
        }
        printf("%d\n",ANS) ;
    }
}

