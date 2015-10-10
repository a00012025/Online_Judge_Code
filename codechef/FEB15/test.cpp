#include<bits/stdc++.h>
using namespace std;

main()
{
    int n=31 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) printf("%3d",i^j) ;
        //for(int j=1;j<=n;j++) printf("%c",j>=i&&(((i^j)==i-j) || ((i^j)==j-i)) ? 'X' : ' ') ;
        printf("\n") ;
    }
}
