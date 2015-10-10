#include<bits/stdc++.h>
#define ABS(x) ((x)>0?(x):(-(x)))
using namespace std;
main()
{
    int n ; scanf("%d",&n) ;
    int k=n/2 ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            putchar((ABS(i-k)+ABS(j-k))<=k?'D':'*') ;
        puts("") ;
    }
}
