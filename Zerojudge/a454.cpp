#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int day[1001],anc[1001],ans[1001];
vector<int> v[1001] ;

void dfs(int n)
{
    for(int i=0;i<v[n].size();i++)
    {
        int t=v[n][i],tem=ans[t] ;
        ans[t]=max(ans[t],ans[n]+day[t]) ;
        if(ans[t]!=tem) dfs(t) ;
    }
}

main()
{
    int T ;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        memset(ans,0,sizeof(ans)) ;
        for(int i=0;i<=n;i++){v[i].clear() ; anc[i]=0 ;}
        for(int i=1;i<=n;i++)
        {
            int m;
            scanf("%d %d",&day[i],&m) ;
            for(int j=1;j<=m;j++)
            {
                int dec;
                scanf("%d",&dec) ;
                v[i].push_back(dec) ;
                anc[dec]++ ;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(anc[i]) continue ;
            ans[i]=day[i] ;
            dfs(i) ;
        }
        int r=0 ;
        for(int i=1;i<=n;i++) r=max(r,ans[i]) ;
        printf("%d\n",r) ;
    }
}
