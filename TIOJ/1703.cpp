#include<bits/stdc++.h>
using namespace std;

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0 ;
        while(n) { ans+=n/3 ; n/=3 ; }
        printf("%d\n",ans) ;
    }
}
