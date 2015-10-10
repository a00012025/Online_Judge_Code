#include<stdio.h>
#include<stdlib.h>
int ans[28];
int n;
void dfs(int z)
    {
    int i,m=0;
    if(z==2*n)
        {
        for(i=1;i<=z;i++)
            {
            if(ans[i]==1)printf("(");
            else if(ans[i]==2)printf(")");
            }
        printf("\n");
        }
    else 
        {
        for(i=1;i<=z;i++)
            {
            if(ans[i]==1) m+=1;
            }
        if(m==n)
            {
            ans[z+1]=2;
            dfs(z+1);
            }
        else if(m>z-m)
            {
            ans[z+1]=1;
            dfs(z+1);
            ans[z+1]=2;
            dfs(z+1);
            }
        else if(m==z-m)
            {
            ans[z+1]=1;
            dfs(z+1);
            }
        }
    }
main()
{
 while(scanf("%d",&n)==1)
 {
 ans[1]=1;
 dfs(1);
 }
}
