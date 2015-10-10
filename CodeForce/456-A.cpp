#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

pii a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
    sort(a,a+n) ;
    for(int i=0;i<n-1;i++) if(a[i+1].S<a[i].S)
        {printf("Happy Alex\n") ; return 0 ;}
    printf("Poor Alex\n") ;
}
