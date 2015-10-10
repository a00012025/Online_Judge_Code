#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[100001];
int sum[100001];
main()
{
 int mm,i,m,n,c,d,j;
 while(scanf("%d %d",&n,&m)==2)
 {
 memset(sum,0,sizeof(sum));
 for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    sum[i]=sum[i-1]+a[i];
    }
 for(i=1;i<=m;i++)
    {
    scanf("%d %d",&c,&d);
    printf("%d\n",sum[d]-sum[c-1]);
    }
 }
}
