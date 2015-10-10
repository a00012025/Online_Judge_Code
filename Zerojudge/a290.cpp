#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
main()
{
 int n,m,i,j,a,b,k;
 bool r[801][801];
 vector<int> v[801];
 while(scanf("%d %d",&n,&m)==2)
 {
 memset(r,0,sizeof(r));
 for(i=1;i<=800;i++) v[i].clear();
 for(i=1;i<=800;i++) v[i].push_back(i);
 for(i=1;i<=800;i++) r[i][i]=1;
 for(i=1;i<=m;i++)
    {
    scanf("%d %d",&a,&b);
    if(r[a][b]==1) continue;
    for(j=1;j<=n;j++)
        {
        if(r[j][a]==0)continue;
        for(k=0;k<v[b].size();k++)
            {
            r[j][v[b][k]]=1;
            v[j].push_back(v[b][k]);
            }
        }
    }
 scanf("%d %d",&a,&b);
 if(r[a][b]==1)printf("Yes!!!\n");
 else printf("No!!!\n"); 
 }
}
