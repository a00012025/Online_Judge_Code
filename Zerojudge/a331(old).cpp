#include<stdio.h>
int tree[20][500000],a[101001] ;

void build_tree(int l,int r,int id,int deep)
{
    if(l==r) { tree[deep][l]=a[l] ; return ; }
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id,deep+1) ;
    build_tree(mid+1,r,2*id+1,deep+1) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if( i==mid+1 || ( (j!=r+1)&&(tree[deep+1][j]<tree[deep+1][i]) ) )
            tree[deep][cnt++] = tree[deep+1][j++] ;
        else tree[deep][cnt++] = tree[deep+1][i++] ;
    }
}

int query2(int l,int r,int deep,int num)
{
    if(tree[deep][l]>num) return 0 ;
    if(tree[deep][r]<=num) return r-l+1 ;
    int L=l , R=r ;
    while(R-L>1)
    {
        int mid=(R+L)/2 ;
        if(tree[deep][mid]<=num) L=mid ;
        else R=mid ;
    }
    return L-l+1 ;
}

int query(int x,int y,int l,int r,int id,int num,int deep)
{
    if(x==l && y==r) return query2(l,r,deep,num) ;
    int mid=(l+r)/2 ;
    if(x>=mid+1) return query(x,y,mid+1,r,2*id+1,num,deep+1) ;
    else if(y<=mid) return query(x,y,l,mid,2*id,num,deep+1) ;
    else return query(x,mid,l,mid,2*id,num,deep+1)+query(mid+1,y,mid+1,r,2*id+1,num,deep+1);
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        build_tree(1,n,1,1) ;
        for(int i=1;i<=m;i++)
        {
            int x,y,k ;
            scanf("%d%d%d",&x,&y,&k) ;
            int l=1,r=n ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                int pos=query(x,y,1,n,1,tree[1][mid],1) ;
                if(pos>=k) r=mid ;
                else l=mid ;
            }
            if(r==2 && query(x,y,1,n,1,tree[1][1],1)>=k) r=1 ;
            printf("%d\n",tree[1][r]) ;
        }
    }
}
