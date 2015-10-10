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
    for(j=0;j<v[a].size();j++)
        {
        for(k=1;k<=n;k++)
            {
            if(r[b][k]==0)continue;
            r[v[a][j]][k]=1;
            v[k].push_back(v[a][j]);
            }
        }
    }
 scanf("%d %d",&a,&b);
 if(r[a][b]==1)printf("Yes!!!\n");
 else printf("No!!!\n"); 
 }
}
