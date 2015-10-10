#include<bits/stdc++.h>
using namespace std;

int a[20],cnt ;
main()
{
    int n ; scanf("%d",&n) ;
    while(n) a[cnt++]=(n%10==4 ? 0 : 1) , n/=10 ;
    int ans=0 ;
    for(int i=cnt-1;i>=0;i--) ans=ans*2+a[i] ;
    ans+=(1<<cnt)-1 ;
    printf("%d\n",ans) ;
}
