#include<bits/stdc++.h>
#include"lib1416.h"
const int maxn=3000000+10 ;

int d[2][2][maxn] ;

int dp(int x,int y,int n)
{
    if(n==0) return (x%2)==1 ;
    if(d[x%2][y%2][n]!=-1) return d[x%2][y%2][n] ;
    int &ans=d[x%2][y%2][n] ;
    if(!dp(y,x+1,n-1)) return ans=1 ;
    if(n>=2 && !dp(y,x+2,n-2)) return ans=1 ;
    return ans=0 ;
}

main()
{
    memset(d,-1,sizeof(d)) ;
    int n=Initialize() , x=0 , y=0 ;
    for(int i=0;i<=n;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
        dp(j,k,i) ;
    while(n)
    {
        int num ;
        if(n>=2 && !dp(y,x+2,n-2)) num=Take_Stone(2) , n-=2 , x+=2 ;
        else num=Take_Stone(1) , n-=1 , x++ ;
        y+=num ; n-=num ;
    }
}
