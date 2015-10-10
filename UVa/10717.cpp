#include<stdio.h>
#include<string.h>
int n,a[51] ;
bool ok(int x)
{
    int num=0 ;
    for(int i=1;i<=n;i++) if(x%a[i]==0) num++ ;
    if(num>=4) return 1;
    else return 0;
}
main()
{
    int m ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=m;i++)
        {
            int x,ans1,ans2;
            scanf("%d",&x) ;
            for(ans1=x;!ok(ans1);ans1--) ;
            for(ans2=x;!ok(ans2);ans2++) ;
            printf("%d %d\n",ans1,ans2) ;
        }
    }
}
