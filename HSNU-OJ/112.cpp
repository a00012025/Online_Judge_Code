#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct P{int ed,type;};
int n,m ;
vector<P> v[80001] ;
vector<int> dif ;
int zero,col[80001],num0,num1 ;

void dfs(int x)
{
    if(col[x]==0) num0++ ;
    else num1++ ;
    for(int i=0;i<v[x].size();i++) if(col[v[x][i].ed]==-1)
    {
        if(v[x][i].type==1) col[v[x][i].ed]=(!col[x]) ;
        else col[v[x][i].ed]=col[x] ;
        dfs(v[x][i].ed) ;
    }
}

bool dp[80001] ;
void DP()
{
    memset(dp,0,sizeof(dp)) ;
    dp[0]=1 ;
    for(int i=0;i<dif.size();i++) for(int j=n;j>=dif[i];j--)
        dp[j] |= dp[j-dif[i]] ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) v[i].clear() ;
        int sub=0 ;
        while(m--)
        {
            int x,y,t ; scanf("%d%d%d",&x,&y,&t) ;
            v[x].push_back((P){y,t}) ;
            v[y].push_back((P){x,t}) ;
            if(t==1) sub++ ;
        }
        memset(col,-1,sizeof(col)) ;
        dif.clear() ; zero=0 ;
        for(int i=0;i<n;i++) if(col[i]==-1)
        {
            if(v[i].empty()) {zero++ ; continue ; }
            num0=num1=0 ;
            col[i]=1 ; dfs(i) ;
            if(num0!=num1) dif.push_back(abs(num0-num1)) ;
        }

        if(!dif.empty()) DP() ;
        int sum=0 ; for(int i=0;i<dif.size();i++) sum+=dif[i] ;
        if(!sum)
        {
            LL x=n/2 , y=n-x ;
            printf("%lld\n",x*y-sub) ;
            continue ;
        }

        int i=(sum+1)/2 ;
        for(;dp[i]==0;i++) ;
        int d=2*i-sum ; LL ans ;
        if(zero>=d) { LL x=n/2 , y=n-x ; ans=x*y ; }
        else { d-=zero ; LL x= (n-d)/2 , y=n-x ; ans=x*y ; }
        printf("%lld\n",ans-sub) ;
    }
}
