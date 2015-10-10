#include<stdio.h>
int gcd(int a,int b)
{
    while(a!=0 && b!=0)
    {
        if(a>b) a=a%b ;
        else b=b%a ;
    }
    if(!a) return b ;
    else return a ;
}
main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
        printf("%lld\n",(long long)a+b-gcd(a,b));
}
