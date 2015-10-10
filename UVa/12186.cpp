#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100001] ;
int d[100001],t ;

bool cmp(int x,int y)
{
    return d[x]<d[y] ;
}

void dfs(int n)
{
    int sz=v[n].size() ;
    if(!sz) {d[n]=1 ; return ;}
    int c=(t*sz-1)/100+1 ;
    for(int i=0;i<v[n].size();i++) dfs(v[n][i]) ;
    sort(v[n].begin(),v[n].end(),cmp) ;
    d[n]=0 ;
    for(int i=0;i<c;i++) d[n]+=d[v[n][i]] ;
}

main()
{
    int n ;
    while(scanf("%d%d",&n,&t)==2 && n+t)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int a ; scanf("%d",&a) ;
            v[a].push_back(i) ;
        }
        dfs(0) ;
        printf("%d\n",d[0]) ;
    }
}
