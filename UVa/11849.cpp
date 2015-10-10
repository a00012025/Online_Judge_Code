#include<stdio.h>
#include<set>
using namespace std;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        set<int> s;
        int a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a) ;
            s.insert(a) ;
        }
        int ans=0 ;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a) ;
            if(s.count(a)) ans++ ;
        }
        printf("%d\n",ans) ;
    }
}
