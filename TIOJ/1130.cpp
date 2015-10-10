#include<bits/stdc++.h>
using namespace std;
const int maxn=30000+10 ;

multiset<int> s1,s2 ;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int s=0 ;
        s1.clear() ; s2.clear() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            s1.insert(x) ;
            s2.insert(y) ;
            s+= x>y ? y-x+n : y-x ;
        }
        while(!s1.empty())
        {
            int x=*s1.begin() ; s1.erase(s1.find(x)) ;
            auto it=s2.lower_bound(x) ;
            if(it==s2.end()) it=s2.begin() ;
            s-= x>*it ? *it-x+n : *it-x ;
            s2.erase(it) ;
        }
        printf("%d\n",s) ;
    }
}
