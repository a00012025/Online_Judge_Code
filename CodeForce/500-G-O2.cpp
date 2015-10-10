#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=200000+10 ;

vector<int> v[maxn] ;
int tin[maxn],tout[maxn],tick ;
int d[maxn],anc[18][maxn] ;
void dfs(int x,int f,int dep)
{
    anc[0][x]=f ; d[x]=dep ;
    tin[x]=tick++ ;
    for(int i=1;i<19;i++)
    {
        anc[i][x]=anc[i-1][anc[i-1][x]] ;
        if(i==18) printf("anc[%d][%d] : %p\n",i,x,&anc[i][x]) ;
    }
    for(auto i : v[x]) if(i!=f)
        dfs(i,x,dep+1) ;
    tout[x]=tick++ ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    printf("d[1] : %p\n",&d[1]) ;
    dfs(1,1,0) ;
    printf("d[1]=%d\n",d[1]) ;
    int Q ; scanf("%d",&Q) ;
}
