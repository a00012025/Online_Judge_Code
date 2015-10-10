#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

int G[maxn][maxn] ;

bool check(int x,int y)
{
    assert((x+y)%2) ;
    if(x==1 || y==1) return 0 ;
    if(x%2) return G[(x-1)/2][y/2]<G[(x+1)/2][y/2] ;
    else return G[x/2][(y-1)/2]<G[x/2][(y+1)/2] ;
}

struct P{int x,h;};

int h[maxn] ;
P st[maxn] ;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        scanf("%d",&G[i][j]) ;
    int ans=0 ;
    for(int i=2;i<=2*n;i++)
    {
        for(int j=1;j<=2*m;j++)
            h[j]=  (((i+j)%2) && !check(i,j)) ? 0 : h[j]+1 ;
        if(i%2) continue ;

        int sz=0 ;
        for(int j=1;j<=2*m;j++)
        {
            while(sz>=2 && st[sz-2].h>=h[j]) sz-- ;
            if(sz && st[sz-1].h > h[j]) st[sz-1].h = h[j] ;
            if(j%2) continue ;
            st[sz++]=(P){j,h[j]} ;
            for(int k=0;k<sz;k++) ans=max(ans,
                ((j-st[k].x+2)/2)*((st[k].h+1)/2)) ;
        }
    }
    printf("%d\n",ans) ;
}
