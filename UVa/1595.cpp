#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii ;
set<pii> s ;
pii p[2000] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        s.clear() ;
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i].first,&p[i].second) ;
            if(!s.count(p[i]))s.insert(p[i]) ;
        }
        sort(p+1,p+n+1) ;
        int r=p[1].first+p[n].first ;
        bool yes=1 ;
        for(int i=1;i<=n;i++) if(!s.count(make_pair(r-p[i].first,p[i].second)))
            yes=0 ;
        if(yes) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
