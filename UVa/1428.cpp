#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int a[20001],left[20001],right[20001] ;
set<int>s ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        s.clear() ; s.insert(a[1]) ; left[1]=0 ;
        for(int i=2;i<=n;i++)
        {
            left[i]=lower_bound(s.begin(),s.end(),a[i])-s.begin() ;
            s.insert(a[i]) ;
        }
        for(int i=1;i<=n;i++) printf("%d,",left[i]) ;
        printf("\n") ;

    }
}
