#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a[511][511],ST1[30010000],ST2[30010000],n ;

LL MAX(LL x,LL b,LL c,LL d)
{
    LL ret=max(x,b) ;
    ret=max(ret,c) ;
    ret=max(ret,d) ;
    return ret;
}

LL MIN(LL x,LL b,LL c,LL d)
{
    LL ret=min(x,b) ;
    ret=min(ret,c) ;
    ret=min(ret,d) ;
    return ret;
}

void buildtree(int x1,int y1,int x2,int y2,int id)
{
    if(x1>x2 || y1>y2)
        {ST1[id]=(-(1LL<<60)) ; ST2[id]=(1LL<<60) ; }
    else if(x1==x2 && y1==y2) {ST1[id]=a[x1][y1] ; ST2[id]=a[x1][y1] ; }
    else
    {
        int mid1=(x1+x2)/2 , mid2=(y1+y2)/2 ;
        buildtree(x1,y1,mid1,mid2,4*id) ;
        if(mid2<y2) buildtree(x1,mid2+1,mid1,y2,4*id+1) ;
        else {ST1[4*id+1]=(-(1LL<<60)) ; ST2[4*id+1]=(1LL<<60) ; }
        if(mid1<x2) buildtree(mid1+1,y1,x2,mid2,4*id+2) ;
        else {ST1[4*id+2]=(-(1LL<<60)) ; ST2[4*id+2]=(1LL<<60) ; }
        if(mid2<y2 && mid1<x2) buildtree(mid1+1,mid2+1,x2,y2,4*id+3) ;
        else {ST1[4*id+3]=(-(1LL<<60)) ; ST2[4*id+3]=(1LL<<60) ; }
        ST1[id]=MAX(ST1[4*id],ST1[4*id+1],ST1[4*id+2],ST1[4*id+3]) ;
        ST2[id]=MIN(ST2[4*id],ST2[4*id+1],ST2[4*id+2],ST2[4*id+3]) ;
    }
        //printf("%I64d , %I64d , %d\n",ST1[id],ST2[id],id) ;
}

LL query1(int x1,int y1,int x2,int y2,int X1,int Y1,int X2,int Y2,int id)
{
        //printf("%d,%d,%d,%d\n",x1,y1,x2,y2);
    if(x1>x2 || y1>y2 || X1>X2 || Y1>Y2) return (-(1LL<<60)) ;
    if(x1==X1 && y1==Y1 && x2==X2 && y2==Y2) return ST1[id] ;
    int mid1=(X1+X2)/2 , mid2=(Y1+Y2)/2 ;
    if(x2<=mid1 && y2<=mid2) return query1(x1,y1,x2,y2,X1,Y1,mid1,mid2,4*id);
    else if(y1>mid2 && x2<=mid1) return query1(x1,y1,x2,y2,X1,mid2+1,mid1,Y2,4*id+1);
    else if(x1>mid1 && y2<=mid2) return query1(x1,y1,x2,y2,mid1+1,Y1,X2,mid2,4*id+2);
    else if(x1>mid1 && y1>mid2) return query1(x1,y1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3);

    else if(x2<=mid1) return max(query1(x1,y1,x2,mid2,X1,Y1,mid1,mid2,4*id),query1(x1,mid2+1,x2,y2,X1,mid2+1,mid1,Y2,4*id+1));
    else if(y2<=mid2) return max(query1(x1,y1,mid1,y2,X1,Y1,mid1,mid2,4*id),query1(mid1+1,y1,x2,y2,mid1+1,Y1,X2,mid2,4*id+2));
    else if(y1>mid2) return max(query1(x1,y1,mid1,y2,X1,mid2+1,mid1,Y2,4*id+1),query1(mid1+1,y1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3));
    else if(x1>mid1) return max(query1(x1,y1,x2,mid2,mid1+1,Y1,X2,mid2,4*id+2),query1(x1,mid2+1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3));

    else return MAX(query1(x1,y1,mid1,mid2,X1,Y1,mid1,mid2,4*id),query1(x1,mid2+1,mid1,y2,X1,mid2+1,mid1,Y2,4*id+1),
                    query1(mid1+1,y1,x2,mid2,mid1+1,Y1,X2,mid2,4*id+2),query1(mid1+1,mid2+1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3)
                    );
}

LL query2(int x1,int y1,int x2,int y2,int X1,int Y1,int X2,int Y2,int id)
{
    //printf("(%d,%d,%d,%d) , (%d,%d,%d,%d) , %d\n",x1,y1,x2,y2,X1,Y1,X2,Y2,id);
    if(x1>x2 || y1>y2 || X1>X2 || Y1>Y2) return (1LL<<60) ;
    if(x1==X1 && y1==Y1 && x2==X2 && y2==Y2) return ST2[id] ;
    int mid1=(X1+X2)/2 , mid2=(Y1+Y2)/2 ;
        //printf("%d,%d\n",mid1,mid2) ;
        //if(x1==2 && y1==31 && x2==2 && y2==32) system("pause");
    if(x2<=mid1 && y2<=mid2) return query2(x1,y1,x2,y2,X1,Y1,mid1,mid2,4*id);
    else if(y1>mid2 && x2<=mid1) return query2(x1,y1,x2,y2,X1,mid2+1,mid1,Y2,4*id+1);
    else if(x1>mid1 && y2<=mid2) return query2(x1,y1,x2,y2,mid1+1,Y1,X2,mid2,4*id+2);
    else if(x1>mid1 && y1>mid2) return query2(x1,y1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3);

    else if(x2<=mid1) return min(query2(x1,y1,x2,mid2,X1,Y1,mid1,mid2,4*id),query2(x1,mid2+1,x2,y2,X1,mid2+1,mid1,Y2,4*id+1));
    else if(y2<=mid2) return min(query2(x1,y1,mid1,y2,X1,Y1,mid1,mid2,4*id),query2(mid1+1,y1,x2,y2,mid1+1,Y1,X2,mid2,4*id+2));
    else if(y1>mid2)  return min(query2(x1,y1,mid1,y2,X1,mid2+1,mid1,Y2,4*id+1),query2(mid1+1,y1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3));
    else if(x1>mid1)  return min(query2(x1,y1,x2,mid2,mid1+1,Y1,X2,mid2,4*id+2),query2(x1,mid2+1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3));

    else return MIN(query2(x1,y1,mid1,mid2,X1,Y1,mid1,mid2,4*id),query2(x1,mid2+1,mid1,y2,X1,mid2+1,mid1,Y2,4*id+1),
                    query2(mid1+1,y1,x2,mid2,mid1+1,Y1,X2,mid2,4*id+2),query2(mid1+1,mid2+1,x2,y2,mid1+1,mid2+1,X2,Y2,4*id+3)
                    );
}

void modify(int x,int y,int X1,int Y1,int X2,int Y2,int id,LL val)
{
    if(X1==X2 && Y1==Y2) {ST1[id]=val ; ST2[id]=val ; return ;}
    int mid1=(X1+X2)/2 , mid2=(Y1+Y2)/2;
    if(x<=mid1)
    {
        if(y<=mid2) modify(x,y,X1,Y1,mid1,mid2,4*id,val) ;
        else modify(x,y,X1,mid2+1,mid1,Y2,4*id+1,val) ;
    }
    else
    {
        if(y<=mid2) modify(x,y,mid1+1,Y1,X2,mid2,4*id+2,val) ;
        else modify(x,y,mid1+1,mid2+1,X2,Y2,4*id+3,val) ;
    }
    ST1[id]=MAX(ST1[4*id],ST1[4*id+1],ST1[4*id+2],ST1[4*id+3]) ;
    ST2[id]=MIN(ST2[4*id],ST2[4*id+1],ST2[4*id+2],ST2[4*id+3]) ;
}

main()
{
    int m;
    while(scanf("%d %d",&m,&n)!=EOF){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        scanf("%lld",&a[i][j]) ;
    buildtree(1,1,n,n,1) ;
    int Q,fir=1;
    scanf("%d",&Q);
    while(Q--)
    {
            //printf("%d\n",Q);
        char type ;
        scanf("%c",&type) ;
        while(type!='q' && type!='c') scanf("%c",&type);
        if(type=='q')
        {
            int x1,y1,x2,y2 ;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2) ;
                //printf("%c %d %d %d %d\n",type,x1,y1,x2,y2);
            //if(fir)fir=0 ;
            //else printf("\n");
            printf("%lld %lld\n",query1(x1,y1,x2,y2,1,1,n,n,1),query2(x1,y1,x2,y2,1,1,n,n,1)) ;
            //printf("%I64d\n",query2(x1,y1,x2,y2,1,1,n,n,1)) ;
            //int xd[20]={1,5,22,20,4,19,18,73,17,16,67,65} ;
            //for(int i=0;i<=11;i++)printf("%I64d,",ST2[xd[i]]);
            //printf("\n");

        }
        else
        {
            int x,y,k ;
            scanf("%d %d %lld",&x,&y,&k) ;
            modify(x,y,1,1,n,n,1,k) ;
        }
    }
}
}
