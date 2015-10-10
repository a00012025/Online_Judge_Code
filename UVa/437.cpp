#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
vector<int> v[1000] ;
int x[1000],y[1000],val[1000],in[1000] ;
LL dp[1000] ;

bool can_place(int p,int q)
{
    if(x[p]<x[q] && y[p]<y[q]) return 1;
    if(x[p]<y[q] && y[p]<x[q]) return 1;
    return 0;
}

main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<=3*n;i++) v[i].clear() ;
        memset(in,0,sizeof(in)) ;
        for(int i=1;i<=n;i++)
        {
            int a,b,c ; scanf("%d%d%d",&a,&b,&c) ;
            x[3*i-2]=a ; y[3*i-2]=b ; val[3*i-2]=c ;
            x[3*i-1]=a ; y[3*i-1]=c ; val[3*i-1]=b ;
            x[3*i]=b ; y[3*i]=c ; val[3*i]=a ;
        }
        for(int i=1;i<=3*n;i++) for(int j=1;j<=3*n;j++)
            if(can_place(i,j)) {v[i].push_back(j) ; in[j]++ ;}

        queue<int> q ;
        LL ans=0LL ;
        for(int i=1;i<=3*n;i++)
        {
            dp[i]=0LL ;
            if(!in[i]) {q.push(i) ; dp[i]=(LL)val[i] ;}
        }
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            ans=max(ans,dp[u]) ;
            for(int i=0;i<v[u].size();i++)
            {
                dp[v[u][i]]=max(dp[v[u][i]],dp[u]+val[v[u][i]]) ;
                in[v[u][i]]-- ; if(in[v[u][i]]==0) q.push(v[u][i]) ;
            }
        }
        printf("Case %d: maximum height = %lld\n",++tc,ans) ;
    }
}
