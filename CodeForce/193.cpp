#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[101] ;
int col[101],M=0,ans[101],n ;

bool b_ok(int x)
{
    for(int i=0;i<v[x].size();i++) if(col[v[x][i]]==1) return 0;
    return 1;
}

void dfs(int num,int black)
{
    if(num==n)
    {
        if(black>M)
        {
            M=black ; int cnt=0 ;
            for(int i=1;i<=n;i++) if(col[i]==1) ans[++cnt]=i ;
        }
        return ;
    }
    if(b_ok(num+1))
    {
        col[num+1]=1 ;
        dfs(num+1,black+1) ;
    }
    col[num+1]=-1 ;
    dfs(num+1,black) ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m ;
        scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        for(int i=1;i<=n;i++) col[i]=-1 ;
        M=0 ;
        dfs(0,0) ;
        printf("%d\n",M) ;
        for(int i=1;i<=M;i++) printf("%d%c",ans[i],i==M?'\n':' ') ;
    }
}
