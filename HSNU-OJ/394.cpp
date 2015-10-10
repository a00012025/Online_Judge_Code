#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    int val=0 , type ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        int x ; scanf("%d",&x) ;
        if(x==-1) { type=(i+j)%2 ; continue ; }
        if((i+j)%2) val+=x ;
        else val-=x ;
    }
    printf("%d\n",type==1 ? -val : val) ;
}
