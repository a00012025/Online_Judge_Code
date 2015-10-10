#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int M,b,ans[40];
bool coprime(int x,int y)
    {
    int i,m=1;
    if((x==1)||(y==1)) return 1 ;
    if(x==y) return 0;
    for(i=2;(i<=x)&&(i<=y);i++)
        {
        if ((x%i==0)&&(y%i==0))
            {
            m=0;
            break;
            }
        }
    return m;
    }
void dfs(int x,int e)
    {
    int j,k,m;
    if(e==b-1)
        {
        j=x;
        m=1;
        if((j<ans[e])||((j==1)&&(ans[e]!=1)))
            {
            m=0;
            }
        else
            {
            for(k=1;k<=e;k++)
                {
                if(coprime(j,ans[k])==0)
                        {
                        m=0;
                        break;
                        }
                }
            }
        if(m==1)
            {
            ans[b]=x;
            for(k=1;k<=b;k++) printf("%d ",ans[k]);
            printf("\n");
            }
        }
    else
        {
        for (j=ans[e];j<=x-1;j++)
            {
            if((j==ans[e])&&(j!=1)) continue;
            m=1;
            for(k=1;k<=e;k++)
                {
                if(coprime(j,ans[k])==0)
                    {
                    m=0;
                    break;
                    }
                }
            if (m==1)
                {
                ans[e+1]=j;
                dfs(x-j,e+1);
                }
            }
        }
    }
main()
{
 int n,nn;
 while(scanf("%d",&n)==1)
 {
 for(nn=1;nn<=n;nn++)
  {
  scanf("%d %d",&M,&b);
  printf("Case %d:\n",nn);
  ans[0]=1;
  dfs(M,0);
  }
 }
}
