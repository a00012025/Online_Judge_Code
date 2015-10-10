#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    LL x,y=0LL ; scanf("%I64d",&x) ;
    LL p=1LL ;
    while(x)
    {
        int t=x%10 ;
        if(x<10 && t!=9 && 9-t<t) t=9-t ;
        else if(x>=10 && 9-t<t) t=9-t ;
        y+=p*t ; p*=10 ;
        x/=10 ;
    }
    printf("%I64d\n",y) ;
}
