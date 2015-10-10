#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000001],b[1000001],ST[5000005] ;

void buildtree(int l,int r,int id)
{
    if(l==r) {ST[id]=b[l+1]-b[l] ; return ;}
    int mid=(l+r)/2 ;
    buildtree(l,mid,2*id) ;
    buildtree(mid+1,r,2*id+1) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l>r) return 0 ;
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return
        max(query(l,mid,L,mid,2*id),query(mid+1,r,mid+1,R,2*id+1));
}

main()
{
    int n,Q ;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&Q) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt=0 ; a[0]=a[1]-1 ;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i-1])
            {
                cnt++ ;
                b[cnt]=i ;
            }
        }
        b[cnt+1]=n+1 ;
        buildtree(1,cnt,1) ;
        while(Q--)
        {
            int l,r ;
            scanf("%d %d",&l,&r) ;
            int id1=lower_bound(b+1,b+cnt+2,l) - b ;
            int id2=upper_bound(b+1,b+cnt+2,r) - b ;
            int id3=upper_bound(b+1,b+cnt+2,l) - b ;
            int ans ;
                //printf("%d,%d,%d\n",id1,id2,id3);
            if(id2==id3) ans=r-l+1 ;
            else
            {
                ans=query(id1,id2-2,1,cnt,1) ;
                if(b[id1]-1<=r)ans=max(ans,b[id1]-l) ;
                if(b[id2-1]>=l)ans=max(ans,r-b[id2-1]+1) ;
            }
            printf("%d\n",ans) ;
                //printf("%d , %d\n",b[id1]-l,r-b[id2-1]+1) ;
        }
    }
}
