#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
    if(x<0) return check(-x) ;
    return x ? (x%10==8 || check(x/10)) : 0 ;
}
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;;i++) if(check(n+i))
        {printf("%d\n",i) ; return 0 ;}
}
