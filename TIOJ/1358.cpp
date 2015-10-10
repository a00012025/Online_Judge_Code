#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
    if(x==1) return 0 ;
    return x-1+f((x+1)/2) ;
}

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF) printf("%d\n",f(n)) ;
}
