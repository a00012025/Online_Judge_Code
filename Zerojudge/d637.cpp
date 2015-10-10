#include<stdio.h>
#include<string.h>
int max[101];
main()
{
 int n,i,food[10001],full[10001],j;
 while(scanf("%d",&n)==1)
 {
 memset(max,0,sizeof(max));
 for(i=1;i<=n;i++) scanf("%d %d",&food[i],&full[i]);
 for(i=1;i<=n;i++)
    {
    for(j=100;j>=food[i];j--)
        {
        if((max[j-food[i]]!=0)||(j==food[i])) max[j] = max[j-food[i]]+full[i]>max[j] ? max[j-food[i]]+full[i]:max[j];
        }
    }
 printf("%d\n",max[100]);
 }
}
