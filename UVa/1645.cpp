#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int dp[1005][1005],ans[1005] ;
void pre_cal()
{
    memset(dp,0,sizeof(dp)) ;
    vector<int> v ;
    for(int i=1;i<=1000;i++)
    {
        if(i==1) {for(int j=1;j<=1000;j++) dp[i][j]=1 ; continue ;}
        v.clear() ;
        for(int j=1;j<=i;j++) if((i%j)==0) v.push_back(j) ;
        for(int j=i+1;j<=1000;j++) for(int x=0;x<v.size();x++)
            dp[i][j]+=dp[v[x]][j-i] , dp[i][j]%=MOD ;
    }
    memset(ans,0,sizeof(ans)) ;
    for(int i=1;i<=1000;i++) for(int j=i;j<=1000;j++)
        ans[j]+=dp[i][j] , ans[j]%=MOD ;
}

main()
{
    pre_cal() ;
    int n,tc=0 ;
    while(scanf("%d",&n)!=EOF) printf("Case %d: %d\n",++tc,ans[n]) ;
}
