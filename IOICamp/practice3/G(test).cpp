#include<bits/stdc++.h>
using namespace std;

main()
{
    srand(time(NULL)) ;
    int T=100,n=20,m=7 ;
    freopen("in.txt","w",stdout) ;
    printf("%d\n",T) ;
    for(int i=1;i<=100;i++)
    {
        printf("%d %d\n",n,m) ;
        int sum=0 ;
        for(int i=1;i<n;i++)
        {
            int a=(rand()<<15)+rand() ;
            sum+=(a%m) ; printf("%d\n",a) ;
        }
        while(1)
        {
            int a=(rand()<<15)+rand() ;
            if((sum+a)%m==0) { printf("%d\n",a) ; break ; }
        }
    }
}
