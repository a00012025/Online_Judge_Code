#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ans[10];
int a[6][6];
void dfs(int m,int n)
    {
    int i;
    if (n==9) 
        {
        for(i=1;i<=9;i++)printf("%d",ans[i]);
        printf("\n");
        }
    else
        {
        for(i=1;i<=5;i++)
            {
            if (a[i][m]==1)
                {
                a[i][m]=0;
                a[m][i]=0;
                ans[n+1]=i;
                dfs(i,n+1);
                a[i][m]=1;
                a[m][i]=1;
                }
            }
        }
    }
main()
{
 ans[1]=1;
 int vis[6][6] ;
 memset(a,0,sizeof(a));
 a[1][2]=1;a[1][3]=1;a[1][5]=1;a[2][1]=1;a[2][5]=1;a[2][3]=1;a[3][1]=1;
 a[3][2]=1;a[3][4]=1;a[3][5]=1;a[4][3]=1;a[4][5]=1;a[5][1]=1;a[5][2]=1;
 a[5][3]=1;a[5][4]=1;
 dfs(1,1);
 system("pause");
}
