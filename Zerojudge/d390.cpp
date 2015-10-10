#include<stdio.h>
main()
{
 int a[111],c[50011],nn,n,zz,i,j,ii,M;
 while(scanf("%d",&nn)==1)
 {
 for(zz=1;zz<=nn;zz++)
  {
  scanf("%d",&n);
  M=0;
  for(i=1;i<=n;i++) 
    {
    scanf("%d",&a[i]);
    M+=a[i];                        //a[1]=100,a[2]=2,a[3]=1
    }
  for(i=0;i<=50010;i++) c[i]=0 ;
  c[0]=1;
  for(i=1;i<=n;i++)
    {
    for(j=50010;j>=a[i];j--)
        {
        if(c[j-a[i]]==1)
            {
            c[j]=1;
            }
        }
    }
  for(i=M/2;c[i]==0;i--);
  printf("%d\n",M-2*i);
  }
 }
 
}
