#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=60000 ;
int phi[maxn] ;

void phi_table()
{
    memset(phi,0,sizeof(phi)) ;
    phi[1]=1 ;
    for(int i=2;i<maxn;i++) if(!phi[i])
    {
        for(int j=i;j<maxn;j+=i)
        {
            if(!phi[j]) phi[j]=j ;
            phi[j]=(phi[j]/i)*(i-1) ;
        }
    }
}

int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    phi_table() ;
    while(T--)
    {
        int a,b,d ; scanf("%d%d%d",&a,&b,&d) ;
        a/=d ; b/=d ;
        if(a>b) swap(a,b) ;
        LL ans=0LL ;
        for(int i=1;i<=a;i++)
        {
            int q=b/i ;
            ans+=(LL)phi[i]*q ;
            for(int j=i*q+1;j<=b;j++) if(gcd(i,j)==1) ans++ ;
        }
        printf("%lld\n",ans) ;
    }
}
