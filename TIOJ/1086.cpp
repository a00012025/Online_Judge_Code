#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL frac[20],C[20][20] ;

main()
{
    frac[0]=1LL ;
    for(int i=1;i<20;i++) frac[i]=frac[i-1]*i ;
    for(int i=1;i<20;i++) for(int j=0;j<=i;j++)
        C[i][j]= (j==0||j==i) ? 1 : C[i-1][j]+C[i-1][j-1] ;
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        LL ans=0LL ;
        for(int i=n-2;i>=0;i--)
        {
            LL val=C[n][i]*frac[i] ;
            if((n-i)%2) ans-=val ;
            else ans+=val ;
        }
        printf("%lld\n",ans) ;
    }
}
