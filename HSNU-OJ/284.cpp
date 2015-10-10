#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=1000000+10 ;
LL a[maxn] ;
main()
{
    int n,x=0,y=0 ; char k ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        k=getchar() ;
        while(k!='1' && k!='2') k=getchar() ;
        (k=='1'?x:y)++ ;
    }
    a[0]=a[1]=1 ;
    for(int i=2;i<=x;i++) a[i]=(a[i-1]+(i-1)*a[i-2])%MOD ;
    LL ans=a[x] ;
    for(int i=x+1;i<=n;i++) ans=ans*i%MOD ;
    printf("%lld\n",ans) ;
}
