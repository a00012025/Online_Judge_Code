#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

bool G[maxn][maxn] ;
main()
{
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    int n=200000,m=1000 ;
    printf("%d\n",n) ;
    while(n--)
    {
        int x=rand()%m , y=rand()%m ;
        while(G[x][y]) x=rand()%m , y=rand()%m ;
        G[x][y]=1 ;
        printf("%d %d\n",x,y) ;
    }
}
