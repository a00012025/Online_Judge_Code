#include <stdio.h>
#include <string.h>
int a[1001][3000];
main()
{
 int n,i,j,k ;
 memset(a,0,sizeof(a));
 a[0][0]=1 ;
 for(n=1;n<=1000;n++)
 {
    for(i=0;i<=2999;i++) a[n][i]=a[n-1][i] ;
    for (j=2998;a[n][j]==0;j--) ;
    for (k=j;k>=0;k--) a[n][k]=n*a[n][k] ;
    for (k=0;k<=j+4;k++)
        {
        if (a[n][k]>=10)
            {
            a[n][k+1]+=a[n][k]/10 ;
            a[n][k]-=a[n][k]/10*10 ;
            }
        }
 }
 while(scanf("%d",&n)==1)
    {
    printf ("%d!\n",n) ;
    for (j=2998;a[n][j]==0;j--);
    for (k=j;k>=0;k--) printf ("%d",a[n][k]) ;
    printf ("\n") ;
    }
}
