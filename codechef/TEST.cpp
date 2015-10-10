#include<bits/stdc++.h>
using namespace std;
int a[50000000] ;
main()
{
    int n,ok=0 ;
    while(scanf("%d",&n)!=EOF)
    {
        if(ok || n==42) { ok=1 ; continue ; }
        printf("%d\n",n) ;
    }
}
