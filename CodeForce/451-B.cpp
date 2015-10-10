#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int a[maxn],b[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , b[i]=a[i] ;
    sort(b+1,b+n+1) ;
    int x,y ;
    for(x=1;x<=n && a[x]==b[x];x++) ;
    for(y=n;y>=1 && a[y]==b[y];y--) ;
    if(x==n+1){printf("yes\n1 1\n") ; return 0 ;}
    for(int i=x;i<y;i++) if(a[i+1]>a[i]){printf("no\n") ; return 0 ;}
    printf("yes\n%d %d\n",x,y) ;
}
