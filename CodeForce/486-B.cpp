#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

int a[maxn][maxn],b[maxn][maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        b[i][j]=1 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]) ;
        if(!a[i][j])
        {
            for(int k=1;k<=m;k++) b[i][k]=0 ;
            for(int k=1;k<=n;k++) b[k][j]=0 ;
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j])
    {
        bool ok=0 ;
        for(int k=1;k<=m;k++) if(b[i][k]) ok=1 ;
        for(int k=1;k<=n;k++) if(b[k][j]) ok=1 ;
        if(!ok){printf("NO\n") ; return 0 ;}
    }
    printf("YES\n") ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        printf("%d%c",b[i][j],j==m?'\n':' ') ;
}
