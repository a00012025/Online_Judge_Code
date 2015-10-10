#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    LL x1,y1,x2,y2 ;
    scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2) ;
    int ans=0,n ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        LL a,b,c ; scanf("%I64d%I64d%I64d",&a,&b,&c) ;
        LL x=a*x1+b*y1+c ;
        LL y=a*x2+b*y2+c ;
        if((x<0 && y>0) || (x>0 && y<0)) ans++ ;
    }
    printf("%d\n",ans) ;
}
