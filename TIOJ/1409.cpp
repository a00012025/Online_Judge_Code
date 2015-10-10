#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        LL ma=0LL,sum=0LL ;
        for(int i=1;i<=n;i++)
        {
            LL x ;scanf("%lld",&x) ;
            sum+=x ; ma=max(ma,x) ;
        }
        if(sum>2*ma) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
