#include<stdio.h>
int s[100000000];
main()
{
 int n,nn,a,M,z,i,j;
 while(scanf("%d",&n)==1)
 {
 for(nn=1;nn<=n;nn++)
 {
 scanf("%d",&a);
 for(i=1;i<=a;i++) scanf("%d",&s[i]) ;
 M=s[2]-s[1];
 z=1;
 for(j=2;j<=a-1;j++)
    {
    if (s[j+1]-s[j]>M)
        {
        z=j;
        M=s[j+1]-s[j];
        }
    }
 printf("%d\n",z);
 }
 }
}
