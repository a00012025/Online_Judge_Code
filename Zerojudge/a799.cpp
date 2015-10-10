#include<stdio.h>
main()
{
int a;
while(scanf("%d",&a)==1)
{
if (a>=0) printf("%d\n",a);
else printf("%d\n",-a);
}
}

