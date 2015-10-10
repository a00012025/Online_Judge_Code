#include<bits/stdc++.h>
using namespace std;

main()
{
    nth_element(1) ;
    int n ; scanf("%d",&n) ;
    for(int i=0;i*i<=n;i++)
    {
        int x=n-i*i ;
        int j=(int)sqrt(x+0.5) ;
        if(j*j==x) {printf("Yes\n") ; return 0 ;}
    }
    printf("No\n") ;
}
