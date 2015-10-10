#include<bits/stdc++.h>
#define DB double
using namespace std;
main()
{
    int T,A,B ; DB p ;
    scanf("%d",&T) ;
    while(T--) scanf("%d%d%lf",&A,&B,&p) , printf("%.10f\n",(1-p)*B/p+2*p*A/(1-p)) ;
}
