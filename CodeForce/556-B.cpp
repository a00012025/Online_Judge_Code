#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,val,ok=1 ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        int x ; scanf("%d",&x) ;
        if(!i) val=n-x ;
        else if(i%2 && (x-val+n)%n!=i) ok=0 ;
        else if(!(i%2) && (x+val)%n!=i) ok=0 ;
    }
    printf("%s\n",ok?"Yes":"No") ;
}
