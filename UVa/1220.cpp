#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> v[211] ;
map<string,int> mp ;
int fa[211],cnt ;
int dp[211][2],f[211][2] ;

int id(string s)
{
    if(mp.count(s)) return mp[s] ;
    cnt++ ; mp[s]=cnt ; return cnt ;
}

void dfs(int n)
{
    for(int i=0;i<v[n].size();i++) dfs(v[n][i]) ;
    if(n==0) return ;

    dp[fa[n]][1]+=max(dp[n][0],dp[n][1]) ;
    dp[fa[n]][0]+=dp[n][1] ;

    if(dp[n][0]==dp[n][1]) f[fa[n]][1]=0 ;
    if(dp[n][0]>dp[n][1] && f[n][0]==0) f[fa[n]][1]=0 ;
    if(dp[n][0]<dp[n][1] && f[n][1]==0) f[fa[n]][1]=0 ;
    if(f[n][1]==0) f[fa[n]][0]=0 ;
    //printf("dp[%d][0]=%d , dp[%d][1]=%d\n",n,dp[n][0],n,dp[n][1]) ;
}

main()
{
    int n;
    char s[2000],t[2000] ;
    string st1,st2 ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<=210;i++)
            {v[i].clear() ; dp[i][0]=f[i][0]=f[i][1]=1 ; dp[i][1]=0 ;}
        mp.clear() ; scanf("%s",s) ;
        st1.clear() ; st1.append(s,s+strlen(s)) ;

        v[0].push_back(1) ; fa[1]=0 ; fa[0]=0 ;
        mp[st1]=1 ; cnt=1 ;
        for(int i=1;i<n;i++)
        {
            scanf("%s%s",s,t) ;
            st1.clear() ; st2.clear() ;
            st1.append(s,s+strlen(s)) ;
            st2.append(t,t+strlen(t)) ;
            int a=id(st1) , b=id(st2) ;
            fa[a]=b ; v[b].push_back(a) ;
        }
        dfs(0) ;
        if(f[0][1]) printf("%d Yes\n",dp[0][1]) ;
        else printf("%d No\n",dp[0][1]) ;
    }
}
