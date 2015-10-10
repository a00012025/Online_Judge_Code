#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;
struct P{int x,h;}st[maxn];
int h[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x ; scanf("%d",&x) ;
            h[j]= x ? h[j]+1 : 0 ;
        }
        int sz=0 ;
        for(int j=1;j<=m;j++)
        {
            if(!h[j]) { sz=0 ; continue ; }
            while(sz>=2 && st[sz-2].h>=h[j]) sz-- ;
            if(!sz || st[sz-1].h < h[j]) st[sz++]=(P){j,h[j]} ;
            else st[sz-1].h=h[j] ;
            for(int k=0;k<sz;k++) ans=max(ans,(j-st[k].x+1)*st[k].h) ;
        }
    }
    printf("%d\n",ans) ;
}
