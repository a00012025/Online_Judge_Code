#include <stdio.h>
main()
{
    int k,i ;
    double a,b,c,d;
    while (scanf ("%d",&k)==1)
    {
    for (i=1 ; i<=k ; i++) 
      {
        scanf ("%lf %lf %lf %lf",&a,&b,&c,&d) ;
        if ((b!=0)||(d!=0)) printf ("No\n") ;
        else if (a>c) printf (">\n");
        else if (a<c) printf ("<\n") ;
        else if (a==c) printf ("=\n") ;
      }
    }
}
