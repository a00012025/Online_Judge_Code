#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
int a[maxn] ;
bool ok[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        fill(ok+1,ok+n+1,1) ; ok[1]=ok[n]=0 ;
        int m=a[1] ;
        for(int i=2;i<n;i++)
        {
            if(m>=a[i]) ok[i]=0 ;
            m=max(m,a[i]) ;
        }
        m=a[n] ;
        for(int i=n-1;i>=2;i--)
        {
            if(m<=a[i]) ok[i]=0 ;
            m=min(m,a[i]) ;
        }
        printf("%d\n",count(ok+1,ok+n+1,1)) ;
    }
}
