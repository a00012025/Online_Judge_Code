#include<bits/stdc++.h>
#define LL long long
#define SQ(x) (((LL)x)*((LL)x))
using namespace std;
const int maxn=1000+10 ;
int x[maxn],y[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]) ;
    LL ans=0LL ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        ans=max(ans,SQ(x[i]-x[j])) ,
        ans=max(ans,SQ(y[i]-y[j])) ;
    printf("%I64d\n",ans) ;
}
