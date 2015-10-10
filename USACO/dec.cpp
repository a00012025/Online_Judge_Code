#include<bits/stdc++.h>
using namespace std;
const int maxn=20+1,maxc=40000+10 ;

struct P
{
    int val,add;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
};

vector<P> v[maxn] ;
int earn[maxn][maxc] ;
void cal_earn()
{
    for(int i=1;i<maxn;i++)
    {
        for(int j=0;j<maxc;j++) earn[i][j]=j ;
        sort(v[i].begin(),v[i].end()) ;
        for(auto j : v[i])
            for(int k=maxc-1;earn[i][k]>=j.val;k--)
            earn[i][k]+=j.add ;
    }
}

int val[maxn][maxn] ;
int dp[1<<20] ;
vector<int> bit[maxn] ;

main()
{
    freopen("dec.in","r",stdin) ;
    freopen("dec.out","w",stdout) ;
    int n,B ; scanf("%d%d",&n,&B) ;
    while(B--)
    {
        int x,val,add ; scanf("%d%d%d",&x,&val,&add) ;
        v[x].push_back((P){val,add}) ;
    }
    for(int i=0;i<n;i++) for(int j=1;j<=n;j++)
        scanf("%d",&val[i][j]) ;

    cal_earn() ;

    for(int i=1;i<(1<<n);i++) bit[__builtin_popcount(i)].push_back(i) ;

    for(int i=1;i<=n;i++) for(auto j : bit[i])
        for(int k=0;k<n;k++) if(j&(1<<k))
            dp[j]=max(dp[j],earn[i][dp[j^(1<<k)]+val[k][i]]) ;
    printf("%d\n",dp[(1<<n)-1]) ;
}
