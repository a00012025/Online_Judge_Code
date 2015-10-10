#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

bool G[maxn][maxn] ;
main()
{
    int k ; scanf("%d",&k) ;
    if(k%2==0){printf("NO\n") ; return 0 ;}
    printf("YES\n") ;
    if(k==1){printf("2 1\n1 2\n") ; return 0 ;}

    int n=2*(k+2) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        G[i][j]=1 ;
    for(int r=0;r<=k+2;r+=k+2)
    {
        for(int i=2;i<=k;i+=2)
            G[r+i][r+i+1]=G[r+i+1][r+i]=0 ;
        G[r+1][r+k+1]=G[r+k+1][r+1]=0 ;
        G[r+1][r+k+2]=G[r+k+2][r+1]=0 ;
    }
    for(int i=1;i<=k+2;i++) for(int j=k+3;j<=n;j++)
        G[i][j]=G[j][i]=0 ;
    G[1][k+3]=1 ;

    int m=0 ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(G[i][j]) m++ ;
    printf("%d %d\n",n,m) ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(G[i][j]) printf("%d %d\n",i,j) ;

}
