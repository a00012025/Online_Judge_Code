#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

vector<int> v[maxn] ;
int m,k,gp[maxn],ans[maxn] ;
void solve()
{
    int mi=maxn , ma=0 ;
    for(int i=1;i<=m;i++)
    {
        mi=min(mi,gp[i]) ; ma=max(ma,gp[i]) ;
        v[gp[i]].push_back(i) ;
    }
    for(int i=mi,newm=ma+1;i<=ma;i++)
    {
        for(int j=0;j<v[i].size();j++)
            gp[v[i][j]]=newm+j%k , ans[v[i][j]]=j%k+1 ;
        for(auto j : v[i]) newm=max(newm,gp[j]) ;
        newm++ ;
    }
    for(int i=1;i<=m;i++) printf("%d%c",ans[i],i==m?'\n':' ') ;
}

main()
{
    int n ; scanf("%d%d%d",&m,&k,&n) ;
    int tmp=m ;
    for(int i=1;i<=n;i++) tmp=(tmp-1)/k+1 ;
    if(tmp>1){printf("-1\n") ; return 0 ;}
    for(int i=1;i<=m;i++) gp[i]=0 ;
    while(n--) solve() ;
}
