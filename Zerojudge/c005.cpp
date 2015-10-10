#include <stdio.h>
main()
{
int n,m,i,j ;
long long int a,b,c ;
long long int x[20] ;
while (scanf ("%d",&n)==1)
{
for (i=0 ; i<n ; i++)
  {
    scanf ("%d",&m) ;
    x[i]=0 ;
    for (j=1 ; j<=m ; j++)
      {
      scanf ("%lld %lld %lld",&a,&b,&c) ;
      x[i]+=a*c ;
      }
  }
for (i=0 ; i<n ; i++) printf ("%lld\n",x[i]) ;
}


}
