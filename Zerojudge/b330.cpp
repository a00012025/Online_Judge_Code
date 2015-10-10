#include<bits/stdc++.h>
using namespace std;

int cal(int n,int t)
{
    int ret=0 ;
    while(n)
    {
        if(n%10==t) ret++ ;
        n/=10 ;
    }
    return ret ;
}

main()
{
    int n,x ; scanf("%d%d",&n,&x) ;
    int ans=0;
    for(int i=1;i<=n;i++) ans+=cal(i,x) ;
    printf("%d\n",ans) ;
}
