#include<bits/stdc++.h>
#define LL long long
using namespace std;

multiset<int> s1,s2 ;
multiset<int,greater<int> > d1,d2 ;

main()
{
    int n,m,Q ; scanf("%d%d%d",&m,&n,&Q) ;
    s1.insert(0) ; s1.insert(n) ;
    s2.insert(0) ; s2.insert(m) ;
    d1.insert(n) ; d2.insert(m) ;
    while(Q--)
    {
        char s[6] ; int x ;
        scanf("%s%d",s,&x) ;
        if(s[0]=='H')
        {
            auto it=s1.lower_bound(x) ;
            int x2=*it ; it-- ; int x1=*it ;
            d1.erase(d1.find(x2-x1)) ;
            d1.insert(x2-x) ;
            d1.insert(x-x1) ;
            s1.insert(x) ;
        }
        else
        {
            auto it=s2.lower_bound(x) ;
            int x2=*it ; it-- ; int x1=*it ;
            d2.erase(d2.find(x2-x1)) ;
            d2.insert(x2-x) ;
            d2.insert(x-x1) ;
            s2.insert(x) ;
        }
        printf("%I64d\n",(LL)(*d1.begin())*(*d2.begin())) ;
    }
}
