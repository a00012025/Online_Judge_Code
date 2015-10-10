#include<bits/stdc++.h>
using namespace std;
const int maxn=50000 + 10 ;
int phi[maxn] , sum[maxn] ;
void phi_table()
{
    memset(phi,0,sizeof(phi)) ;
    for(int i=2;i<maxn;i++) if(!phi[i])
        for(int j=i;j<maxn;j+=i)
    {
        if(!phi[j]) phi[j]=j ;
        phi[j] = (phi[j]/i)*(i-1) ;
    }
    sum[0]=0 ;
    for(int i=1;i<maxn;i++) sum[i]=sum[i-1]+phi[i] ;
}

main()
{
    phi_table() ;
    int n ;
    while(scanf("%d",&n)==1 && n) printf("%d\n",2*sum[n]+1) ;
}
