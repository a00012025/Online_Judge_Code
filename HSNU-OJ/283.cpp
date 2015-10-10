#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
int ri[maxn][maxn],dn[maxn][maxn] ; /// 1 : not equal
int ans[maxn][maxn] ;
char s[maxn] ;
main()
{
    int n,m,k,num=0 ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1) ;
        for(int j=1;j<m;j++) if(s[j]=='N')
            num++ , ri[i][j]=1 ;
        if(i==n) break ;
        scanf("%s",s+1) ;
        for(int j=1;j<=n;j++) if(s[j]=='N')
            num++ , dn[i][j]=1 ;
    }
    if(k==1)
    {
        if(2*n*m-m-n<=4*num){printf("NO\n") ; return 0 ;}
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            printf("1%c",j==m?'\n':' ') ;
        return 0 ;
    }
    printf("YES\n") ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        if(i==1)
        {
            ans[i][j]=ans[i][j-1]^ri[i][j-1] ;
            continue ;
        }
        if(j==1 || j==m)
        {
            ans[i][j]=ans[i-1][j]^dn[i-1][j] ;
            continue ;
        }
        int x=ans[i][j-1]^ri[i][j-1],y=ans[i-1][j]^dn[i-1][j] ;
        int z=ans[i-1][j+1]^dn[i-1][j+1]^ri[i][j] ;
        if(x==y || x==z) ans[i][j]=x ;
        else ans[i][j]=y ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        printf("%d%c",ans[i][j]+1,j==m?'\n':' ') ;
}
