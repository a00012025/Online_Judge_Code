#include<bits/stdc++.h>
using namespace std;

main()
{
    freopen("in.txt","w",stdout) ;
    srand(time(NULL)) ;
    int T=100,n=10,m=4 ;
    printf("%d\n",T) ;
    while(T--)
    {
        printf("%d\n",n) ;
        for(int i=1;i<=n;i++) printf("%d%c",rand()%5+1,i==n?'\n':' ') ;
    }
}
