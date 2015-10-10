#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
main()
{
    int n ; scanf("%d",&n) ;
    ULL a=0ULL,ans=0ULL ;
    while(n--)
    {
        ULL x ; scanf("%llu",&x) ;
        ans+=a*x ; a+=x ;
    }
    printf("%llu\n",ans) ;
}
