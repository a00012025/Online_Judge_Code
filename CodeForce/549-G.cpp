#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int a[maxn],ans[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , a[i]+=i ;
    sort(a+1,a+n+1) ;
    for(int i=1;i<=n;i++)
    {
        ans[i]=a[i]-i ;
        if(i>1 && ans[i]<ans[i-1]){printf(":(\n") ; return 0 ;}
    }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
