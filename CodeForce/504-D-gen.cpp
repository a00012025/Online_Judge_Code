#include<bits/stdc++.h>
using namespace std;

main()
{
    srand(time(NULL)) ;
    freopen("in","w",stdout) ;
    int n=2000 ; printf("%d\n",n) ;
    while(n--)
    {
        printf("%d",rand()%9+1) ;
        for(int i=1;i<600;i++) printf("%d",rand()%10) ;
        printf("\n") ;
    }
}
