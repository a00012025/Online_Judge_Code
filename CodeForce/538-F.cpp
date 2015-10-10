#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int a[maxn],ans[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;)
        {
            int q=(i-1)/j ;
            int j2= (q==0?n-1:(i-1)/q) ;
            if(a[q]>a[i]) ans[j]++ , ans[j2+1]-- ;
            j=j2+1 ;
        }
    }

    for(int i=1,s=0;i<n;i++)
        printf("%d%c",s+ans[i],i==n-1?'\n':' ') ,
        s+=ans[i] ;
}
