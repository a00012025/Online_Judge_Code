#include<stdio.h>
#include<set>
using namespace std;
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        long long ans=0 ;
        multiset<int> s ;
        for(int i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m) ;
            for(int i=1;i<=m;i++)
            {
                int a;
                scanf("%d",&a) ;
                s.insert(a) ;
            }
            int M,mi ;
            multiset<int>::iterator it ;
            it=s.end() ; it-- ;
            M=(*it) ;
            it=s.begin() ; mi=(*it) ;
            ans+=(long long)M-mi ;
            s.erase(s.find(M)) ; s.erase(s.find(mi)) ;
        }
        printf("%lld\n",ans) ;
    }
}
