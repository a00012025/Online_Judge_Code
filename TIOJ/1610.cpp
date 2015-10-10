#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=20000+10 ;

int w[maxn],l[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) ;
    for(int i=1;i<n;i++) scanf("%d",&l[i]) ;
    sort(w+1,w+n+1) ;
    sort(l+1,l+n,greater<int>()) ;
    LL ans=0LL , s=0LL ;
    for(int i=1;i<n;i++)
    {
        s+=w[i] ;
        ans+=s*l[i] ;
    }
    printf("%lld\n",ans) ;
}
