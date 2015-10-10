#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b ; scanf("%d%d",&a,&b) ;
    int n=a+b+1 ;
    for(int i=1;i<=a;i++) printf("%d ",i) ;
    if(!b) printf("%d\n",n) ;
    else printf("%d ",n) ;
    for(int i=n-1;i>a;i--) printf("%d%c",i,i==a?'\n':' ') ;
}
