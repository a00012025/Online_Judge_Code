#include<bits/stdc++.h>
#define F first
#define S second
#define LL long long
using namespace std;

map<int,int> mp ;
main()
{
    int n,x ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&x) , mp[x]++ ;
    if(mp.size()==1) printf("0 %I64d\n",(LL)n*(n-1)/2) ;
    else
    {
        auto i=mp.begin() ;
        auto j=mp.rbegin() ;
        printf("%d %I64d\n",j->F-i->F,(LL)i->S*j->S) ;
    }
}
