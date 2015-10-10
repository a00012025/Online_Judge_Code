#include<bits/stdc++.h>
#define LL long long
using namespace std;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        LL x=0LL,y ;
        while(n--) scanf("%lld",&y) , x^=y ;
        printf("%lld\n",x) ;
    }
}
