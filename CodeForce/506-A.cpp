#include<bits/stdc++.h>
using namespace std;

int d[31000][701] ;
int val[31000],dis ;

int dp(int i,int j)
{
    if(i>30000) return 0 ;
    if(d[i][j]!=-1) return d[i][j] ;
    int &ans=d[i][j] ; ans=0 ;
    int j2=j-350+dis ;
    if(j2>1) ans=max(ans,dp(i+j2-1,j-1)) ;
    ans=max(ans,dp(i+j2,j)) ;
    ans=max(ans,dp(i+j2+1,j+1)) ;
    ans+=val[i] ;
    return ans ;
}

main()
{
    int n ; scanf("%d%d",&n,&dis) ;
    memset(val,0,sizeof(val)) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        val[x]++ ;
    }
    memset(d,-1,sizeof(d)) ;
    printf("%d\n",dp(dis,350)) ;
}
