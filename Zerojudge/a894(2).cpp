#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
bool comp(int a,int b)
{
    return a>b ;
}
main()
{
    int T,a[100001];
    set<int> s;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,ans=0;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sort(&a[1],&a[n+1],comp) ;
        s.clear() ;
        for(int i=1;i<=n;i++)
        {
            if(!s.count(2*a[i]))
            {
                s.insert(2*a[i]) ;
                ans++ ;
            }
            else if(!s.count(a[i]))
            {
                s.insert(a[i]) ;
                ans++ ;
            }
        }
        printf("%d\n",ans) ;
    }
}
