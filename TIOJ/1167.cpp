#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
int a[maxn] ;
main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF && n+k)
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
        nth_element(a,a+n-k,a+n) ;
        printf("%d\n",a[n-k]) ;
    }
}
