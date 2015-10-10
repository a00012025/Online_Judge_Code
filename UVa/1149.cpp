#include<stdio.h>
#include<set>
using namespace std;
multiset<int> s ;
multiset<int>::iterator it ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,M ;
        scanf("%d %d",&n,&M) ;
        s.clear() ;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a) ;
            s.insert(a) ;
        }
        int ans=0 ;
        while(!s.empty())
        {
            ans++ ;
            it=s.end() ; it-- ; int now=*it ;
            s.erase(s.find(now)) ;
            if(s.empty() || (now + *(s.begin()) > M)) continue ;
            it=s.lower_bound(M-now) ;
            if(it==s.end() || *it > M-now) it-- ;
            s.erase(s.find(*it)) ;
        }
        printf("%d\n",ans) ;
        if(T) printf("\n") ;
    }
}
