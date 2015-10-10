#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    LL r,x1,y1,x2,y2 ; scanf("%I64d%I64d%I64d%I64d%I64d",&r,&x1,&y1,&x2,&y2) ;
    x1-=x2 , y1-=y2 ;
    for(int i=0;;i++)
        if(x1*x1+y1*y1 <= 2*r*i*2*r*i) { printf("%d\n",i) ; return 0 ; }
}
