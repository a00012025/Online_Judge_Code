#include<bits/stdc++.h>
using namespace std;
main()
{
    int k,n,w ; scanf("%d%d%d",&k,&n,&w) ;
    int m=(w*(w+1)/2)*k ;
    printf("%d\n",max(0,m-n)) ;
}
