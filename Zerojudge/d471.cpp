#include<stdio.h>
int n,a[17];
void dfs(int z)
    {
    int j;
    if(z==n)
        {
        for(j=1;j<=n;j++) printf("%d",a[j]);
        printf("\n");
        }
    else
        {
        a[z+1]=0;
        dfs(z+1);
        a[z+1]=1;
        dfs(z+1);
        }
    }
main()
{
 while(scanf("%d",&n)==1)
    {
    a[0]=0;
    dfs(0);
    }
}
