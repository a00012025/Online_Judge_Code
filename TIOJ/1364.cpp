#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int a[maxn] ;

main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sort(a+1,a+n+1) ;
        printf("%d\n",a[n+1-k]) ;
    }
}
