#include<stdio.h>
main()
{
 int n,a,b,i;
 while(scanf("%d",&n)==1)
 {
 if(n==1) printf("1\n");
 else if(n==2) printf("1 1\n");
 else if(n==3) printf("1 1 1\n");
 else
 {
 for(a=1;(a<=46340)&&(a*a<=n);a++);
 a=a-1;
 b=n-a*a;
 for(i=1;i<=b;i++)printf("1 ");
 for(i=1;i<=a;i++)printf("%d ",i);
 for(i=a-1;i>=2;i--)printf("%d ",i);
 printf("1\n");
 }
 }
}
