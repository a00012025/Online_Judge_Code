#include<bits/stdc++.h>
using namespace std;

main()
{
    srand(time(NULL)) ;
    int n=20,m=50 ;
    printf("%d\n",m) ;
    for(int i=0;i<m;i++)
    {
        int x=i/3 , y=i%3 ;
        for(int j=0;j<n;j++)
            printf("%c",j==x ? y+'b' : 'a') ;
        printf("\n") ;
    }
}
