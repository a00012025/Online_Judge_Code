#include<bits/stdc++.h>
using namespace std;
const int maxn=500 ;
char G[maxn][maxn],c[10] ;
bool check(int x,int y)
{
    c[0]=G[x][y] ;
    c[1]=G[x+1][y] ;
    c[2]=G[x][y+1] ;
    c[3]=G[x+1][y+1] ;
    sort(c,c+4) ;
    return (c[0]=='a' && c[1]=='c' && c[2]=='e' && c[3]=='f') ;
}
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    int ans=0 ;
    for(int i=0;i<n-1;i++) for(int j=0;j<m-1;j++)
        if(check(i,j)) ans++ ;
    printf("%d\n",ans) ;
}
