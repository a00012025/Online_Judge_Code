#include<stdio.h>
int i,m,ans[20];
void dfs(int z)
    {
    int j;
    if(z==i)
        {
        printf("{");
        printf("%d",ans[1]);
        for(j=2;j<=z;j++) printf(",%d",ans[j]);
        printf("}\n");
        }
    for(j=ans[z]+1;j<=m;j++)
        {
        ans[z+1]=j;
        dfs(z+1);
        }
    }
main()
{
 int n,nn;
 while(scanf("%d",&n)==1)
 {
 for(nn=1;nn<=n;nn++)
 {
 scanf("%d",&m);
 printf("{0}\n");
 for(i=1;i<=m;i++) printf("{%d}\n",i);
 ans[0]=0;
 for(i=2;i<=m;i++)
    {
    dfs(0);
    }
 }
 }
}
