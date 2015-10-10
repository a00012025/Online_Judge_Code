#include<bits/stdc++.h>
using namespace std;
int a[40000] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<n;i++) scanf("%d",&a[i]) ;
    int now=1,ans=0 ;
    while(now<k)
    {
        now=a[now]+now ;
        if(now==k){ans=1 ; break ;}
    }
    if(ans) printf("YES\n") ;
    else printf("NO\n") ;
}
