#include "interactive/23.h"
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y) ;
}

main()
{
    int n,x ; GetN(n) ;
    for(int i=1;i<=n;i++)
    {
        int y ; Get(y) ;
        if(i==1) x=y ;
        else x=gcd(x,y) , Report(x) ;
    }
    Bye() ;
}
