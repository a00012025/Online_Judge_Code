#include<stdio.h>
int abs(int x){return x>0?x:-x ;}
int x[20],y[20],cap[20] ;
int ans[20] ;

int better(int x0,int y0,int x1,int y1,int x2,int y2)
{
    int d1=abs(x0-x1)+abs(y0-y1),d2=abs(x0-x2)+abs(y0-y2) ;
    if(d1!=d2) return d2<d1 ;
    if(x1!=x2) return x2<x1 ;
    return y2<y1 ;
}

main()
{
    int n,m ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d%d%d",&x[i],&y[i],&cap[i]) ;
    scanf("%d",&m) ;
    while(m--)
    {
        int x0,y0 ; scanf("%d%d",&x0,&y0) ;
        int x1=100000,y1=100000,id=-1 ;
        for(int i=0;i<n;i++) if(cap[i] && better(x0,y0,x1,y1,x[i],y[i]))
            id=i , x1=x[i] , y1=y[i] ;
        cap[id]-- ; ans[id]++ ;
    }
    for(int i=0;i<n;i++) printf("%d\n",ans[i]) ;
}
