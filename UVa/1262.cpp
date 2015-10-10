#include<bits/stdc++.h>
using namespace std;
char G[2][7][7] ;
vector<char> v[5] ;

void solve(int col,int lev)
{
    if(col==4) {printf("%c",v[4][lev-1]) ; return ; }
    int num=1 ; for(int i=col+1;i<=4;i++) num*=v[i].size() ;
    int fir=(lev-1)/num ; printf("%c",v[col][fir]) ;
    solve(col+1,lev-fir*num) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int k ; scanf("%d",&k) ;
        for(int i=0;i<6;i++) scanf("%s",G[0][i]) ;
        for(int i=0;i<6;i++) scanf("%s",G[1][i]) ;
        int num=1 ;
        for(int i=0;i<5;i++)
        {
            v[i].clear() ;
            for(int x=0;x<6;x++) for(int y=0;y<6;y++)
                if(G[0][x][i]==G[1][y][i])
                v[i].push_back(G[0][x][i]) ;
            sort(v[i].begin(),v[i].end()) ;
            v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin()) ;
            num*=v[i].size() ;
        }
        if(num<k) {printf("NO\n") ; continue ; }
        solve(0,k) ; printf("\n") ;
    }
}
