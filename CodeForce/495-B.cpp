#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b ; scanf("%d%d",&a,&b) ;
    if(a==b){printf("infinity\n") ; return 0 ;}
    a-=b ;
    int ans=0 ;
    for(int i=1;i*i<=a;i++) if(a%i==0)
    {
        if(i>b) ans++ ;
        if(i*i==a) continue ;
        if(a/i>b) ans++ ;
    }
    printf("%d\n",ans) ;
}
