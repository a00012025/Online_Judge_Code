#include<stdio.h>
#include<string.h>
bool A[10001][10001];
main()
{
 int N,x,y,a,b,g[10001],yes[10001],m,p,q,i,j;
 while(scanf("%d %d %d",&N,&x,&y)==3)
 {
 memset(A,0,sizeof(A));
 for(i=1;i<=x;i++)
    {
    scanf("%d %d",&a,&b);
    A[a][b]=1;
    A[b][a]=1;
    }
 memset(yes,0,sizeof(yes));
 memset(g,0,sizeof(g));
 g[1]=1;yes[1]=1;
 for(i=2;i<=N;i++)
    {
    if(A[1][i]==0) continue;
    else {  g[i]=1;
            yes[i]=1;//g[2]=1,yes[2]=1
            }
    }
 m=1;
 while(1)
    {
    m+=1;//m=3
    for(i=1;yes[i]==1;i++);//i=5
    if(i==N+1) break;
    for(j=1;j<=N;j++)
        {
        if(A[i][j]==0) continue;
        if(g[j]!=0) 
            {
            g[i]=g[j];
            yes[i]=1;//yes[5]=1
            break;
            }
        }
    if(g[i]!=0) 
        {
        m=m-1;
        continue;
        }
    g[i]=m;//g[3]=2
    yes[i]=1;  //yes[3]=1 , i=3
    for(j=1;j<=N;j++)
        {
        if(A[i][j]==0) continue;
        g[j]=m; //g[4]=2
        yes[j]=1;//yes[4]=1
        }
    
    for(i=1;yes[i]==1;i++);
    if(i==N+1) break;
    }
 for(i=1;i<=y;i++)
    {
    scanf("%d %d",&p,&q);
    if(g[p]==g[q]) printf(":)\n");
    else printf(":(\n");
    }
 }
}
