#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
main()
{
 bool x[801][801];
 int m,n,i,a,b,z;
 queue<int> q;
 while(scanf("%d %d",&n,&m)==2)
 {
 while(q.empty()==0) q.pop();
 memset(x,0,sizeof(x));
 for(i=1;i<=m;i++)
    {
    scanf("%d %d",&a,&b);
    x[a][b]=1;
    }
 scanf("%d %d",&a,&b);
 q.push(a);
 while(q.empty()==0)
    {
    z=q.front();
    q.pop();
    for(i=1;i<=n;i++)
        {
        if(x[z][i]==1)
            {
            if(i==b) break;
            q.push(i);
            }
        }
    if(i==b) break;
    }
 if(i==b) printf("Yes!!!\n");
 else printf("No!!!\n");
 }
}
