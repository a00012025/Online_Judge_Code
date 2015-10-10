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
  printf ("%d 個餅乾，%d 盒巧克力，%d 個蛋糕。\n",a,b+f,c) ;
  }
}
