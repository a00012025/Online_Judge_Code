#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii ;
multiset<pii> s ;
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        s.clear() ;
        bool no=0 ;
        for(int i=1;i<=n;i++)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            if(!no && s.count(make_pair(b,a))) s.erase(s.find(make_pair(b,a))) ;
            else if(!no) s.insert(make_pair(a,b)) ;
            if(n-i<s.size()) no=1 ;
        }
        if(!no && s.empty()) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
