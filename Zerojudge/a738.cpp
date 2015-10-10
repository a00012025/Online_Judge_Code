#include<stdio.h>
main()
{
 int a,b,c;
 while(scanf("%d %d",&a,&b)==2)
 {
 if(b>a)
    {
    c=b;
    b=a;
    a=c;
    }
 while(a%b!=0)
    {
    c=b;
    b=a%b;
    a=c;
    }
 printf("%d\n",b);
 }
}
