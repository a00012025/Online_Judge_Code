#include<bits/stdc++.h>
using namespace std;

int a[300001] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int num=n ;
    for(int i=n;i>=1;i--) if(a[i]==num) num-- ;
    printf("%d\n",num) ;
}
