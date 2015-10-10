#include<bits/stdc++.h>
#define LL long long
#define DB long double
using namespace std;
const int maxn=100000+10 ;

DB a[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            a[i]=x ;
        }
        sort(a+1,a+n+1) ;
        for(int i=1;i<=n;i++) a[i]/=m ;

        DB s=0LL , sqs=0LL ;
        DB ans=1e60 ;
        for(int i=1;i<=n;i++)
        {
            s+=a[i] ; sqs+=a[i]*a[i] ;
            if(i>=m+1) s-=a[i-m] , sqs-=a[i-m]*a[i-m] ;
            if(i>=m) ans=min(ans,m*sqs-s*s) ;
        }
        double ans2=ans ;
        printf("%.15f\n",ans2) ;
    }
}
