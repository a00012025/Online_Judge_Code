#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[1001] ;
int a[1001],b[1001],in[1001]={0} ;
int len[1001]={0},anc[1001],ANS[1001] ;

void dfs(int n,int lev)
{
    len[n]=lev ;
    for(int i=0;i<v[n].size();i++)
    {
        if(lev+1>len[v[n][i]]) {anc[v[n][i]]=n ; dfs(v[n][i],lev+1) ;}
    }
}

main()
{
    int n=0 ;
    while(1)
    {
        n++ ;
        if(scanf("%d %d",&a[n],&b[n])==EOF) break ;
    }
    n-- ;
    for(int i=0;i<=n;i++) v[i].clear() ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        if(i==j) continue ;
        if(a[i]<a[j] && b[i]>b[j]) {v[i].push_back(j) ; in[j]++ ;}
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]) continue ;
        anc[i]=i ;
        dfs(i,1) ;
    }
    int ans=0,id,cnt=0 ;
    for(int i=1;i<=n;i++) if(len[i]>ans) {ans=len[i] ; id=i ;}
    for(;anc[id]!=id;id=anc[id]) ANS[++cnt]=id ;
    ANS[++cnt]=id ;
    printf("%d\n",ans) ;
    for(int i=cnt;i>=1;i--)printf("%d\n",ANS[i]);
}
