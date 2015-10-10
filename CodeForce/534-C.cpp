#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

int a[maxn] ;
main()
{
    int n ; LL A ; scanf("%d%lld",&n,&A) ;
    LL s=0 ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , s+=a[i] ;
    for(int i=1;i<=n;i++)
    {
        LL l=max(1LL,A-s+a[i]) , r=min((LL)a[i],A-n+1) ;
        printf("%lld%c",a[i]-(r-l+1),i==n?'\n':' ') ;
    }
}
