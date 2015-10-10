#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int now[16],goal[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0} ;
int d[16][16] ;

void init()
{
    for(int x1=0;x1<4;x1++) for(int y1=0;y1<4;y1++)
        for(int x2=0;x2<4;x2++) for(int y2=0;y2<4;y2++)
        {
            int z1=4*x1+y1 , z2=4*x2+y2 ;
            d[z1][z2]= ((x1>x2) ? (x1-x2) : (x2-x1)) ;
            d[z1][z2]+= ((y1>y2) ? (y1-y2) : (y2-y1)) ;
        }
}

int estimate()
{
    int ret=0 ;
    for(int i=0;i<16;i++)
    {
        int x,y ;
        for(x=0;now[x]!=i;x++) ;
        y=((i==0) ? 15 : (i-1)) ;
        ret+=d[x][y] ;
    }
    return ret/2 ;
}
bool iddfs(int num,int depth)
{
    int e=estimate() ;
    if(e==0) return 1;
    if(num==depth) return 0;
    if(num+e>depth) return 0;
    for(int z=0;z<16;z++) if(!now[z])
    {
        int x=z/4 , y=z%4 ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0||nx>3||ny<0||ny>3) continue ;
            int nz=4*x+y ;
            now[z]=now[nz] ; now[nz]=0 ; if(iddfs(num+1,depth)) return 1 ;
            now[nz]=now[z] ; now[z]=0 ;
        }
        break ;
    }
    return 0;
}

main()
{
    int T;
    scanf("%d",&T) ;
    init() ;
    while(T--)
    {
        for(int i=0;i<16;i++) scanf("%d",&now[i]) ;
        printf("%d\n",estimate()) ;
        system("pause") ;
        int depth ;
        for(depth=0;depth<=81;depth++)
        {
            printf("%d\n",depth) ;
            if(iddfs(0,depth)) break ;
        }
        if(depth==82) printf("This puzzle is not solvable.\n") ;
        else printf("%d\n",depth) ;
    }
}
