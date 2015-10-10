#include<stdio.h>
int gcd(int x,int y)
{
    while(x!=0 && y!=0)
    {
        if(x>y) x=x%y ;
        else y=y%x ;
    }
    if(!x) return y ;
    else return x ;
}
main()
{
    int a,b,c ;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(gcd(a,b)>1) printf("No\n") ;
        else if(c>=(a*b)-a-b+1) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
