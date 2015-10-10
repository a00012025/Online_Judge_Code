#include<stdio.h>
int ST[800101],nowl,nowr,ans[100101] ;
void build_tree(int L,int R,int id)
{
    ST[id]=R-L ;
    if(R-L==1) return ;
    int mid=(L+R)/2 ;
    build_tree(L,mid,2*id) ;
    build_tree(mid,R,2*id+1) ;
}
void modify(int l,int r,int L,int R,int id)
{
    if(R-L==1){ST[id]=ans[L] ; return ; }
    int mid=(L+R)/2 ;
    if(mid>=r) modify(l,r,L,mid,2*id) ;
    else if(l>=mid) modify(l,r,mid,R,2*id+1) ;
    else
    {
        modify(l,mid,L,mid,2*id) ;
        modify(mid,r,mid,R,2*id+1);
    }
    ST[id]=ST[2*id]+ST[2*id+1] ;
}
int query(int l,int r,int L,int R,int id)
{
    if(L==l && R==r) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>=mid) return query(l,r,mid,R,2*id+1) ;
    else return query(l,mid,L,mid,2*id)+query(mid,r,mid,R,2*id+1);
}
main()
{
    int n,q,rev=0 ;
    scanf("%d %d",&n,&q) ;
    nowl=0 ; nowr=n ;
    build_tree(0,n,1) ;
    for(int i=0;i<=n;i++) ans[i]=1 ;
    for(int i=1;i<=q;i++)
    {
        int a,b,p;
        scanf("%d",&p) ;
        if(p==1)
        {
            scanf("%d",&p) ;
            p+=nowl ;
            int mid=(nowl+nowr)/2 ;
            if(p<=mid)
            {
                if(!rev)
                {
                    for(int z=p;z<=2*p-nowl-1;z++)
                        ans[z]+=ans[2*p-1-z] ;
                    modify(p,2*p-nowl,0,n,1) ;
                    nowl=p ;
                }
                else
                {
                    p=nowl+nowr-p ;
                    for(int z=p-1;z>=2*p-nowr;z--)
                        ans[z]+=ans[2*p-1-z] ;
                    modify(2*p-nowr,p,0,n,1);
                    nowr=p;
                }
            }
            else
            {
                if(!rev)
                {
                    for(int z=p-1;z>=2*p-nowr;z--)
                        ans[z]+=ans[2*p-1-z] ;
                    modify(2*p-nowr,p,0,n,1) ;
                    nowr=p ;
                }
                else
                {
                    p=nowl+nowr-p ;
                    for(int z=p;z<=2*p-nowl-1;z++)
                        ans[z]+=ans[2*p-1-z] ;
                    modify(p,2*p-nowl,0,n,1) ;
                    nowl=p ;
                }
                rev=!rev ;
            }
        }
        else if(p==2)
        {
            scanf("%d %d",&a,&b) ;
            a=a+nowl ; b=b+nowl ;
            if(rev) {int tem=a ; a=nowl+nowr-b ; b=nowl+nowr-tem ;}
            printf("%d\n",query(a,b,0,n,1)) ;
        }
    }
}
