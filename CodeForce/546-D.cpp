#include<bits/stdc++.h>
using namespace std;
const int maxn=5000000+10 ;

bool vis[maxn] ;

int di[maxn],ans[maxn] ;
void cal()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 , di[j]=i ;
    for(int i=2;i<maxn;i++) ans[i]= (vis[i] ? ans[i/di[i]]+1 : 1) ;
    for(int i=2;i<maxn;i++) ans[i]+=ans[i-1] ;
}

main()
{
    cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        printf("%d\n",ans[x]-ans[y]) ;
    }
}
