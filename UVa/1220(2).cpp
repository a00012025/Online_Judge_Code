#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> v[211] ;
map<string,int> mp ;
int cnt ;
int d[211][2],f[211][2] ;

int id(string s)
{
    if(mp.count(s)) return mp[s] ;
    cnt++ ; mp[s]=cnt ; return cnt ;
}

int dp(int n,int k)
{
    d[n][k]=k ; f[n][k]=1 ;
    for(int i=0;i<v[n].size();i++)
    {
        if(k==1)
        {
            d[n][k]+=dp(v[n][i],0) ;
            if(f[v[n][i]][0]==0) f[n][k]=0 ;
        }
        else
        {
            d[n][k]+=max(dp(v[n][i],0),dp(v[n][i],1)) ;
            if(d[v[n][i]][0]==d[v[n][i]][1]) f[n][k]=0 ;
            if(d[v[n][i]][0]<d[v[n][i]][1] && !d[v[n][i]][1]) f[n][k]=0 ;
            if(d[v[n][i]][0]>d[v[n][i]][1] && !d[v[n][i]][0]) f[n][k]=0 ;
        }
    }
    return d[n][k] ;
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
            {v[i].clear() ; f[i][0]=f[i][1]=1 ; d[i][0]=d[i][1]=0 ;}
        mp.clear() ; scanf("%s",s) ;
        st1.clear() ; st1.append(s,s+strlen(s)) ;

        mp[st1]=0 ; cnt=0 ;
        for(int i=1;i<n;i++)
        {
            scanf("%s%s",s,t) ;
            st1.clear() ; st2.clear() ;
            st1.append(s,s+strlen(s)) ;
            st2.append(t,t+strlen(t)) ;
            v[id(st2)].push_back(id(st1)) ;
        }
        printf("%d ",max(dp(0,0),dp(0,1))) ;
        bool uni=1 ;
        if(d[0][0]==d[0][1]) uni=0 ;
        if(d[0][0]>d[0][1] && !f[0][0]) uni=0 ;
        if(d[0][0]<d[0][1] && !f[0][1]) uni=0 ;
        if(uni) printf("Yes\n") ;
        else printf("No\n") ;
    }
}

