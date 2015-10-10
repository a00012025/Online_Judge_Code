#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
typedef struct{int a,b,c ;} tri ;
main()
{
    int T,a[200],i;
    map<tri,int> m ;
    scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        int n,ans=0;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sort(a+1,a+n+1) ;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(a[i]+a[j]>a[k]) ans++ ;
                    for(;k==n || a[k+1]==a[k];k++) ;
                }
                for(;j==n || a[j+1]==a[j];j++) ;
            }
            for(;i==n || a[i+1]==a[i];i++) ;
        }
        printf("Case #%d: %d\n",cnt,ans) ;
    }
}
