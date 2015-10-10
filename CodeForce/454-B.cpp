#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
int a[maxn] ;
main()
{
    int n,x=-1 ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) ;
        if(i>1&&a[i]<a[i-1]&&x==-1) x=i ;
    }
    if(x==-1){printf("0\n") ; return 0 ;}
    for(int i=x+1;i<=n;i++) if(a[i]<a[i-1])
        {printf("-1\n") ; return 0 ;}
    printf("%d\n",a[n]<=a[1]?n-x+1:-1) ;
}
