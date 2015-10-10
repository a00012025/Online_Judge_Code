#include <stdio.h>
main ()
{
long long a,b,c,M ;
while (scanf ("%lld %lld %lld",&a,&b,&c)==3)
  {
  M=a ;
  if (b>M) 
  {
  M=b ;
  }
  if (c>M)
  {
  M=c ; 
  } 
  if (M==a)
    {
      if ((b+c>a)&&(b>c)) 
      {
      printf ("B\n") ;
      }
      else if ((b+c>a)&&(c>b))
      {
      printf ("C\n") ;
      }
      else if (a>b+c)
      printf ("A\n") ;
    } 
  else if (M==b)
    {
      if ((a+c>b)&&(a>c))
      {
      printf ("A\n") ;
      }
      else if ((a+c>b)&&(c>a))
      {
      printf ("C\n") ;
      }
      else if (b>a+c)
      {
      printf ("B\n") ;
      }
    }
  else if (M==c)
    {
      if ((b+a>c)&&(b>a))
      {
      printf ("B\n") ;
      }
      else if ((b+a>c)&&(a>b))
      {
      printf ("A\n") ;
      }
      else if (c>b+a)
      {
      printf ("C\n") ;
      }
    } 
}
}
