#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL f(LL a,LL b)
{
    return b==0 ? 0 : a/b+f(b,a%b) ;
}

main()
{
    LL a,b ; scanf("%I64d%I64d",&a,&b) ;
    printf("%I64d\n",f(a,b)) ;
}
