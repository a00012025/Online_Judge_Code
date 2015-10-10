#include<bits/stdc++.h>
#define LL long long
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=1000000+10 ;

LL a[maxn] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]) , a[i]^=a[i-1] ;
    while(Q--)
    {
        int l,r ; scanf("%d%d",&l,&r) ;
        printf("%lld\n",a[r]^a[l-1]) ;
    }
}
