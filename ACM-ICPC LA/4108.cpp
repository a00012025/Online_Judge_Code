#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int ST1[1600008],ST2[1600008],data[1600008] ;

void buildtree()
{
    memset(ST1,0,sizeof(ST1)) ;
    memset(ST2,0,sizeof(ST2)) ;
    memset(data,-1,sizeof(data)) ;
}

int modify(int l,int r,int L,int R,int id,int x)
{
    if(data[id]>0)
    {
        int k=data[id] ;
        data[2*id]=k ; data[2*id+1]=k ;
        ST1[2*id]=k ; ST1[2*id+1]=k ;
        ST2[2*id]=k ; ST2[2*id+1]=k ;
        data[id]=-1 ;
    }
    int ret ;
    if(l==L && r==R && ST2[id]<=x) {ST1[id]=x ; ST2[id]=x ; data[id]=x ; ret=R-L+1 ;}
    else if(l==L && r==R && ST1[id]>x) ret=0 ;
    else
    {
        int mid=(L+R)/2 ;
        if(r<=mid) ret = modify(l,r,L,mid,2*id,x) ;
        else if(l>mid) ret = modify(l,r,mid+1,R,2*id+1,x) ;
        else ret = modify(l,mid,L,mid,2*id,x) + modify(mid+1,r,mid+1,R,2*id+1,x) ;
        ST1[id]=min(ST1[2*id],ST1[2*id+1]) ;
        ST2[id]=max(ST2[2*id],ST2[2*id+1]) ;
    }
        //printf("%d,%d,%d,%d , return %d\n",l,r,L,R,ret);
    return ret ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,ans=0 ;
        scanf("%d",&m) ;
        buildtree() ;
        while(m--)
        {
            int a,b,x ;
            scanf("%d %d %d",&a,&b,&x) ;
            ans+=modify(a,b-1,1,100001,1,x) ;
        }
        printf("%d\n",ans) ;
    }
    scanf("%d",&T) ;
}
