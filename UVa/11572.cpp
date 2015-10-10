#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
set<int> s ;
int a[1000001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int l=1,r=2,ans=0 ;
        s.clear() ; s.insert(a[1]) ;
        for(;r<=n;r++)
        {
            ans=max(ans,r-l) ;
            if(!s.count(a[r])) {s.insert(a[r]) ; continue ;}
            for(;a[l]!=a[r];l++) s.erase(a[l]) ;
            l++ ;
        }
        ans=max(ans,r-l) ;
        printf("%d\n",ans) ;
    }
}
