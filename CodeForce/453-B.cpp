#include<bits/stdc++.h>
#define INF 100000000
#define ABS(x) ((x)>0 ? (x) : (-(x)))
using namespace std;
const int maxn=100+10 ;

int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59} ;
int di[100],dp[maxn][1<<17],last[maxn][1<<17] ;
int n ;
vector<int> trans[1<<17] ;
void print_ans(int x,int S)
{
    if(!x) return ;
    int y=last[x][S] ;
    print_ans(x-1,S^di[y]) ;
    printf("%d%c",y,x==n?'\n':' ') ;
}

main()
{
    for(int i=1;i<=60;i++)
        for(int j=0,x=i;j<17;j++) if(x%p[j]==0)
    {
        di[i]^=(1<<j) ;
        while(x%p[j]==0) x/=p[j] ;
    }

    for(int i=0;i<(1<<17);i++) for(int j=1;j<=60;j++)
        if(!(i&di[j])) trans[i].push_back(j) ;

    scanf("%d",&n) ;
    fill(dp[0],dp[maxn-1]+(1<<17),INF) ;
    dp[0][0]=0 ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        for(int j=0;j<(1<<17);j++) if(dp[i-1][j]!=INF)
            for(auto k : trans[j]) if(dp[i-1][j]+ABS(k-x) < dp[i][j^di[k]])
            dp[i][j^di[k]]=dp[i-1][j]+ABS(k-x) ,
            last[i][j^di[k]]=k ;
    }
    print_ans(n,min_element(dp[n],dp[n]+(1<<17))-dp[n]) ;
}
