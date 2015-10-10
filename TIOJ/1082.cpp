#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int a[maxn],b[maxn] ;

main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        int sum=0,val=0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]) ;
            sum+=min(a[i],b[i]) ;
            if(a[i]<=b[i]) val|=1 ;
            if(a[i]>=b[i]) val|=2 ;
        }
        if(n==1)
        {
            if(a[1]&&b[1]) printf("-1\n") ;
            else printf("0\n") ;
            continue ;
        }
        if(val==3) { printf("%d\n",sum) ; continue ; }
        if(val==2) swap(a,b) ;
        int mi=2147483647 ;
        for(int i=1;i<=n;i++) mi= min(mi,b[i]-a[i]) ;
        printf("%d\n",sum+mi) ;
    }
}
