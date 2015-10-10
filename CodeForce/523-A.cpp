#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

char a[3][maxn][maxn] ;
main()
{
    int n,m ; scanf("%d%d",&m,&n) ;
    for(int i=0;i<n;i++) scanf("%s",a[0][i]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        a[1][j][i]=a[0][i][j] ;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        a[2][2*i][2*j]=a[2][2*i+1][2*j]
        =a[2][2*i][2*j+1]=a[2][2*i+1][2*j+1]=a[1][i][j] ;
    for(int i=0;i<2*m;i++) printf("%s\n",a[2][i]) ;
}
