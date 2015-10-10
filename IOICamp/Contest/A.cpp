#include<bits/stdc++.h>
using namespace std;

int d[41][26][801] ;

int dp(int n,int k,int s)
{
    if(d[n][k][s]!=-1) return d[n][k][s] ;
    if(k==1) return s<=n ? 1 : 0 ;
    if(k>n || k*(k+1)/2 > s) return d[n][k][s]=0 ;
    if( (2*n-k+1)*k/2 < s ) return d[n][k][s]=0 ;

    int &ans=d[n][k][s] ; ans=0 ;
    for(int i=1; s>=((2*i+k-1)*k/2) ;i++) ans+=dp(n-i,k-1,s-k*i) ;
    return ans ;
}

main()
{
    int T ; scanf("%d",&T) ;
    memset(d,-1,sizeof(d)) ;
    while(T--)
    {
        int n,k,s ; scanf("%d%d%d",&n,&k,&s) ;
        printf("%d\n",dp(n,k,s)) ;
    }
}
