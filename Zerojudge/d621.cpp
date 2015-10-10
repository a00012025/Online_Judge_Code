#include<stdio.h>
#include<string.h>
int a[500],plus,n,ans;
void dfs(int now,int k)
{
 int m=0,i;
 if(now==n)
    {
    ans=1;
    printf("1 ");
    for(i=1;i<=k-1;i++)
        {
        if(a[i]>0)printf("+ %d ",a[i]);
        else printf("* 2 ");
        }
    printf("\n");
    }
 if(now+plus<=n)
    {
    a[k]=plus;
    plus=plus+1;
    dfs(now+plus-1,k+1);
    plus=plus-1;
    }
 if(now*2<=n)
    {
    a[k]=-1;
    dfs(now*2,k+1);
    }
}
main()
{
 while(scanf("%d",&n)==1)
    {
    if(n==0) break;
    memset(a,0,sizeof(a));
    ans=0;
    plus=2;
    dfs(1,1);
    if(ans==0)printf("cheat!\n");
    }
}
