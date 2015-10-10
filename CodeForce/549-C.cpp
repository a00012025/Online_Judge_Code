#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    int x=0 , y=0 ;
    for(int i=1;i<=n;i++)
    {
        int t ; scanf("%d",&t) ;
        if(t%2) x++ ;
        else y++ ;
    }
    if(n==k){printf("%s\n",x%2 ? "Stannis" : "Daenerys") ; return 0 ;}
    int val=n-k ;
    if(val%2 && k%2) printf("%s\n",2*x<val ? "Daenerys" : "Stannis") ;
    else if(val%2) printf("%s\n",(2*x<val || 2*y<val) ? "Daenerys" : "Stannis") ;
    else if(k%2) printf("%s\n",2*y<=val ? "Stannis" : "Daenerys") ;
    else printf("Daenerys\n") ;
}
