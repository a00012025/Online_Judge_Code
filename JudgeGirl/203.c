#include<stdio.h>
#define SWAP(x,y) (x^=y^=x^=y)
int X,Y,x[2],y[2],dx[2],dy[2],T ;
void process(int i)
{
    if((x[i]==1 && dx[i]==-1) || (x[i]==X && dx[i]==1))
        dx[i]=-dx[i] ;
    if((y[i]==1 && dy[i]==-1) || (y[i]==Y && dy[i]==1))
        dy[i]=-dy[i] ;
}
main()
{
    scanf("%d%d%d%d%d%d%d%d%d%d%d",&X,&Y,&x[0],&y[0],&x[1],&y[1],&dx[0],&dy[0],&dx[1],&dy[1],&T) ;
    while(T--)
    {
        if(x[0]==x[1] && y[0]==y[1])
            SWAP(dx[0],dx[1]) , SWAP(dy[0],dy[1]) ;
        for(int i=0;i<2;i++) process(i) ;
        for(int i=0;i<2;i++) x[i]+=dx[i] , y[i]+=dy[i] ;
    }
    for(int i=0;i<2;i++) printf("%d\n%d\n",x[i],y[i]) ;
}
