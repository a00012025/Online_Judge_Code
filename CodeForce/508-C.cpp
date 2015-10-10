#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
int a[maxn] ;
main()
{
    int m,t,r ; scanf("%d%d%d",&m,&t,&r) ;
    if(r>t){printf("-1\n") ; return 0 ;}
    int ans=0 ;
    for(int i=1;i<=m;i++)
    {
        int x,num=0 ; scanf("%d",&x) ; x+=500 ;
        for(int j=x-t+1;j<=x;j++) num+=a[j] ;
        if(num>=r) continue ;
        for(int j=x;num<r;j--) if(!a[j]) a[j]=1 , num++ , ans++ ;
    }
    printf("%d\n",ans) ;
}
