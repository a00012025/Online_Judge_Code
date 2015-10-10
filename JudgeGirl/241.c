#include<stdio.h>
int cross(int x,int y,int z,int u){return x*u-y*z ;}
main()
{
    int a,b,c,d,e,f,g,h ; scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h) ;
    printf("%d\n",(cross(a,b,c,d)>0)&&(cross(c,d,e,f)>0)&&(cross(e,f,g,h)>0)&&(cross(g,h,a,b)>0)) ;
}
