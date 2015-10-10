#include<stdio.h>
#include<string.h>
int a[20000][700];
main()
{
 int n,i,j,k;
 memset(a,0,sizeof(a));
 a[0][0]=1;
 a[1][0]=1;
 for(i=2;i<=19999;i++)
    {
    for(j=699;a[i-1][j]==0;j--);
    for(k=j;k>=0;k--) a[i][k]=a[i-1][k]+a[i-2][k];
    for(k=0;k<=j+3;k++)
        {
        if(a[i][k]>=1000000000)
            {
            a[i][k+1]+=a[i][k]/1000000000;
            a[i][k]=a[i][k]%1000000000;
            }
        }
    }
 while(scanf("%d",&n)==1)
 {
 for(j=699;a[n-1][j]==0;j--);
 printf("%d",a[n-1][j]);
 for(k=j-1;k>=0;k--) 
    {
    if(a[n-1][k]>=100000000)printf("%d",a[n-1][k]);   
    else if(a[n-1][k]>=10000000)printf("0%d",a[n-1][k]);
    else if(a[n-1][k]>=1000000)printf("00%d",a[n-1][k]);
    else if(a[n-1][k]>=100000)printf("000%d",a[n-1][k]);
    else if(a[n-1][k]>=10000)printf("0000%d",a[n-1][k]);   
    else if(a[n-1][k]>=1000)printf("00000%d",a[n-1][k]);
    else if(a[n-1][k]>=100)printf("000000%d",a[n-1][k]);
    else if(a[n-1][k]>=10)printf("0000000%d",a[n-1][k]);
    else printf("00000000%d",a[n-1][k]);
    }
 printf("\n");
 }
}
