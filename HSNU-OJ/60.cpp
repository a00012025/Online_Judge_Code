#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    LL n ;
    while(scanf("%lld",&n)!=EOF)
    {
        if(!n){printf("0\n") ; continue ;}
        string s ;
        for(;n;n=(n%2 ? -(n-1)/2 : -n/2))
            s+=(n%2 ? '1' : '0') ;
        reverse(s.begin(),s.end()) ;
        cout << s << endl ;
    }
}
