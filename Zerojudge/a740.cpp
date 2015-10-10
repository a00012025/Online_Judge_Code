#include<stdio.h>
main()
{
 int a,m,i,j;
 while(scanf("%d",&a)==1)
 {
 m=0;
 j=1;
 if(a==1) m=1;
 else if(a>1000000000) printf("%d\n",a);
 else{
 while(a%2==0)
    {
    a=a/2;
    m=m+2;
    }
 while(a!=1)
    {
    for(i=j+2;(a%i)!=0;i=i+2);
    while(a%i==0)
        {
        a=a/i ;
        m=m+i;
        }
    j=i;
    }
 printf("%d\n",m);
 }}
}
