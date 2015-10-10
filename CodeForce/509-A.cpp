#include<bits/stdc++.h>
using namespace std;
int d[20][20] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) d[i][1]=d[1][i]=1 ;
    for(int i=2;i<=n;i++) for(int j=2;j<=n;j++)
        d[i][j]=d[i-1][j]+d[i][j-1] ;
    printf("%d\n",d[n][n]) ;
}
