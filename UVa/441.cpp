#include<stdio.h>
int a[15],n,ans[15];
void dfs(int m,int e)
    {
    int j;
    if (e==6)
        {
        printf("%d",a[ans[1]]);
        for(j=2;j<=6;j++) printf(" %d",a[ans[j]]);
        printf("\n");
        }
    else for(j=m+1;j<=n;j++)
            {
            ans[e+1]=j;
            dfs(j,e+1);
            }
        }
main()
{
 int i,z=0;
 while(scanf("%d",&n)==1)
 {
 if(n==0) break;
 if(z==1) printf("\n");
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 dfs(0,0);
 z=1;
 }
}
