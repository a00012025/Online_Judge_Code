#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n)
    {
        LL ans=1LL ;
        for(int i=m;i<m+n-1;i++) ans=ans*(i+1)/(i+1-m) ;
        printf("%lld\n",ans) ;
    }
}
