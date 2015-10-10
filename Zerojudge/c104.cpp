#include<stdio.h>
int c[9][9];
int ans[9],N;
void dfs(int z)
    {
    int j,m,k,M;
    if(z==8)
        {
        M=0;
        for(j=1;j<=8;j++) M+=c[j][ans[j]];
        if(M>=N) N=M;
        }
    else{
    for(j=1;j<=8;j++)
        {
        m=1;
        for(k=1;k<=z;k++)
            {
            if ((j==ans[k])||(z+1+j==k+ans[k])||(z+1-j==k-ans[k]))
                {
                m=0;
                break;
                }
            }
        if(m==1)
            {
            ans[z+1]=j ;
            dfs(z+1);
            }
        }}
    }
main()
{
 int n,nn,i,j;
 while(scanf("%d",&n)==1)
 {
 for(nn=1;nn<=n;nn++)
  {
  N=0;
  for(i=1;i<=8;i++)
    {
    for(j=1;j<=8;j++) scanf("%d",&c[i][j]);
    }
  dfs(0);
  if(N>=10000)printf("%d\n",N);
  else if(N>=1000)printf(" %d\n",N);
  else if(N>=100)printf("  %d\n",N);
  else if(N>=10)printf("   %d\n",N);
  else printf("    %d\n",N);
  }
 }
}
