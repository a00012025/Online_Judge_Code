#include <stdio.h>
main()
{
int a ;
while (scanf ("%d",&a)==1)
{
if ((a%2)==0) printf ("%d\n",a) ;
else if ((a%2)==1) printf ("%d\n",a-1) ;
}
}
