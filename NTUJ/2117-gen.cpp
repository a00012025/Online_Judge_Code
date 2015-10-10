#include<bits/stdc++.h>
using namespace std;
main()
{
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    int T=10000 ; printf("%d\n",T) ;
    while(T--) for(int i=0;i<16;i++) printf("%d%c",rand()%13+1,i==15?'\n':' ') ;
}
