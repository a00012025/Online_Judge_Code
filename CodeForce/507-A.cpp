#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i].first) , a[i].second=i ;
    sort(a+1,a+n+1) ;
    int i ;
    for(i=1;i<=n;i++)
    {
        if(a[i].first>k) break ;
        k-=a[i].first ;
    }
    printf("%d\n",i-1) ;
    for(int j=1;j<i;j++) printf("%d%c",a[j].second,j==i?'\n':' ') ;
}
