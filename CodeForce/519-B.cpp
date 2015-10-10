#include<bits/stdc++.h>
using namespace std;

multiset<int> s1,s2 ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        s1.insert(x) ;
    }
    for(int i=1;i<=n-1;i++)
    {
        int x ; scanf("%d",&x) ;
        s1.erase(s1.find(x)) ;
        s2.insert(x) ;
    }
    for(int i=1;i<=n-2;i++)
    {
        int x ; scanf("%d",&x) ;
        s2.erase(s2.find(x)) ;
    }
    printf("%d\n%d\n",*s1.begin(),*s2.begin()) ;
}
