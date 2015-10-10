#include<stdio.h>
int a[100101],ST[802000] ;

int sgn(int n)
{
    if(n<0) return -1 ;
    if(n>0) return 1 ;
    return 0 ;
}

void build_tree(int l,int r,int id)
{
    if(l==r) {ST[id]=a[l] ; return ;}
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id) ;
    build_tree(mid+1,r,2*id+1) ;
    ST[id]=ST[2*id]*ST[2*id+1] ;
        //printf("ST[%d]=%d\n",id,ST[id]) ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return query(l,mid,L,mid,2*id)*query(mid+1,r,mid+1,R,2*id+1) ;
}

void modify(int L,int R,int id,int x,int y)
{
    if(L==R) {ST[id]=sgn(y) ; return ;}
    int mid=(L+R)/2 ;
    if(x<=mid) modify(L,mid,2*id,x,y) ;
    else if(x>mid) modify(mid+1,R,2*id+1,x,y) ;
    ST[id]=ST[2*id]*ST[2*id+1] ;
}

main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            int b ;
            scanf("%d",&b) ;
            a[i]=sgn(b) ;
        }
        build_tree(1,n,1) ;
        while(k--)
        {
            char s[20] ;
            int x,y ;
            scanf("%s%d%d",s,&x,&y) ;
            if(s[0]=='P')
            {
                int res=query(x,y,1,n,1) ;
                if(res==1) printf("+") ;
                else if(res==-1) printf("-") ;
                else printf("0");
            }
            else modify(1,n,1,x,y) ;
        }
        printf("\n");
    }
}
