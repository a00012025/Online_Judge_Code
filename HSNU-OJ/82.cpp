#include<bits/stdc++.h>
using namespace std;

vector<int> v[11],pri[11] ;
int dp[2001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        int x,tp ; scanf("%d%d",&x,&tp) ;
        v[tp].push_back(x) ;
    }
    for(int i=1;i<=10;i++) sort(v[i].begin(),v[i].end(),greater<int>()) ;
    for(int i=1;i<=10;i++)
    {
        pri[i].push_back(0) ; int last=0 ;
        for(int j=0;j<v[i].size();j++) pri[i].push_back(last+v[i][j]+2*j) , last+=v[i][j]+2*j ;
        //for(int j=0;j<pri[i].size();j++)printf("%d,",pri[i][j]) ; printf("\n") ;
    }

    memset(dp,0,sizeof(dp)) ;
    for(int i=1;i<=10;i++) for(int j=m;j>=0;j--)
        for(int k=0;k<pri[i].size() && k<=j;k++)
            dp[j]=max(dp[j],dp[j-k]+pri[i][k]) ;
    printf("%d\n",dp[m]) ;
}
