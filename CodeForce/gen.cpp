#include<bits/stdc++.h>
using namespace std;
const int maxn=100000 ;

main()
{
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    printf("%d\n",maxn) ;
    for(int i=1;i<=maxn;i++) printf("%d ",i==1?100000:rand()%1000) ;
    printf("\n") ;
}
