#include <stdio.h>
main()
{
 int a,b,c,d ;
 while (scanf ("%d %d %d %d",&a,&b,&c,&d)==4)
 { 
 if ((a==0)&&(b==0)&&(c==0)&&(d==0)) break ;
 else if ((a==c)&&(b==d)) printf ("0\n") ;
 else if ((a==c)||(b==d)) printf ("1\n") ;
 else if ((a-c==b-d)||(a-c==d-b)||(c-a==b-d)||(c-a==d-b)) printf ("1\n") ;
 else printf ("2\n") ; 
 }
 scanf (" ") ; 
}
