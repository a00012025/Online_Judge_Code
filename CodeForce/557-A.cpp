#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m1,M1,m2,M2,m3,M3 ;
    scanf("%d%d%d%d%d%d%d",&n,&m1,&M1,&m2,&M2,&m3,&M3) ;
    int x=min(M1,n-m2-m3) , y=min(M2,n-x-m3) ;
    printf("%d %d %d\n",x,y,n-x-y) ;
}
