#include<bits/stdc++.h>
#define ABS(x) ((x)>0 ? (x) : (-(x)))
using namespace std;

main()
{
    int a,b,c ; scanf("%d%d%d",&a,&b,&c) ;
    int d=c-ABS(a)-ABS(b) ;
    printf("%s\n",d<0 || d%2 ? "No" : "Yes") ;
}
