#include<bits/stdc++.h>
using namespace std;

int k ;
int f(int x)
{
    return x==1 ? 1 : (f(x-1)+k-1)%x+1 ;
}

main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d%d",&n,&k) ;
        printf("Case %d: %d\n",++tc,f(n)) ;
    }
}
