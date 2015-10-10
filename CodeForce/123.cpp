#include<bits/stdc++.h>
using namespace std;

main()
{
    //freopen("1.txt","w",stdout) ;
    int n=(1<<16) ;
    printf("%d\n",n) ;
    printf("2 %d\n",1^(n-1)) ;
    for(int i=1;i<n-2;i++) printf("2 %d\n",(i-1)^(i+1)) ;
    printf("1 %d\n",n-3) ;
    printf("1 %d\n",0) ;
}
