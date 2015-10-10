#include<stdio.h>
int a[15],n,ans[15];
void dfs(int m,int e)
    {
    int j;
    if (e==6)
        {
        for(j=1;j<=6;j++) printf("%d ",a[ans[j]]);
        printf("\n");
        }
    else for(j=m+1;j<=n;j++)
            {// m=5 e=5 j=6
            ans[e+1]=j;
            dfs(j,e+1);
            }
        }
    

main()
{
 int i;
 while(scanf("%d",&n)==1)
 {
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 dfs(0,0);
 }
}
