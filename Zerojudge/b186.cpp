#include <stdio.h>
main ()
{
 int a,b,c,d,e,f ;
 while (scanf("%d %d %d",&a,&b,&c)==3)
  {
  d=a/10 ;
  e=c/2 ;
  f=d ;
  if (e<f) f=e ;
  printf ("%d �ӻ氮�A%d �����J�O�A%d �ӳJ�|�C\n",a,b+f,c) ;
  }
}
