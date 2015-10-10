#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;;i++)
    {
        n-- ; if(i%m==0) n++ ;
        if(!n){printf("%d\n",i) ; return 0 ;}
    }
}
