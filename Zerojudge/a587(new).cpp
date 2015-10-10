#include<stdio.h>
#include<string.h>
main()
{
 int a[10010];
 int weight[103],cost[103],n,M,m,x,i,j,k;
 while(scanf("%d",&n)==1)
 {
 memset(a,0,sizeof(a)) ;
 for(i=1;i<=n;i++) scanf("%d %d",&weight[i],&cost[i]) ;
 scanf("%d",&M);
 for(j=1;j<=n;j++)
    {
    for(k=M;k>=weight[j];k--)
        {
        if((a[k-weight[j]]!=0)||(k==weight[j]))
            {
            a[k]=a[k-weight[j]]+cost[j]>a[k]?a[k-weight[j]]+cost[j]:a[k];
            }
        }
    }
 m=a[1];
 for(x=1;x<=M;x++)
    {
    if(a[x]>=m) m=a[x];
    }
 printf("%d\n",m);
 }
}
