#include<bits/stdc++.h>
using namespace std;

int d[21][11][160] ;
int dp(int n,int k,int s)
{
    if(d[n][k][s]!=-1) return d[n][k][s] ;
    if(!k && !s) return 1 ;
    if(!k || k>n) return 0 ;
    int &ans=d[n][k][s] ; ans=0 ;
    for(int i=min(n,s);i>=1;i--) ans+=dp(i-1,k-1,s-i) ;
    return ans ;
}

main()
{
    memset(d,-1,sizeof(d)) ;
    int n,k,s ;
    while(scanf("%d%d%d",&n,&k,&s)==3 && n+k+s) printf("%d\n",dp(n,k,s)) ;
}
