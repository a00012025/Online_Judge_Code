#include<stdio.h>
#include<string.h>
char a[1000101];
int n,ST[5000001] ;

void buildtree(int l,int r,int id)
{
    if(l==r) {ST[id]= (a[l]=='0' ? -1 : 1) ; return ;}
    int mid=(l+r)/2 ;
    buildtree(l,mid,2*id) ;
    buildtree(mid+1,r,2*id+1) ;
    if(ST[2*id]!=ST[2*id+1]) ST[id]=0 ;
    else if(!ST[2*id] && !ST[2*id+1]) ST[id]=0 ;
    else ST[id]=ST[2*id] ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>=mid+1) return query(l,r,mid+1,R,2*id+1) ;
    else
    {
        int p=query(l,mid,L,mid,2*id) ;
        int q=query(mid+1,r,mid+1,R,2*id+1) ;
        if(p!=q) return 0 ;
        else if(!p && !q) return 0;
        else return p ;
    }
}

main()
{
    int tc=0 ;
    while(scanf("%s",a)!=EOF)
    {
        n=strlen(a)-1 ;
        buildtree(0,n,1) ;
        int Q;
        scanf("%d",&Q) ;
        printf("Case %d:\n",++tc) ;
        while(Q--)
        {
            int x,y ;
            scanf("%d %d",&x,&y) ;
            if(x>y) {int tem=x ; x=y ; y=tem ;}
            if(query(x,y,0,n,1)) printf("Yes\n") ;
            else printf("No\n") ;
        }
    }
}
