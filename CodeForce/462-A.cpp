#include<stdio.h>
main()
{
    int n ;
    char s[101][101] ;
    bool ans=1 ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%s",s[i]) ;
    for(int i=1;i<=n;i++) for(int j=0;j<n;j++)
    {
        int now=0 ;
        if(i>=2 && s[i-1][j]=='o') now++ ;
        if(j>=1 && s[i][j-1]=='o') now++ ;
        if(i<n && s[i+1][j]=='o') now++ ;
        if(j<n-1 && s[i][j+1]=='o') now++ ;
        if(now%2==1) ans=0 ;
    }
    if(ans) printf("YES\n") ;
    else printf("NO\n") ;
}
