#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int> v[1000] ;
double x[1000],y[1000],dis2[800][800],key[1000] ;
bool vis[1000] ;
int cnt,id[1000] ;

double dis(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])) ;
}

void dfs(int n)
{
    id[n]=cnt ;
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++)
        if(!vis[v[n][i]]) dfs(v[n][i]) ;
}

double prim()
{
    double ans=0 ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=cnt;i++) key[i]=200000000 ;
    int last=1 , id ; vis[1]=1 ;
    double val ;

    for(int i=2;i<=cnt;i++)
    {
        val=200000000 ;
        for(int j=1;j<=cnt;j++)
        {
            if(vis[j]) continue ;
            key[j]=min(key[j],dis2[last][j]) ;
            if(key[j]<val) {val=key[j] ; id=j ;}
        }
        vis[id]=1 ; ans+=val ;
        last=id ;
    }
    return ans ;
}

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%lf %lf",&x[i],&y[i]);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int a,b ;
            scanf("%d%d",&a,&b);
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        memset(vis,0,sizeof(vis)) ;
        cnt=0 ;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue ;
            cnt++ ;
            dfs(i) ;
        }
            //for(int i=1;i<=n;i++) printf("%d,",id[i]);
            //printf("\n");
        for(int i=1;i<=cnt;i++) for(int j=1;j<=cnt;j++)
            {dis2[i][j]=200000000 ; dis2[i][i]=0 ;}
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        {
            if(id[i]==id[j]) continue ;
            dis2[id[i]][id[j]]=min(dis2[id[i]][id[j]],dis(i,j)) ;
            dis2[id[j]][id[i]]=min(dis2[id[j]][id[i]],dis(i,j)) ;
        }
            //for(int i=1;i<=cnt;i++) for(int j=i+1;j<=cnt;j++)
                //printf("%lf\n",dis2[i][j]);
        printf("%.2lf\n",prim()) ;
    }
}
