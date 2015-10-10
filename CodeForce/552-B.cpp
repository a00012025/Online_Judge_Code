#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int n ; scanf("%d",&n) ;
    LL ans=0LL ;
    for(LL i=1,j=1;i<=n;i*=10,j++) ans+=j*(min((LL)n,10*i-1)-i+1) ;
    printf("%I64d\n",ans) ;
}
