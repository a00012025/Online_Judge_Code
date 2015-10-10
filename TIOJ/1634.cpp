#include<bits/stdc++.h>
using namespace std;
main()
{
    int n ; scanf("%d",&n) ;
    int s=0 ;
    for(int i=0;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        if(s>=((1<<i)-1)) s+=x*(1<<i) ;
    }
    printf("%d\n",s+1) ;
}
