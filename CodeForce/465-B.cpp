#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) if(a[i])
    {
        int j ;
        for(j=i;j<=n && a[j];j++) ;
        ans+=j-i+1 ;
        i=j-1 ;
    }
    printf("%d\n",max(0,ans-1)) ;
}
