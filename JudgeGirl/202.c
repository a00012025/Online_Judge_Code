#include<stdio.h>
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x ;
}
void print(int x,int y)
{
    int g=gcd(x,y) ;
    x/=g ; y/=g ;
    if(x<0&&y<0) x=-x , y=-y ;
    else if(y<0) x=-x , y=-y ;
    if(x<0) printf("%d\n%d\n%d\n",-(-x)/y,-x-(-x)/y*y,y) ;
    else printf("%d\n%d\n%d\n",x/y,x-x/y*y,y) ;
}
main()
{
    int a,b,c,d,e,f,g ; scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g) ;
    b=(a>0 ? a*c+b : a*c-b) ;
    f=(e>0 ? e*g+f : e*g-f) ;
    // b/c , f/g
    if(d==0) print(g*b+c*f,c*g) ;
    if(d==1) print(g*b-c*f,c*g) ;
    if(d==2) print(b*f,c*g) ;
    if(d==3) print(b*g,c*f) ;
}
