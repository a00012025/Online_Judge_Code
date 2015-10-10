#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
set<pii> s ;
bool G[1015][1015] ;
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(G,0,sizeof(G)) ;
        while(n--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            G[x][y]=1 ;
        }
        s.clear() ;
        for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++)
            if(G[i][j])
        {
            if(!G[i][j+1] && !G[i+1][j+2])
                s.insert(mkp(i,j+1)) ;
            if(!G[i+1][j] && !G[i+2][j+1])
                s.insert(mkp(i+1,j)) ;
        }

        int ans=0 ;
        while(!s.empty())
        {
            pii p=*s.begin() ;
            int num=0 , x=p.F , y=p.S ;
            while(s.count(mkp(x,y)))
                num++ , s.erase(mkp(x,y)) ,
                x++ , y++ ;
            ans+=(num+1)/2 ;
        }
        printf("%d\n",ans) ;
    }
}
