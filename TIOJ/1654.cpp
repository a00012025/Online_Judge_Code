#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int d[maxn],fa[maxn] ;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=2;i<=n;i++) scanf("%d",&fa[i]) ;
    int ans=0 ;
    for(int i=n;i>=1;i--)
    {
        if(!d[i]) d[i]=1 ;
        if(i!=1) d[fa[i]]=max(d[fa[i]],d[i]+1) ;
        if(d[i]<=m) ans++ ;
    }
    printf("%d\n",ans) ;
}
