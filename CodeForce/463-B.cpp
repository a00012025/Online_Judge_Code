#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,ans=0 ; scanf("%d",&n) ;
    while(n--){int x ; scanf("%d",&x) ; ans=max(ans,x) ;}
    printf("%d\n",ans) ;
}
