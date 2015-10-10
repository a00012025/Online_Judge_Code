#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y) ;
}
main()
{
    int tc=0,T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        printf("Case %d: %d\n",++tc,(a+b)/gcd(a,b)) ;
    }
}
