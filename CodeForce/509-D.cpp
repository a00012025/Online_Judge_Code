#include<bits/stdc++.h>
#define MAX 100000000007
#define LL long long
using namespace std;

LL a[200][200] ;
set<LL> st ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        scanf("%I64d",&a[i][j]) ;
    if(n==1)
    {
        printf("YES\n%I64d\n",MAX) ;
        printf("0\n") ;
        for(int i=1;i<=m;i++) printf("%I64d%c",a[1][i],i==m?'\n':' ') ;
        return 0 ;
    }
    if(m==1)
    {
        printf("YES\n%I64d\n",MAX) ;
        for(int i=1;i<=n;i++) printf("%I64d%c",a[i][1],i==n?'\n':' ') ;
        printf("0\n") ;
        return 0 ;
    }

    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        for(int k=1;k<=m;k++) for(int l=k+1;l<=m;l++)
        st.insert(a[i][k]+a[j][l]-a[i][l]-a[j][k]) ;

    LL now=*st.begin() ;
    for(auto i : st) now=__gcd(now,i) ;
    if(now<0) now=-now ;

    if(now)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            if(a[i][j]>=now)
                { printf("NO\n") ; return 0 ; }
    }

    LL ans ;
    if(!now) ans=MAX ;
    else ans=now ;

    printf("YES\n%I64d\n",ans) ;
    for(int i=1;i<=n;i++) printf("%I64d%c",a[i][1],i==n?'\n':' ') ;
    for(int i=1;i<=m;i++)
        printf("%I64d%c",((a[1][i]-a[1][1])%ans+ans)%ans,i==m?'\n':' ') ;
}
